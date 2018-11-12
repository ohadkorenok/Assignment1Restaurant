//
// Created by nitzan on 10/11/18.
//
#include "../../include/Action.h"
#include "../../include/Table.h"
#include "../../include/Restaurant.h"
using namespace std;

PrintActionsLog::PrintActionsLog() {};
string PrintActionsLog::toString() const {
    string toRet="log";
    if(this->getStatus()==COMPLETED)
        toRet+=" COMPLETED";
    else
        toRet="You didn't activate act method.";
    return toRet;
}

/**
 * Print Actions Log.
 * @param restaurant
 */
void PrintActionsLog::act(Restaurant &restaurant) {
    for(BaseAction * action :restaurant.getActionsLog()){
        cout << action->toString() << endl;
    }
    complete();
}
