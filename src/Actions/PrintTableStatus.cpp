//
// Created by nitzan on 10/11/18.
//
#include "../../include/Action.h"
#include "../../include/Table.h"
#include "../../include/Restaurant.h"
using namespace std;

PrintTableStatus::PrintTableStatus(int id): tableId(id) {};
void PrintTableStatus::act(Restaurant &restaurant) {
    Table* t1=restaurant.getTable(tableId);
    if(!t1->isOpen())
        cout<<"Table "+ to_string(tableId)+" status: closed"<<endl;
    else{
        cout<<"Table "+ to_string(tableId)+" status: open"+ "\n"+"Customers:"<<endl;
        for(Customer* i : t1->getCustomers()){
            cout<<to_string(i->getId())+" "+i->getName()<<endl;
        }
        cout<<"Orders:"<<endl;
        for(OrderPair i : t1->getOrders())
            cout<<to_string(i.second.getId())+" "+to_string(i.second.getPrice())+"NIS"+" "+to_string(i.first)<<endl;
        cout<<"Current Bill: "+to_string(t1->getBill())+"NIS"<<endl;
    }
    complete();
}
string PrintTableStatus::toString() const {
    string toRet="status "+to_string(tableId);
    if(this->getStatus()==COMPLETED)
        toRet+=" COMPLETED";
    else
        toRet="You didn't activate act method.";
    return toRet;
}
BaseAction* PrintTableStatus::clone() {
    BaseAction* toRet=new PrintTableStatus(tableId);
    return toRet;
}