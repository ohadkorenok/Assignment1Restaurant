#include "../include/Action.h"
#include "../include/Table.h"
#include "../include/Restaurant.h"
using namespace std;

CloseAll::CloseAll() {};
void CloseAll::act(Restaurant &restaurant) {
    for(int i=0;i<restaurant.getNumOfTables()-1;i++){
        Table* t1=restaurant.getTable(i);
        if(t1->isOpen()) {
            Close tableI = Close(i);
            tableI.act(restaurant);
        }
    }
    restaurant.closeRestaurant();
    complete();
}
string CloseAll::toString() const {
    string toRet="closeall";
    return toRet;}
BaseAction* CloseAll::clone() {
    BaseAction* toRet= nullptr;
    toRet=new CloseAll();
    return toRet;
}