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

Restaurant::Restaurant(const std::string &configFilePath) {
    vector<string> arguments;
    arguments = Restaurant::extractArgumentsFromConfig(configFilePath);
    if (arguments.size() == 3) {
        createTablesFromArguments(arguments);
    } else {
        cout << "arguments size different from 3 " << endl;
    }
}

std::vector<Dish> &Restaurant::getMenu() {}

bool Restaurant::createTablesFromArguments(vector<string> argument) {
    int numberOfTables = stoi(argument[0]);
    vector<Table *> tables(numberOfTables);
//    regex rgx("(\\d+)");
//    smatch matches;
//    regex_search(argument[1], matches, rgx);
//    for (int i = 0; i <matches.size() ; ++i) {
//        int ohad  = stoi(matches[i].str());
//        cout << matches[i].str() << endl;
//    }
//    string ohad1 = "ohad";
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


