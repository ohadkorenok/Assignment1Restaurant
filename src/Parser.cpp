#include "../include/Parser.h"
#include "../include/Restaurant.h"
#include "../include/Action.h"
#include "regex"

BaseAction *Parser::parse(std::string firstWord, std::string fullLine, Restaurant &restaurant) {
    BaseAction *action = nullptr;
    map<string, regex> regexDict = {
            {"open",     regex("open\\s*(\\d+)\\s*(.*)")},
            {"order",    regex("order\\s*(\\d+)")},
            {"move",     regex("move\\s*(\\d+)\\s*(\\d+)\\s*(\\d+)")},
            {"close",    regex("close\\s*(\\d+)")},
            {"closeall", regex("closeall\\s*")},
//            {"menu",     regex("menu\\s*")},
            {"menu",     regex("menu")},
            {"status",   regex("status\\s*(\\d+)")},
            {"log",      regex("log")},
            {"backup",   regex("backup")},
            {"restore",  regex("restore")}};
    std::smatch smatch1;
    regex_search(fullLine, smatch1, regexDict[firstWord]);
    if (!smatch1.empty()) {

        BaseAction *customAction = nullptr;
        if (firstWord == "open") {
            string stringOfMatch = smatch1[2].str();
            vector<Customer *> customerList;
            customerList = parseOpen(stringOfMatch, restaurant);
            customAction = new OpenTable(stoi(smatch1[1].str()), customerList);
        }

        if (firstWord == "order") {
            int tableId = stoi(smatch1[1].str());
            customAction = new Order(tableId);
        }
        if (firstWord == "move") {
            int originTableId = stoi(smatch1[1]);
            int destinationTableId = stoi(smatch1[2]);
            int customerId = stoi(smatch1[3]);
            customAction = new MoveCustomer(originTableId, destinationTableId, customerId);
        }
        if (firstWord == "close") {
            int tableId = stoi(smatch1[1]);
            customAction = new Close(tableId);
        }
        if (firstWord == "closeall") {
            customAction = new CloseAll();
        }
        if (firstWord == "menu") {
            customAction = new PrintMenu();
        }
        if (firstWord == "status") {
            int tableId = stoi(smatch1[1]);
            customAction = new PrintTableStatus(tableId);
        }
        if (firstWord == "log") {
            customAction = new PrintActionsLog();
        }
        if (firstWord == "backup") {
            customAction = new BackupRestaurant();
        }

        if (firstWord == "restore") {
            customAction = new RestoreResturant();
        }
        action = runAction(customAction, restaurant);
    }
    else{
        cout << "no match found!" << endl;
    }
    return action;


}

vector<Customer *> Parser::parseOpen(string match, Restaurant &restaurant) {

    istringstream is1(match);
    string customer;
    vector<Customer *> customerList;
    customerList.clear();
    int nextCustomerId = restaurant.getNextCustomerId();
    while (getline(is1, customer, ' ')) {
        istringstream is2(customer);
        string name;
        Customer *customer1 = nullptr;
        string strategy;
        getline(is2, name, ',');
        getline(is2, strategy, ',');
        std::transform(strategy.begin(), strategy.end(), strategy.begin(), ::toupper);
        if (strategy == "ALC") {
            customer1 = new AlchoholicCustomer(name, nextCustomerId);
        } else if (strategy == "CHP") {
            customer1 = new CheapCustomer(name, nextCustomerId);
        } else if (strategy == "SPC") {
            customer1 = new SpicyCustomer(name, nextCustomerId);
        } else if (strategy == "VEG") {
            customer1 = new VegetarianCustomer(name, nextCustomerId);
        }
        if (customer1 != nullptr) {
            customerList.push_back(customer1);
            nextCustomerId++;
        }
    }
    restaurant.setNextCustomerId(nextCustomerId);
    return customerList;
}

/**
 * This method gets an action as an argument, runs it, adds the action into the actionsLog of the restaurant.
 * @param action
 * @param restaurant
 */
BaseAction *Parser::runAction(BaseAction *action, Restaurant &restaurant) {
    action->act(restaurant);
    vector<BaseAction *> actionsLog = restaurant.getActionsLog();
    return action;
}
