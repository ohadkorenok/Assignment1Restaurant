//
// Created by nitzan on 10/11/18.
//
#include "../../include/Action.h"
#include "../../include/Table.h"
#include "../../include/Restaurant.h"

using namespace std;

Order::Order(int id) : BaseAction::BaseAction(), tableId(id) {};
Order::Order(int id, ActionStatus actionStatus, string errorMsg) : BaseAction::BaseAction(), tableId(id) {
    if(actionStatus == ActionStatus::COMPLETED)
        this->complete();
    if(actionStatus == ActionStatus::ERROR)
        this->error(errorMsg);
};


void Order::act(Restaurant &restaurant) {
    Table *t1 = restaurant.getTable(tableId);
    if (t1 == nullptr | !t1->isOpen()) {
        string err = "Table does not exist or is already open";
        BaseAction::error(err);
    } else {
        t1->order(restaurant.getMenu());
        vector<OrderPair> lastOrders = t1->getLastOrderList();
        for (int i = 0; i < lastOrders.size(); ++i) {
            cout << t1->getCustomer(lastOrders[i].first)->getName() + " ordered " +lastOrders[i].second.getName() << endl;
        }
//        for (std::vector<OrderPair>::iterator it = t1->getLastOrderList().begin(); it != t1->getLastOrderList().end(); ++it) {
//            cout << t1->getCustomer((*it).first)->getName() + " ordered " + (*it).second.getName() << std::endl;
//        }
        complete();
    }
}

string Order::toString() const {
    string toRet = "order " + to_string(tableId);
    if (this->getStatus() == COMPLETED)
        toRet += " COMPLETED";
    else if (this->getStatus() == ERROR)
        toRet += " ERROR:" + this->getErrorMsg();
    else
        toRet = "You didn't activate act method.";
    return toRet;
}

BaseAction* Order::clone() {
    BaseAction* toRet= nullptr;
    toRet=new Order(tableId, this->getStatus(), this->getErrorMsg());
    return toRet;
}

Order::~Order() {}
