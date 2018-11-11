#include "../include/Parser.h"
#include "../include/Restaurant.h"
#include "../include/Action.h"
#include "regex"

void Parser::parse(std::string firstWord, std::string fullLine, Restaurant &restaurant) {
    regex openReg("open\\s*(\\d+)\\s*(.*)");
    regex orderReg("order\\s*(\\d+)");
    regex moveReg("move\\s*(\\d+)\\s*(\\d+)\\s*(\\d+)");
    regex closeReg("close\\s*(\\d+)");
    regex closeAllReg("closeall\\s*");
    regex printMenuReg("menu\\s*");
    regex printTableStatusReg("status\\s*(\\d+)");
    regex printActionsLogReg("log");
    regex backupRestaurantReg("backup");
    regex restoreReg("restore");

    map<string, regex> regexDict ={
            {"open", openReg},
            {"order", orderReg},
            {"move", moveReg},
            {"close",closeReg},
            {"closeall",closeAllReg},
            {"menu",printMenuReg},
            {"status",printTableStatusReg},
            {"log",printActionsLogReg},
            {"backup",backupRestaurantReg},
            {"restore",restoreReg}
    };
    std::smatch smatch1;
    if(regex_search(fullLine, smatch1, regexDict[firstWord])){
        cout<< smatch1[0]<<endl;
//        cout<< smatch1[1]<<endl;
    }
    if(!smatch1.empty() ){
        cout<<"hi"<<endl;

        BaseAction* customAction = nullptr;
        if(firstWord == "open"){

            string stringOfMatch= smatch1[2].str();
            vector<Customer*> customerList;
//            customerList = parseOpen(stringOfMatch);
//            OpenTable(stoi(smatch[1].str()), customerList);
        }

        if(firstWord == "order"){
            int tableId = stoi(smatch1[1].str());
            customAction = new Order(tableId);
        }
        if(firstWord == "move"){
            int originTableId = stoi(smatch1[1]);
            int destinationTableId = stoi(smatch1[2]);
            int customerId = stoi(smatch1[3]);
            customAction = new MoveCustomer(originTableId, destinationTableId, customerId);
        }
        if(firstWord == "close"){
            int tableId = stoi(smatch1[1]);
            customAction= new Close(tableId);
        }
        if(firstWord == "closeall"){
            customAction = new CloseAll();
        }
        if(firstWord == "menu"){
            customAction = new PrintMenu();
        }
        if(firstWord == "status"){
            int tableId = stoi(smatch1[1]);
            customAction = new PrintTableStatus(tableId);
        }
//        if(firstWord == "log"){
//            customAction = new PrintActionsLog();
//        }
//        if(firstWord == "backuo"){
//            customAction = new BackupRestaurant();
//        }
//
//        if(firstWord == "restore"){
//            customAction = new RestoreResturant();
//        }
        runAction(customAction, restaurant);
    }

    string ohad = "ohad";



}

vector<Customer*> Parser::parseOpen(string match) {

    istringstream is1 (match);
    string customer;
    vector <Customer*> customerList;
    int i=0;
    while(getline(is1, customer , ' ')) {
        istringstream is2(customer);
        string name;
        Customer *customer1 = nullptr;
        string strategy;
        getline(is2, name, ',');
        getline(is2,strategy, ',');
        if (strategy == "ALC") {
            customer1 = new AlchoholicCustomer(name,i);
        } else if (strategy == "CHP") {
            customer1 = new CheapCustomer(name, i);
        } else if (strategy == "SPC") {
            customer1 = new SpicyCustomer(name, i);
        } else if (strategy == "VEG") {
            customer1 = new VegetarianCustomer(name, i);
        }
        if(customer1!= nullptr){
            customerList.push_back(customer1);
            i++;
        }
    }
    return customerList;
}

/**
 * This method gets an action as an argument, runs it, adds the action into the actionsLog of the restaurant.
 * @param action
 * @param restaurant
 */
void Parser::runAction(BaseAction *action, Restaurant &restaurant) {
    action->act(restaurant);
    vector<BaseAction*> actionsLog= restaurant.getActionsLog();
    actionsLog.push_back(action);
    cout << "<--------------started to run the action "+action->toString()+" --------------- > ";
}
