//
// Created by nitzan on 10/11/18.
//
#include "../../include/Action.h"
#include "../../include/Table.h"
#include "../../include/Restaurant.h"
using namespace std;

PrintMenu::PrintMenu() {};
void PrintMenu::act(Restaurant &restaurant) {
    for(Dish i : restaurant.getMenu())
//        cout<<i.getName()+" "+ to_string(i.getType())+" "+ to_string(i.getPrice())+"NIS"+"\n"<<endl;
        cout<<i.getName()+" "+ i.getTypeInString()+" "+ to_string(i.getPrice())+"NIS"+"\n"<<endl;

    complete();
}
string PrintMenu::toString() const {
    string toRet="menu";
    if(this->getStatus()==COMPLETED)
        toRet+=" COMPLETED";
    else
        toRet="You didn't activate act method.";
    return toRet;
};
BaseAction* PrintMenu::clone() {
    BaseAction* toRet=new PrintMenu();
    return toRet;
}
