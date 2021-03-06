#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <vector>
#include <string>
#include "Dish.h"

using namespace std;

class Customer{
public:
    Customer(std::string c_name, int c_id);
    virtual std::vector<int> order(const std::vector<Dish> &menu)=0;
    virtual std::string toString() const = 0;
    virtual std::string getType() const = 0;
    std::string getName() const;
    int getId() const;
private:
    const std::string name;
    const int id;
};


class VegetarianCustomer : public Customer {
public:
    VegetarianCustomer(std::string name, int id);
    std::vector<int> order(const std::vector<Dish> &menu);
    std::string toString() const;
    std::string getType() const;
private:
};


class CheapCustomer : public Customer {
public:
    CheapCustomer(std::string name, int id);
    std::vector<int> order(const std::vector<Dish> &menu);
    std::string toString() const;
    std::string getType() const;
private:
    bool _isOrdered;
};


class SpicyCustomer : public Customer {
public:
    SpicyCustomer(std::string name, int id);
    std::vector<int> order(const std::vector<Dish> &menu);
    std::string toString() const;
    std::string getType() const;
private:
    bool _isOredered;
};


class AlchoholicCustomer : public Customer {
    typedef std::pair<int, int> AlcoholPair; //first=id of alcohol,second=price;
public:
    AlchoholicCustomer(std::string name, int id);
    std::vector<int> order(const std::vector<Dish> &menu);
    std::string toString() const;
    std::string getType() const;
private:
    int findCheapestNerase(vector<AlcoholPair> &alc);
    std::vector<AlcoholPair> alcohol;
    bool _firstRun;
    int orders;
};


#endif