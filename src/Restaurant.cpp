#include "../include/Restaurant.h"
#include <iostream>
#include <sstream>
#include <fstream>

const std::vector<BaseAction *> &Restaurant::getActionsLog() const {}

Restaurant::Restaurant() {}

Restaurant::Restaurant(const std::string &configFilePath) {
    std::ifstream myFile(configFilePath);
    std::string line;
    while(std::getline(myFile, line)){
        std::istringstream iss(line);
    }

}

std::vector<Dish> &Restaurant::getMenu() {}

int Restaurant::getNumOfTables() const {}

Table *Restaurant::getTable(int ind) {}

void Restaurant::start() {}