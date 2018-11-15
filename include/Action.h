#ifndef ACTION_H_
#define ACTION_H_

#include <string>
#include <iostream>
#include "Customer.h"


enum ActionStatus {
    PENDING, COMPLETED, ERROR
};

//Forward declaration
class Restaurant;

class BaseAction {

public:
    BaseAction();

    ActionStatus getStatus() const;

    virtual void act(Restaurant &restaurant) = 0;

    virtual std::string toString() const = 0;

    virtual BaseAction *clone() = 0;

    virtual ~BaseAction()= default;


protected:
    void complete();

    void error(std::string errorMsg);

    std::string getErrorMsg() const;

private:
    std::string errorMsg;
    ActionStatus status;
};


class OpenTable : public BaseAction {
public:
    OpenTable(int id, std::vector<Customer *> &customersList);

    OpenTable(int id, std::vector<Customer *> &customersList, ActionStatus actionStatus, string errorMsg);

    void act(Restaurant &restaurant);

    std::string toString() const;

    BaseAction *clone();

    ~OpenTable();

private:
    const int tableId;
    std::vector<Customer *> customers;
};


class Order : public BaseAction {
public:
    Order(int id);

    Order(int id, ActionStatus actionStatus, string errorMsg);

    void act(Restaurant &restaurant);

    std::string toString() const;

    BaseAction *clone();
    ~Order();

private:
    const int tableId;
};


class MoveCustomer : public BaseAction {
public:
    MoveCustomer(int src, int dst, int customerId);

    MoveCustomer(int src, int dst, int customerId, ActionStatus actionStatus, string errorMsg);

    void act(Restaurant &restaurant);

    std::string toString() const;

    BaseAction *clone();

private:
    const int srcTable;
    const int dstTable;
    const int id;
};


class Close : public BaseAction {
public:
    Close(int id);

    Close(int id, ActionStatus actionStatus, string errorMsg);

    void act(Restaurant &restaurant);

    std::string toString() const;

    BaseAction *clone();

private:
    const int tableId;
};


class CloseAll : public BaseAction {
public:
    CloseAll();

    void act(Restaurant &restaurant);

    std::string toString() const;

    BaseAction *clone();

private:
};


class PrintMenu : public BaseAction {
public:
    PrintMenu();

    PrintMenu(ActionStatus actionStatus, string errorMsg);

    void act(Restaurant &restaurant);

    std::string toString() const;

    BaseAction *clone();

private:
};


class PrintTableStatus : public BaseAction {
public:
    PrintTableStatus(int id);

    PrintTableStatus(int id, ActionStatus actionStatus, string errorMsg);

    void act(Restaurant &restaurant);

    std::string toString() const;

    BaseAction *clone();

private:
    const int tableId;
};


class PrintActionsLog : public BaseAction {
public:
    PrintActionsLog();

    PrintActionsLog(ActionStatus actionStatus, string errorMsg);

    void act(Restaurant &restaurant);

    std::string toString() const;

    BaseAction *clone();

private:
};


class BackupRestaurant : public BaseAction {
public:
    BackupRestaurant();

    BackupRestaurant(ActionStatus actionStatus);

    void act(Restaurant &restaurant);

    std::string toString() const;

    BaseAction *clone();

private:
};


class RestoreResturant : public BaseAction {
public:
    RestoreResturant();

    RestoreResturant(ActionStatus actionStatus);

    void act(Restaurant &restaurant);

    std::string toString() const;

    BaseAction *clone();

};


#endif