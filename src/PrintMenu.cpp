#include "../include/Action.h"
#include "../include/Table.h"
#include "../include/Restaurant.h"
using namespace std;

PrintMenu::PrintMenu() {};
PrintMenu::PrintMenu(ActionStatus actionStatus, string errorMsg) {
    if(actionStatus == ActionStatus::COMPLETED)
        this->complete();
    if(actionStatus == ActionStatus::ERROR)
        this->error(errorMsg);
};

void PrintMenu::act(Restaurant &restaurant) {
    for(Dish i : restaurant.getMenu())
        cout<<i.getName()+" "+ i.getTypeInString()+" "+ to_string(i.getPrice())+"NIS"<<endl;

    complete();
}
string PrintMenu::toString() const {
    string toRet="menu";
    if(this->getStatus()==COMPLETED)
        toRet+=" Completed";
    return toRet;
};
BaseAction* PrintMenu::clone() {
    BaseAction* toRet= nullptr;
    toRet=new PrintMenu(this->getStatus(), this->getErrorMsg());
    return toRet;
}
