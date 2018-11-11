//
// Created by nitzan on 11/11/18.
//
#include "../../include/Action.h"
#include "../../include/Table.h"
#include "../../include/Restaurant.h"
BackupRestaurant::BackupRestaurant() {};
void BackupRestaurant::act(Restaurant &restaurant) {
}


std::string BackupRestaurant::toString() const {
    string toRet="backup";
    if(this->getStatus()==COMPLETED)
        toRet+=" COMPLETED";
    else
        toRet="You didn't activate act method.";
    return toRet;
}

