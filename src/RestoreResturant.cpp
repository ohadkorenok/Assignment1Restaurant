#include "../include/Action.h"
#include "../include/Table.h"
#include "../include/Restaurant.h"

extern Restaurant *backup;

RestoreResturant::RestoreResturant() {};

RestoreResturant::RestoreResturant(ActionStatus actionStatus, string errorMsg) {
    if (actionStatus == COMPLETED)
        complete();
    if(actionStatus == ActionStatus::ERROR)
        this->error(errorMsg);
}

void RestoreResturant::act(Restaurant &restaurant) {
    if (backup != nullptr) {
        restaurant = (*backup);
        complete();
    } else {
        string err = "No backup available";
        error(err);
        cout << "Error: " + err << endl;
    }

}

std::string RestoreResturant::toString() const {
    string toRet = "restore";
    if (this->getStatus() == COMPLETED)
        toRet += " Completed";
    else if(this->getStatus()==ERROR)
        toRet+=" Error: "+this->getErrorMsg();
    return toRet;
}

BaseAction *RestoreResturant::clone() {
    BaseAction *toRet = nullptr;
    toRet = new RestoreResturant(this->getStatus(), this->getErrorMsg());
    return toRet;
}
