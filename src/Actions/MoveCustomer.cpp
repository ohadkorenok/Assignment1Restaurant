//
// Created by nitzan on 10/11/18.
//
#include "../../include/Action.h"
#include "../../include/Table.h"
#include "../../include/Restaurant.h"
using namespace std;

MoveCustomer::MoveCustomer(int src, int dst, int customerId): srcTable(src),dstTable(dst),id(customerId){};
void MoveCustomer::act(Restaurant &restaurant) {
    Table* t1=restaurant.getTable(srcTable);
    Table* t2=restaurant.getTable(dstTable);
    if(t1 == nullptr | !t1->isOpen() | t2==nullptr || !t2->isOpen() | t1->getCustomer(id)==nullptr | t2->getCustomers().size()>=t2->getCapacity()){
        string err="“Cannot move customer";
        BaseAction::error(err);
    }
    else{
        int i=0;
        for(vector<OrderPair>::iterator it=t1->getOrders().begin();it!=t1->getOrders().end();++it){
            i++;
            if(it->first==id){
                t2->getOrders().push_back(*it);
                t1->getOrders().erase(t1->getOrders().begin()+i);
            }
            t2->addCustomer(t1->getCustomer(id));
            t1->removeCustomer(id);
        }
        complete();
    }
}
string MoveCustomer::toString() const {
    string toRet="move "+to_string(srcTable)+" "+to_string(dstTable)+" "+to_string(id);
    if(this->getStatus()==COMPLETED)
        toRet+=" COMPLETED";
    else if(this->getStatus()==ERROR)
        toRet+=" ERROR:"+this->getErrorMsg();
    else
        toRet="You didn't activate act method.";
    return toRet;
}