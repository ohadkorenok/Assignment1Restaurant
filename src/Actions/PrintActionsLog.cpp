//
// Created by nitzan on 10/11/18.
//
#include "../../include/Action.h"
#include "../../include/Table.h"
#include "../../include/Restaurant.h"
using namespace std;

PrintActionsLog::PrintActionsLog() {};
/**
 * TO DO : print the error in case of error message appear.
 * @param restaurant
 */
void PrintActionsLog::act(Restaurant &restaurant) {
    for(BaseAction* i : restaurant.getActionsLog()){
        if(i->getStatus()==COMPLETED)
            cout<<i->toString()+" "+to_string(i->getStatus())<<endl;
        else if(i->getStatus()==ERROR)
            cout<<i->toString()+" "+to_string(i->getStatus())+":"+i->getErrorMsg()<<endl;
    }
    complete();

}
