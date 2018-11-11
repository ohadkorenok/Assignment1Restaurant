//
// Created by ohadkoren on 09/11/18.
//
#include <iostream>
#include "../include/Table.h"

Table::Table(int t_capacity) {
    capacity = t_capacity;
    this->open = false;
}
//TODO:: change the copy assignment operator!
Table &Table::operator=(const Table &Table) {
    if (this == &Table) {
        return *this;
    }
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
    if(!open){
        std::cout << "table is not open" << endl;
    }
    vector<int> customerOrder;
    for (int i = 0; i < customersList.size(); ++i) {
        for (int customerOrder1 :  customersList[i]->order(menu)){
            if(customerOrder1 != -1) {
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
    customersList.clear();
}

int Table::getBill() {
    int sum = 0;
    for(OrderPair const &orderPair1 : orderList){
        sum+=orderPair1.second.getPrice();
    }
}
