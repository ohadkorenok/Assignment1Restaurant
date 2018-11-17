

#include "../include/Customer.h"
#include <limits>

SpicyCustomer::SpicyCustomer(std::string name, int id) : Customer(name, id), _isOredered(false) {};

std::vector<int> SpicyCustomer::order(const std::vector<Dish> &menu) {
    std::vector<int> vecofOrder(1, -1);
    if (!_isOredered) {
        int mostexpensivedishPrice = -1;
        int mostexpID = std::numeric_limits<int>::max();
        for (const Dish &dish: menu) {
            if ((dish.getType() == SPC) && (dish.getPrice() > mostexpensivedishPrice)) {
                if (dish.getPrice() > mostexpensivedishPrice) {
                    mostexpID = dish.getId();
                    mostexpensivedishPrice=dish.getPrice();
                }
            }
        }
        if(mostexpID<std::numeric_limits<int>::max())
            vecofOrder[0] = mostexpID;
        _isOredered = true;
    } else {
        int cheapestBVGprice = std::numeric_limits<int>::max();
        int cheapestBVGid = std::numeric_limits<int>::max();
        for (const Dish &dish: menu) {
            if ((dish.getType() == BVG) & (dish.getPrice() < cheapestBVGprice)) {
                cheapestBVGprice = dish.getPrice();
                cheapestBVGid = dish.getId();
            } else if ((dish.getType() == BVG) & (dish.getPrice() == cheapestBVGprice))
                if (dish.getId() < cheapestBVGid)
                    cheapestBVGid = dish.getId();
        }
        if(cheapestBVGid<std::numeric_limits<int>::max())
            vecofOrder[0] = cheapestBVGid;
    }

    return vecofOrder;
};

std::string SpicyCustomer::toString() const { return (std::string(getName()) + "," + std::to_string(getId())); };

std::string SpicyCustomer::getType() const { return "SPC"; };