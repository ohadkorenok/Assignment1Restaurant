#include <algorithm>
#include "../include/Action.h"
#include "../include/Table.h"
#include "../include/Restaurant.h"

using namespace std;

OpenTable::OpenTable(int id, std::vector<Customer *> &customersList)
        : BaseAction::BaseAction(), tableId(id), customers(customersList) {};

OpenTable::OpenTable(int id, std::vector<Customer *> &customersList, ActionStatus actionStatus, string errorMsg)
        : BaseAction::BaseAction(), tableId(id), customers(customersList) {
    if (actionStatus == ActionStatus::COMPLETED)
        this->complete();
    if (actionStatus == ActionStatus::ERROR)
        this->error(errorMsg);
};

void OpenTable::act(Restaurant &restaurant) {
    Table *t1 = restaurant.getTable(tableId);
    if ((t1 == nullptr) | (t1->isOpen())) {
        string err = "Table does not exist or is already open";
        error(err);
        cout << "Error: "+err << endl;
    } else if (customers.size() > size_t (t1->getCapacity())) {
    }
     else {
        t1->openTable();
        for (size_t i = 0; i < customers.size(); ++i) {
            Customer *customer1=nullptr;
            if (customers[i]->getType() == "ALC") {
                customer1 = new AlchoholicCustomer(customers[i]->getName(), customers[i]->getId());
            } else if (customers[i]->getType() == "CHP") {
                customer1 = new CheapCustomer(customers[i]->getName(), customers[i]->getId());
            } else if (customers[i]->getType() == "VEG") {
                customer1 = new VegetarianCustomer(customers[i]->getName(), customers[i]->getId());
            } else if (customers[i]->getType() == "SPC") {
                customer1 = new SpicyCustomer(customers[i]->getName(), customers[i]->getId());
            }
            t1->addCustomer(customer1);
        }
        complete();
    }

}

string OpenTable::toString() const {
    string toRet = "open " + to_string(tableId);
    for (Customer *i : customers) {
        string type = i->getType();
        transform(type.begin(), type.end(), type.begin(), ::tolower);
        toRet += " " + i->getName() + "," + type;
    }

    if (this->getStatus() == COMPLETED)
        toRet += " Completed";
    else if (this->getStatus() == ERROR)
        toRet += " Error: " + this->getErrorMsg();
    return toRet;
}

BaseAction *OpenTable::clone() {
    vector<Customer *> clonedCustomers;
    for (Customer *customer: customers) {
        if (customer->getType() == "ALC"){
            Customer* customerToPush=nullptr;
            customerToPush = new AlchoholicCustomer(customer->getName(), customer->getId());
            clonedCustomers.push_back(customerToPush);
        }
        else if (customer->getType() == "VEG"){
            Customer* customerToPush=nullptr;
            customerToPush = new VegetarianCustomer(customer->getName(), customer->getId());
            clonedCustomers.push_back(customerToPush);
        }
        else if (customer->getType() == "CHP") {
            Customer *customerToPush = nullptr;
            customerToPush = new CheapCustomer(customer->getName(), customer->getId());
            clonedCustomers.push_back(customerToPush);
        }
        else if (customer->getType() == "SPC"){
            Customer* customerToPush=nullptr;
            customerToPush = new SpicyCustomer(customer->getName(), customer->getId());
            clonedCustomers.push_back(customerToPush);
        }
    }
    BaseAction *toRet = new OpenTable(tableId, clonedCustomers, this->getStatus(), this->getErrorMsg());
    return toRet;
}


OpenTable::~OpenTable() {
    for (size_t i = 0; i < this->customers.size(); ++i) {
        delete this->customers[i];
        this->customers[i] = nullptr;
    }
}
