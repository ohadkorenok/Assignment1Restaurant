//
// Created by ohadkoren on 08/11/18.
//
#include <limits>
#include "../../include/Customer.h"
VegetarianCustomer::VegetarianCustomer(std::string name, int id) : Customer(name, id){}
std::vector<int> VegetarianCustomer::order(const std::vector<Dish> &menu) {
    std::vector<int> vecofOrder(2,-1);
    int smallestID=std::numeric_limits<int>::max();
    int expensiveBVGid=std::numeric_limits<int>::max();
    int maxBVGprice=-1;
    for(std::vector<Dish>::const_iterator it=menu.begin();it!=menu.end();++it){
        if(it->getType()==VEG & it->getId()<smallestID)
            smallestID=getId();
        if(it->getType()==BVG & it->getPrice()>=maxBVGprice & it->getId()<expensiveBVGid)
            expensiveBVGid=it->getId();
    }
    if(smallestID<numeric_limits<int>::max() & expensiveBVGid<numeric_limits<int>::max()) {
        vecofOrder[0]=smallestID;
        vecofOrder[1] = expensiveBVGid;
    }
    return vecofOrder;
}
std::string VegetarianCustomer::toString() const {
    return (std::string(getName())+","+std::to_string(getId()));
}
std::string VegetarianCustomer::getType() const {return "veg";}