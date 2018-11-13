//
// Created by nitzan on 09/11/18.
//


#include "../../include/Customer.h"
#include "../../include/Dish.h"
#include <algorithm>
using namespace std;

//TODO :: change default value of customerDish.
AlchoholicCustomer::AlchoholicCustomer(std::string name, int id) : Customer(name,id),_firstRun(true){};
vector<int> AlchoholicCustomer::order(const std::vector<Dish> &menu) {
    vector<int> vecofOrder(1,-1);
    if(_firstRun){
        for(vector<Dish>::const_iterator it=menu.begin();it!=menu.end();++it){
            if(it->getType()==ALC) {
                AlcoholPair toPush(it->getId(),it->getPrice());
                alcohol.push_back(toPush);
            }
        }
        vecofOrder[0]=findCheapestNerase(alcohol);
        _firstRun=false;
    }
    else{
        if(alcohol.size()==0)
            vecofOrder[0]=-1;
        else
            vecofOrder[0] = findCheapestNerase(alcohol);
    }
    return vecofOrder;
}
/** return the id of the cheapest alcohol beverage and remove it from the vector.
 *
 */
int AlchoholicCustomer::findCheapestNerase(vector<AlcoholPair> &alc) {
    int minPrice=std::numeric_limits<int>::max();int index=0;int i=0;
    for(AlcoholPair pair: alc){
        if(pair.second < minPrice){
            minPrice=pair.second;
            index=i;
        }
        i++;
    }
    i=alc[index].first;
    alc.erase(alc.begin()+index);
    return i;
}
std::string AlchoholicCustomer::toString() const {return (std::string(getName())+","+std::to_string(getId()));}
std::string AlchoholicCustomer::getType() const {return "alc";}
