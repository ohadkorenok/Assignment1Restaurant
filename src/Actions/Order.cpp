//
// Created by nitzan on 10/11/18.
//
#include "../../include/Action.h"
#include "../../include/Table.h"
#include "../../include/Restaurant.h"
using namespace std;

Order::Order(int id) : BaseAction::BaseAction(),tableId(id){};
void Order::act(Restaurant &restaurant) {
    Table* t1=restaurant.getTable(tableId);
    if(t1 == nullptr | t1->isOpen()){
        string err="Table does not exist or is already open";
        BaseAction::error(err);
    }
    else{
        t1->order(restaurant.getMenu());
        for(std::vector<OrderPair>::iterator it= t1->getOrders().begin();it!=t1->getOrders().end();++it){
            cout<< t1->getCustomer((*it).first)->getName()+" ordered "+ (*it).second.getName()<<std::endl;
    }
        complete();
    }
}
