#ifndef RESTAURANT_H_
#define RESTAURANT_H_

#include <vector>
#include <string>
#include "Dish.h"
#include "Table.h"
#include "Action.h"
#include "Parser.h"
using namespace std;

class Restaurant{		
public:
	Restaurant();
    Restaurant(const string &configFilePath);
    void start();
    int getNumOfTables() const;
    Table* getTable(int ind);
	const vector<BaseAction*>& getActionsLog() const; // Return a reference to the history of actions
    vector<Dish>& getMenu();
    void closeRestaurant();

private:
    bool open;
    vector<Table*> tables;
    vector<Dish> menu;
    vector<BaseAction*> actionsLog;
    static vector<string> extractArgumentsFromConfig(const string &configFilePath);
    bool createTablesFromArguments(vector <string> argument);
    void buildMenuFromArguments(string menuArgument);

};

#endif