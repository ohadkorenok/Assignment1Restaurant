#include "../include/Restaurant.h"

const std::vector<BaseAction *> &Restaurant::getActionsLog() const {}

Restaurant::Restaurant() {}

Restaurant::Restaurant(const std::string &configFilePath) {}

std::vector<Dish> &Restaurant::getMenu() {}

int Restaurant::getNumOfTables() const {}

Table *Restaurant::getTable(int ind) {}

void Restaurant::start() {}