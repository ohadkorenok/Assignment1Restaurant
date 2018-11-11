//
// Created by nitzan on 10/11/18.
//
#include "../../include/Action.h"
#include "../../include/Table.h"
#include "../../include/Restaurant.h"
using namespace std;

PrintActionsLog::PrintActionsLog() {};
void PrintActionsLog::act(Restaurant &restaurant) {
    for(BaseAction* i : restaurant.getActionsLog()){
        cout<<i->toString()<endl;
    }
    complete();

}
string PrintActionsLog::toString() const {
    string toRet="log";
    if(this->getStatus()==COMPLETED)
        toRet+=" COMPLETED";
    else
        toRet="You didn't activate act method.";
    return toRet;
}
