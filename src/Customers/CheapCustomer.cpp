//
// Created by nitzan on 09/11/18.
//

//TODO :: change default value of customerDish.
#include "../../include/Customer.h"
#include <limits>
CheapCustomer::CheapCustomer(std::string name, int id) : Customer(name,id),_isOrdered(false) {};
std::vector<int> CheapCustomer::order(const std::vector<Dish> &menu) {
    std::vector<int> vecofOrder(1,-1);
    if(!_isOrdered){
        int cheapestdishPrice=std::numeric_limits<int>::max();
        int cheapestdishID=0;
        for(std::vector<Dish>::const_iterator it=menu.begin();it!=menu.end();++it){
            if(it->getPrice()<cheapestdishPrice) {
                cheapestdishPrice = it->getId();
                cheapestdishID=it->getId();
            }
            else if(it->getPrice()==cheapestdishPrice)
                if(it->getId()<cheapestdishID)
                    cheapestdishID=it->getId();
        }
        vecofOrder[0]=cheapestdishPrice;
    }
    return vecofOrder;
}

std::string CheapCustomer::toString() const {return (std::string(getName())+","+std::to_string(getId()));}
