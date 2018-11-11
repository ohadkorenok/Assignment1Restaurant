//
// Created by nitzan on 09/11/18.
//
#include "../../include/Customer.h"
#include "../../include/Dish.h"
#include <algorithm>
using namespace std;

AlchoholicCustomer::AlchoholicCustomer(std::string name, int id) : Customer(name,id),_firstRun(true),orders(0){};
vector<int> AlchoholicCustomer::order(const std::vector<Dish> &menu) {
    vector<int> vecofOrder(1,-1);
    if(_firstRun){
        for(vector<Dish>::const_iterator it=menu.begin();it!=menu.end();++it){
            if(it->getType()==ALC)
                alcohol.push_back(*it);
        }
        sort(alcohol.begin(),alcohol.end(), Dish::compare);
        vecofOrder.at(0)=alcohol.at(orders).getId();
        orders++;
    }
    else{
        if(orders>(alcohol.size()-1))
            vecofOrder.at(0)=-1;
        else {
            vecofOrder.at(0) = alcohol.at(orders).getId();
            if (orders < alcohol.size())
                orders++;
        }
    }
    return vecofOrder;
}
std::string AlchoholicCustomer::toString() const {return (std::string(getName())+","+std::to_string(getId()));}
std::string AlchoholicCustomer::getType() const {return "alc";}
