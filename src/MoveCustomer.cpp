#include "../include/Action.h"
#include "../include/Table.h"
#include "../include/Restaurant.h"
#include <vector>
#include <string>

using namespace std;

MoveCustomer::MoveCustomer(int src, int dst, int customerId) : srcTable(src), dstTable(dst), id(customerId) {};
MoveCustomer::MoveCustomer(int src, int dst, int customerId, ActionStatus actionStatus, string errorMsg) : srcTable(src), dstTable(dst), id(customerId) {
    if(actionStatus == ActionStatus::COMPLETED)
        this->complete();
    if(actionStatus == ActionStatus::ERROR)
        this->error(errorMsg);
};


void MoveCustomer::act(Restaurant &restaurant) {
    Table *t1 = restaurant.getTable(srcTable);
    Table *t2 = restaurant.getTable(dstTable);
    if ((t1 == nullptr) | (!t1->isOpen()) | (t2 == nullptr) |
            (!t2->isOpen()) | (t1->getCustomer(id) == nullptr) | (t2->getCustomers().size() >= size_t (t2->getCapacity()))) {
        string err = "“Cannot move customer";
        error(err);
    } else {
        vector<OrderPair> copySrcOrders;
        vector<OrderPair> srcOrders = t1->getOrders();
        for (size_t i = 0; i < srcOrders.size(); ++i) {
            copySrcOrders.push_back(srcOrders[i]);
        }
        srcOrders.clear();
        for (size_t j = 0; j < copySrcOrders.size(); ++j) {
            if (copySrcOrders[j].first == id) {
                t2->getOrders().push_back(copySrcOrders[j]);
            } else {
                srcOrders.push_back(copySrcOrders[j]);
            }
        }
        t1->getOrders().clear();
        for(OrderPair i : srcOrders)
            t1->getOrders().push_back(i);
        Customer *customer = t1->getCustomer(id);
        t2->addCustomer(customer);
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
BaseAction* MoveCustomer::clone() {
    BaseAction* toRet= nullptr;
    toRet=new MoveCustomer(srcTable,dstTable,id, this->getStatus(), this->getErrorMsg());
    return toRet;
}