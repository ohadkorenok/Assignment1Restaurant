//
// Created by nitzan on 10/11/18.
//
#include "../../include/Action.h"
#include "../../include/Table.h"
#include "../../include/Restaurant.h"
#include <vector>
#include <string>

using namespace std;

MoveCustomer::MoveCustomer(int src, int dst, int customerId) : srcTable(src), dstTable(dst), id(customerId) {};

void MoveCustomer::act(Restaurant &restaurant) {
    Table *t1 = restaurant.getTable(srcTable);
    Table *t2 = restaurant.getTable(dstTable);
    if (t1 == nullptr | !t1->isOpen() | t2 == nullptr |
        !t2->isOpen() | t1->getCustomer(id) == nullptr | t2->getCustomers().size() >= t2->getCapacity()) {
        string err = "“Cannot move customer";
        error(err);
    } else {
        vector<OrderPair> copySrcOrders;
        vector<OrderPair> srcOrders = t1->getOrders();
        for (int i = 0; i < srcOrders.size(); ++i) {
            copySrcOrders.push_back(srcOrders[i]);
        }
        srcOrders.clear();
        for (int j = 0; j < copySrcOrders.size(); ++j) {
            if (copySrcOrders[j].first == id) {
                t2->getOrders().push_back(copySrcOrders[j]);
            } else {
                srcOrders.push_back(copySrcOrders[j]); //TODO ::check what the fuck is going on with the copy.
            }
        }
        int newId = t2->getCustomers().size();
        Customer *customer = t1->getCustomer(id);
        Customer *customerToAdd;
        if (customer->getType() == "ALC") {
            customerToAdd = new AlchoholicCustomer(customer->getName(), newId);
        }
        if (customer->getType() == "SPC") {
            customerToAdd = new SpicyCustomer(customer->getName(), newId);
        }
        if (customer->getType() == "CHP") {
            customerToAdd = new CheapCustomer(customer->getName(), newId);
        }
        if (customer->getType() == "VEG") {
            customerToAdd = new VegetarianCustomer(customer->getName(), newId);
        }
        t2->addCustomer(customerToAdd);
        t1->removeCustomer(id);

        complete();
    }
}

string MoveCustomer::toString() const {
    string toRet = "move " + to_string(srcTable) + " " + to_string(dstTable) + " " + to_string(id);
    if (this->getStatus() == COMPLETED)
        toRet += " COMPLETED";
    else if (this->getStatus() == ERROR)
        toRet += " ERROR:" + this->getErrorMsg();
    else
        toRet = "You didn't activate act method.";
    return toRet;
}