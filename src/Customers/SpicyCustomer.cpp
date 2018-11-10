//
// Created by nitzan on 09/11/18.
//

//TODO :: change default value of customerDish.
#include "../../include/Customer.h"
#include <limits>
SpicyCustomer::SpicyCustomer(std::string name, int id) : Customer(name,id),_isOredered(false){};
std::vector<int> SpicyCustomer::order(const std::vector<Dish> &menu) {
    std::vector<int> vecofOrder(1,0);
    if(!_isOredered){
        int mostexpensivedishPrice=-1;
        int mostexpID=std::numeric_limits<int>::max();
        for(std::vector<Dish>::const_iterator it=menu.begin();it!=menu.end();++it){
            if(it->getType()==SPC & it->getPrice()>mostexpensivedishPrice){
                mostexpensivedishPrice=it->getPrice();
                mostexpID=it->getId();
            }
            else if(it->getType()==SPC &it->getPrice()==mostexpensivedishPrice)
                if(it->getId()<mostexpID)
                    mostexpID=it->getId();
        }
        vecofOrder[0]=mostexpID;
    }
    else{
        int cheapestBVGprice=std::numeric_limits<int>::max();
        int cheapestBVGid=std::numeric_limits<int>::max();
        for(std::vector<Dish>::const_iterator it=menu.begin();it!=menu.end();++it){
            if(it->getType()==BVG & it->getPrice()<cheapestBVGprice){
                cheapestBVGprice=it->getPrice();
                cheapestBVGid=it->getId();
            }
            else if(it->getType()==BVG & it->getPrice()==cheapestBVGprice)
                if(it->getId()<cheapestBVGid)
                    cheapestBVGid=it->getId();
        }
        vecofOrder[0]=cheapestBVGid;
    }
    return vecofOrder;
};
std::string SpicyCustomer::toString() const {return (std::string(getName())+","+std::to_string(getId()));};