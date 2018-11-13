//
// Created by ohadkoren on 09/11/18.
//
#include <iostream>
#include "../include/Table.h"

Table::Table(int t_capacity) {
    capacity = t_capacity;
    this->open = false;
}

/**
 * Copy assignment operator.
 * @param Table
 * @return
 */
Table &Table::operator=(const Table &Table) {
    if (this == &Table) {
        return *this;
    } else {
        clear();
        fillMeUp(Table.customersList, Table.orderList);
        capacity = Table.getCapacity();
        open = Table.open;
    }
}

/**
 * Destructor.
 */
Table::~Table() {
    clear();
}

/**
 * Move Constructor.
 * @param other
 */
Table::Table(Table &&other):capacity(other.capacity), open(other.open), orderList(other.orderList) {
    for (int i = 0; i < other.customersList.size(); ++i) {
        customersList[i] = other.customersList[i];
        other.customersList[i] = nullptr;
    }
    other.orderList.clear();
}

/**
 * Move Assignment Operator.
 * @param other
 * @return
 */
Table& Table::operator=(Table &&other) {
    open = other.open;
    orderList.clear();
    for (int j = 0; j < other.orderList.size(); ++j) {
        orderList.push_back(other.orderList[j]);
    }
//    orderList = other.orderList;
    for (int i = 0; i < other.customersList.size(); ++i) {
        customersList[i] = other.customersList[i];
        other.customersList[i] = nullptr;
    }
    other.orderList.clear();
}

void Table::fillMeUp(vector<Customer *> customersListToCopy, std::vector<OrderPair> orderListToCopy) {
    for (Customer *customer : customersListToCopy) {
        if (customer->getType() == "ALC") {
            customersList.push_back(new AlchoholicCustomer(customer->getName(), customer->getId()));
        } else if (customer->getType() == "CHP") {
            customersList.push_back(new CheapCustomer(customer->getName(), customer->getId()));

        } else if (customer->getType() == "SPC") {
            customersList.push_back(new SpicyCustomer(customer->getName(), customer->getId()));

        } else if (customer->getType() == "VEG") {
            customersList.push_back(new VegetarianCustomer(customer->getName(), customer->getId()));
        }
    }
    for (OrderPair orderPair : orderListToCopy) {
        orderList.push_back(orderPair);
    }

}

void Table::clear() {
    for (Customer *customer1 : customersList) {
        delete customer1;
        customer1 = nullptr;
    }
}

/**
 * Copy Constructor.
 * @param other
 */
Table::Table(const Table &other) {
    capacity = other.getCapacity();
    open = other.open;
    fillMeUp(other.customersList, other.orderList);
}

bool Table::isOpen() {
    return open;
}

int Table::getCapacity() const {
    return capacity;
}

void Table::addCustomer(Customer *customer) {
    if (this->customersList.size() < this->capacity) {
        this->customersList.push_back(customer);
    }
}

void Table::removeCustomer(int id) {
    for (int i = 0; i < customersList.size(); ++i) {
        if (customersList[i]->getId() == id) {
            customersList.erase(customersList.begin() + i);
        }
    }
    if (customersList.empty()) {
        open = false;
    }
}

/**
 * Getter to Customer by id.
 * @param id
 * @return  *Customer or nullptr.
 */
Customer *Table::getCustomer(int id) {
    Customer *customer;
    customer = nullptr;
    for (int i = 0; i < customersList.size(); ++i) {
        if (customersList[i]->getId() == id) {
            customer = customersList[i];
        }
    }
    return customer;

}

std::vector<Customer *> &Table::getCustomers() {
    return customersList;
}

std::vector<OrderPair> &Table::getOrders() {
    return orderList;
}

/**
 *
 * @param menu gets menu
 */
void Table::order(const std::vector<Dish> &menu) {
    if (!open) {
        std::cout << "table is not open" << endl;
    }
    vector<int> customerOrder;
    orderList.clear();
    for (int i = 0; i < customersList.size(); ++i) {
        for (int customerOrder1 :  customersList[i]->order(menu)) {
            if (customerOrder1 != -1) {
                orderList.push_back(OrderPair(customersList[i]->getId(), menu[customerOrder1]));
            }
        }
    }
}

void Table::openTable() {
    open = true;

}

void Table::closeTable() {
    open = false;
    orderList.clear();
    clear();
}

int Table::getBill() {
    int sum = 0;
    for (OrderPair const &orderPair1 : orderList) {
        sum += orderPair1.second.getPrice();
    }
}
