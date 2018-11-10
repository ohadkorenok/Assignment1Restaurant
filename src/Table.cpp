//
// Created by ohadkoren on 09/11/18.
//

#include "../include/Table.h"

Table::Table(int t_capacity) {
    capacity = t_capacity;
}
//
//bool Table::operator==(const Table &rhs) const {
//    return capacity == rhs.capacity &&
//           open == rhs.open &&
//           customersList == rhs.customersList &&
//           orderList == rhs.orderList;
//}

Table &Table::operator=(const Table &Table) {
    if (this == &Table) {
        return *this;
    }


}
//
//bool Table::operator!=(const Table &rhs) const {
//    return !(rhs == *this);
//}

bool Table::isOpen() {
    return false;
}

int Table::getCapacity() const {
    return 0;
}

void Table::addCustomer(Customer *customer) {

}

void Table::removeCustomer(int id) {

}

Customer *Table::getCustomer(int id) {
    return nullptr;
}

//std::vector<Customer *> &Table::getCustomers() {
//    return <#initializer#>;
//}
//
//std::vector<OrderPair> &Table::getOrders() {
//    return <#initializer#>;
//}

void Table::order(const std::vector<Dish> &menu) {

}

void Table::openTable() {

}

void Table::closeTable() {

}

int Table::getBill() {
    return 0;
}
