#include "../include/Customer.h"
#include <limits>
CheapCustomer::CheapCustomer(std::string name, int id) : Customer(name,id),_isOrdered(false) {};
std::vector<int> CheapCustomer::order(const std::vector<Dish> &menu) {
    std::vector<int> vecofOrder(1,-1);
    if(!_isOrdered){
        _isOrdered=true;
        int cheapestdishPrice=std::numeric_limits<int>::max();
        int cheapestdishID=0;
        for(std::vector<Dish>::const_iterator it=menu.begin();it!=menu.end();++it){
            if(it->getPrice()<cheapestdishPrice) {
                cheapestdishPrice = it->getPrice();
                cheapestdishID=it->getId();
            }
        }
        vecofOrder[0]=cheapestdishID;
    }
    return vecofOrder;
}

std::string CheapCustomer::toString() const {return (std::string(getName())+","+std::to_string(getId()));}
std::string CheapCustomer::getType() const {return "CHP";}