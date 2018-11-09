
#include "../../include/Dish.h"
using namespace std;

Dish::Dish(int d_id, std::string d_name, int d_price, DishType d_type):id(d_id), name(d_name),price(d_price), type(d_type){}
std::string Dish::getName() const {return name;}
bool Dish::compare(const Dish &a1,const Dish &a2) {
    return a1.getPrice()<a2.getPrice();
}
int Dish::getId() const {
    return id;
}
int Dish::getPrice() const {
    return price;
}
DishType Dish::getType() const {
    return type;
}