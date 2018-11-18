#include "../include/Action.h"
#include "../include/Table.h"
#include "../include/Restaurant.h"

extern Restaurant *backup;

RestoreResturant::RestoreResturant() {};

RestoreResturant::RestoreResturant(ActionStatus actionStatus) {
    if (actionStatus == COMPLETED)
        complete();
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
    else
        toRet = "You didn't activate act method.";
    return toRet;
}

BaseAction *RestoreResturant::clone() {
    BaseAction *toRet = nullptr;
    toRet = new RestoreResturant(this->getStatus());
    return toRet;
}
