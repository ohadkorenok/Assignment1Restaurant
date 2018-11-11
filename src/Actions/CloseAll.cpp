//
// Created by nitzan on 10/11/18.
//
#include "../../include/Action.h"
#include "../../include/Table.h"
#include "../../include/Restaurant.h"
using namespace std;

CloseAll::CloseAll() {};
void CloseAll::act(Restaurant &restaurant) {
    for(int i=0;i<restaurant.getNumOfTables()-1;i++){
        Table* t1=restaurant.getTable(i);
        Close tableI = Close(i);
        tableI.act(restaurant);
    }
    restaurant.closeRestaurant();
    complete();
    std::exit(1);
}

