
#include "../include/Dish.h"
using namespace std;

Dish::Dish(int d_id, std::string d_name, int d_price, DishType d_type):id(d_id), name(d_name),price(d_price), type(d_type){}
std::string Dish::getName() const {return name;}
int Dish::getId() const {
    return id;
}
int Dish::getPrice() const {
    return price;
}
DishType Dish::getType() const {
    return type;
}

string Dish::getTypeInString() const {
    string returnString;
    if(type == ALC){
        returnString = "ALC";
    }
    if(type == SPC){
        returnString = "SPC";
    }
    if(type == BVG){
        returnString = "BVG";
    }
    if(type == VEG){
        returnString = "VEG";
    }
    return returnString;
}