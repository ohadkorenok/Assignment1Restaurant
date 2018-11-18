#include "../include/Action.h"
#include "../include/Table.h"
#include "../include/Restaurant.h"
using namespace std;

Close::Close(int id) : BaseAction(),tableId(id){};
Close::Close(int id, ActionStatus actionStatus, string errorMsg) : BaseAction(),tableId(id){
    if(actionStatus == ActionStatus::COMPLETED)
        this->complete();
    if(actionStatus == ActionStatus::ERROR)
        this->error(errorMsg);
};

void Close::act(Restaurant &restaurant) {
    Table* t1=restaurant.getTable(tableId);
    if((t1 == nullptr) | (!t1->isOpen())){
        string err="Table does not exist or is not open";
        cout << "Error: "+err << endl;
        error(err);
    }
    else{
        cout<< "Table " + to_string(tableId) +" was closed. Bill "+ to_string(t1->getBill())+"NIS"+"\n"<<std::endl;
        t1->closeTable();
        complete();
    }

}
string Close::toString() const {
    string toRet="close "+to_string(tableId);
    if(this->getStatus()==COMPLETED)
        toRet+=" Completed";
    else if(this->getStatus()==ERROR)
        toRet+=" ERROR:"+this->getErrorMsg();
    else
        toRet="You didn't activate act method.";
    return toRet;
}
BaseAction* Close::clone() {
    BaseAction* toRet= nullptr;
    toRet=new Close(tableId, this->getStatus(), this->getErrorMsg());
    return toRet;
}