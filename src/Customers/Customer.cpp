#include "../../include/Customer.h"

//TODO :: change default value of customerDish.
Customer::Customer(std::string c_name, int c_id):name(c_name), id(c_id) {};
std::string Customer::getName() const {return name;}
int Customer::getId() const {return id;}



