#ifndef TABLE_H_
#define TABLE_H_

#include <vector>
#include "Customer.h"
#include "Dish.h"
using namespace std;

typedef std::pair<int, Dish> OrderPair;

class Table{
public:
    Table(int t_capacity);
    int getCapacity() const;
    void addCustomer(Customer* customer);
    void removeCustomer(int id);
    Customer* getCustomer(int id);
    std::vector<Customer*>& getCustomers();
    std::vector<OrderPair>& getOrders();
    void order(const std::vector<Dish> &menu);
    void openTable();
    void closeTable();
    int getBill();
    bool isOpen();

    // Destructor
    virtual ~Table();

    // Copy Constructor
    Table(const Table &other);

    // Move Constructor
    Table(Table &&other);

    //Copy assignment operator
    Table & operator=(const Table &Table);

    // Move Assignment
    Table& operator=(Table &&other);

//    bool operator==(const Table &rhs, Table &Table) const;

//    bool operator!=(const Table &rhs) const;

private:
    int capacity;
    bool open;
    std::vector<Customer*> customersList;
    std::vector<OrderPair> orderList; //A list of pairs for each order in a table - (customer_id, Dish)
    void clear();
    void fillMeUp(vector<Customer*> customersListToCopy, std::vector<OrderPair> orderListToCopy);
};


#endif