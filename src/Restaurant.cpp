#include "../include/Restaurant.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <regex>


using namespace std;

const std::vector<BaseAction *> &Restaurant::getActionsLog() const {
    return this->actionsLog;
}

/**
 * Copy constructor.
 * @param other
 */
Restaurant::Restaurant(const Restaurant &other) {
    fillMeUp(other.tables, other.menu, other.actionsLog, other.open);
}

/**
 * Move constructor
 * @param other
 */
Restaurant::Restaurant(Restaurant &&other) {
    if (this != &other) {
        stealFromOther(other.tables, other.menu, other.actionsLog, other.open);
    }
}

/**
 * Destructor.
 */
Restaurant::~Restaurant() {
    clear();
}


/**
 * Move assignment operator
 * @param other
 * @return
 */
Restaurant &Restaurant::operator=(Restaurant &&other) {
    if (this == &other) {
        return *this;
    }
    stealFromOther(other.tables, other.menu, other.actionsLog, other.open);
    return *this;
}

/**
 * Copy assignment operator
 * @param Restaurant
 * @return
 */
Restaurant &Restaurant::operator=(const Restaurant &Restaurant) {
    if (this == &Restaurant) {
        return *this;
    }

    for (int l = 0; l < this->tables.size(); ++l) {
        delete tables[l];
        tables[l] = nullptr;
    }
//    tables.clear();
    for (int m = 0; m < actionsLog.size(); ++m) {
        delete actionsLog[m];
        actionsLog[m] = nullptr;
    }

    fillMeUp(Restaurant.tables, Restaurant.menu, Restaurant.actionsLog, Restaurant.open);
    return *this;
}

vector<string> Restaurant::extractArgumentsFromConfig(const string &configFilePath) {
    std::vector<string> arguments(3);
    std::string line;
    std::string tableNumbers;
    std::ifstream myFile(configFilePath);
    int i = 0;
    if (myFile.is_open()) {
        while (std::getline(myFile, line) && i <= 2) {
            std::istringstream iss(line);
            while (line[0] == '#' || line == "\r" || line.empty() || line == "\n") {
                std::getline(myFile, line);
            }
            if (i == 2) {
                string text = line.substr(0, line.rfind('\r'));
                while (getline(myFile, line)) {
//                    getline(myFile, line);
                    text += "\n" + line;
                }
                arguments[i] = text;
                i++;
            } else {
                arguments[i] = line.substr(0, line.rfind('\r'));
                i++;
            }
        }

    }
    return arguments;
}

Restaurant::Restaurant() {}

/**
 *
 * @param configFilePath
 */
Restaurant::Restaurant(const std::string &configFilePath) {
    this->open = true;
    this->nextCustomerId = 0;
    std::string pathname = __BASE_FILE__;
    string const configurationFile = pathname.substr(0, pathname.size() - 19) + "/" + configFilePath;
    vector<string> arguments;
    arguments = Restaurant::extractArgumentsFromConfig(configurationFile);
    if (arguments.size() == 3) {
        createTablesFromArguments(arguments);
        buildMenuFromArguments(arguments[2]);
    } else {
        cout << "arguments size different from 3 " << endl;
    }
}

/**
 * This program builds the menu from the menuArgument. TODO:: return the desired flag , true or false
 * @param menuArgument
 * @return
 */
void Restaurant::buildMenuFromArguments(string menuArgument) {
    vector<Dish> menu;
    string token;
    string dishToken;
    vector<string> dishArgument(3);
    istringstream is(menuArgument);
    int j = 0;
    while (getline(is, token, '\n')) {
        cout << token << endl;
        istringstream tokenStream(token);
        int i = 0;
        while (getline(tokenStream, dishToken, ',') && i <= 2) {
            dishArgument[i] = dishToken;
            i++;
        }
        DishType dishType;
        if (dishArgument[1] == "ALC") {
            dishType = DishType::ALC;
        } else if (dishArgument[1] == "BVG") {
            dishType = DishType::BVG;
        } else if (dishArgument[1] == "SPC") {
            dishType = DishType::SPC;
        } else if (dishArgument[1] == "VEG") {
            dishType = DishType::VEG;
        } else cout << "problem with building the menu, there is no such dish " + dishArgument[1] << endl;
        string ohad = "ohad";
        if (dishType == DishType::ALC | dishType == DishType::VEG | DishType::SPC | DishType::BVG) {
            Dish dish = Dish(j, dishArgument[0], stoi(dishArgument[2]), dishType);
            this->menu.push_back(dish);
            j++;
        }
    }
}

std::vector<Dish> &Restaurant::getMenu() {
    return this->menu;
}

/**
 * Create the tables from the arguments according to the config. (number of tables and tables capacity).
 * @param vector<string> argument
 * @return
 */
bool Restaurant::createTablesFromArguments(vector<string> argument) {
    int numberOfTables = stoi(argument[0]);
    vector<Table *> tables(numberOfTables);
    string token;
    int i = 0;
    istringstream is(argument[1]);
    while (getline(is, token, ',') && i < numberOfTables) {
        tables[i] = new Table(stoi(token));
        i++;
    }
    this->tables = tables;

    return true;
}

int Restaurant::getNumOfTables() const {
    return this->tables.size();
}

Table *Restaurant::getTable(int ind) {
    return this->tables[ind];
}

void Restaurant::start() {
    cout << "restaurant is now open! " << endl;
    string line;
    while (true) {
        getline(cin, line);
        string firstWord = line.substr(0, line.find(" "));
        BaseAction *action = Parser::parse(firstWord, line, *this);
        actionsLog.push_back(action);
    }
}

void Restaurant::closeRestaurant() {
    this->open = false;
}


void Restaurant::clear() {
    for (int i = 0; i < actionsLog.size(); ++i) {
        delete actionsLog[i];
        actionsLog[i] = nullptr;
    }
    for (int j = 0; j < tables.size(); ++j) {
        delete tables[j];
        tables[j] = nullptr;
    }
    tables.clear();
    actionsLog.clear();
}

/**
 * Helper method.
 * @param otherTables
 * @param otherMenu
 * @param otherActionsLog
 * @param otherOpen
 */
void Restaurant::fillMeUp(vector<Table *> otherTables, vector<Dish> otherMenu, vector<BaseAction *> otherActionsLog,
                          bool otherOpen) {
    for (int i = 0; i < otherTables.size(); ++i) {
        tables.push_back(new Table(*otherTables[i]));
    }
    for (int j = 0; j < otherActionsLog.size(); ++j) {
//        this->actionsLog[j] = otherActionsLog[j]->clone();
        BaseAction* action = otherActionsLog[j]->clone();
        actionsLog.push_back(action);

        string ohad = " ohad";
    }
    menu.clear();
    for (int k = 0; k < otherMenu.size(); ++k) {
        menu.push_back(otherMenu[k]);
    }
    open = otherOpen;
}

void Restaurant::stealFromOther(vector<Table *> otherTables, vector<Dish> otherMenu,
                                vector<BaseAction *> otherActionsLog, bool otherOpen) {

    for (int i = 0; i < otherTables.size(); ++i) {
        Table *temp = tables[i];
        this->tables[i] = otherTables[i];
        otherTables[i] = nullptr;
        delete temp;
    }

    menu.clear();
    for (int j = 0; j < otherMenu.size(); ++j) {
        menu.push_back(otherMenu[j]);
    }
    otherMenu.clear();

    for (int k = 0; k < otherActionsLog.size(); ++k) {
        BaseAction *temp;
        temp = actionsLog[k];
        actionsLog[k] = otherActionsLog[k];
        otherActionsLog[k] = nullptr;
        delete temp;
    }
    open = otherOpen;
}

int Restaurant::getNextCustomerId() {
    return nextCustomerId;
}

void Restaurant::setNextCustomerId(int newId) { nextCustomerId = newId; }


