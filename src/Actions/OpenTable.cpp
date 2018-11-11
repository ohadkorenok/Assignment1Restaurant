//
// Created by nitzan on 10/11/18.
//
#include "../../include/Action.h"
#include "../../include/Table.h"
#include "../../include/Restaurant.h"
using namespace std;

OpenTable::OpenTable(int id, std::vector<Customer *> &customersList):BaseAction::BaseAction(), tableId(id),customers(customersList) {};
void OpenTable::act(Restaurant &restaurant) {
    Table* t1=restaurant.getTable(tableId);
    if(t1 == nullptr | t1->isOpen()){
        string err="Table does not exist or is already open";
        BaseAction::error(err);
    }
        else {
            t1->openTable();
        for (std::vector<Customer *>::const_iterator it = customers.begin(); it != customers.end(); ++it) {
            t1->addCustomer(*it);
        }
        complete();
    }
}
string OpenTable::toString() const {
    string toRet="open "+to_string(tableId);

}
