#include "../include/Action.h"
#include "../include/Table.h"
#include "../include/Restaurant.h"
using namespace std;

PrintActionsLog::PrintActionsLog() {};
PrintActionsLog::PrintActionsLog(ActionStatus actionStatus, string errorMsg) {
    if(actionStatus == ActionStatus::COMPLETED)
        this->complete();
    if(actionStatus == ActionStatus::ERROR)
        this->error(errorMsg);
};
string PrintActionsLog::toString() const {
    string toRet="log";
    if(this->getStatus()==COMPLETED)
        toRet+=" Completed";
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
BaseAction* PrintActionsLog::clone() {
    BaseAction* toRet= nullptr;
    toRet=new PrintActionsLog(this->getStatus(), this->getErrorMsg());
    return toRet;
}
