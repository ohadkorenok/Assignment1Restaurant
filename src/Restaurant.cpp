#include "../include/Restaurant.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <regex>


using namespace std;

const std::vector<BaseAction *> &Restaurant::getActionsLog() const {}

vector<string> Restaurant::extractArgumentsFromConfig(const string &configFilePath) {
    std::vector<string> arguments(3);
    std::string line;
    std::string tableNumbers;
    std::ifstream myFile(configFilePath);
    int i = 0;
    if (myFile.is_open()) {
        while (std::getline(myFile, line) && i <= 2) {
            std::istringstream iss(line);
            while (line[0] == '#' || line == "\r") {
                std::getline(myFile, line);
            }
            if (i == 2) {
                string text = line.substr(0, line.rfind('\r'));
                while (getline(myFile, line)) {
                    getline(myFile, line);
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
    std::string pathname = __BASE_FILE__;
    string const configurationFile = pathname.substr(0,pathname.size() - 19)+"/"+configFilePath;
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
bool Restaurant::buildMenuFromArguments(string menuArgument) {
    vector<Dish> menu;
    string token;
    string dishToken;
    vector<string> dishArgument(3);
    istringstream is(menuArgument);
    int j =1;
    while(getline(is, token, '\n')){
        cout <<token << endl;
        istringstream tokenStream(token);
        int i =0;
        while(getline(tokenStream, dishToken, ',') && i<=2) {
            dishArgument[i] = dishToken;
            i++;
        }
        map<string, DishType> dishTypes = {
                {"ALC",DishType::ALC},
                {"BVG",DishType ::BVG},
                {"SPC",DishType ::SPC},
                {"VEG",DishType ::VEG}

        };
        DishType dishType;
        if(dishArgument[1] == "ALC")
            dishType = DishType ::ALC;
        if(dishArgument[1]== " BVG")
            dishType = DishType ::BVG;
        if(dishArgument[1] == "SPC")
            dishType = DishType ::SPC;
        if(dishArgument[1] == "VEG")
            dishType = DishType ::VEG;
        if(dishType){
            Dish dish = Dish(j, dishArgument[0], stoi(dishArgument[2]), dishType);
            this->menu.push_back(dish);
        }
    }
    string ohad = "ohad";

    return true;
}

std::vector<Dish> &Restaurant::getMenu() {}

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

int Restaurant::getNumOfTables() const {}

Table *Restaurant::getTable(int ind) {}

void Restaurant::start() {}
void Restaurant::closeRestaurant() { open=false; }


