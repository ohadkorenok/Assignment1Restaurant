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
        BaseAction::error(err);
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
                srcOrders.push_back(copySrcOrders[j]);
            }
        }
        t2->addCustomer(t1->getCustomer(id));
        t1->removeCustomer(id);
        complete();
    }
}