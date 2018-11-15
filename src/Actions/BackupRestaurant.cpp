//
// Created by nitzan on 11/11/18.
//
#include "../../include/Action.h"
#include "../../include/Table.h"
#include "../../include/Restaurant.h"
extern Restaurant* backup;

BackupRestaurant::BackupRestaurant(){};
BackupRestaurant::BackupRestaurant(ActionStatus actionStatus){
    if(actionStatus == COMPLETED)
        complete();
};
void BackupRestaurant::act(Restaurant &restaurant) {
    backup=new Restaurant(restaurant);
    complete();
}


std::string BackupRestaurant::toString() const {
    string toRet="backup";
    if(this->getStatus()==COMPLETED)
        toRet+=" COMPLETED";
    else
        toRet="You didn't activate act method.";
    return toRet;
}
BaseAction* BackupRestaurant::clone() {
    BaseAction* toRet= nullptr;
    toRet=new BackupRestaurant(this->getStatus());
    return toRet;
}

