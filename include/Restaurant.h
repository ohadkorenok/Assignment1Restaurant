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
    void setNextCustomerId(int newId);
    int getNextCustomerId();
    int getNumOfTables() const;
    Table* getTable(int ind);
	const vector<BaseAction*>& getActionsLog() const; // Return a reference to the history of actions
    vector<Dish>& getMenu();

    void closeRestaurant();
	// Destructor
	virtual ~Restaurant();

	// Copy Constructor
	Restaurant(const Restaurant &other);

	// Move Constructor
	Restaurant(Restaurant &&other);

	//Copy assignment operator
	Restaurant & operator=(const Restaurant &Restaurant);

	// Move Assignment
	Restaurant& operator=(Restaurant &&other);


private:
    bool open;
    void clear();
    vector<Table*> tables;
    vector<Dish> menu;
    vector<BaseAction*> actionsLog;
    static vector<string> extractArgumentsFromConfig(const string &configFilePath);
    bool createTablesFromArguments(vector <string> argument);
    void buildMenuFromArguments(string menuArgument);
    void fillMeUp(vector <Table*> otherTables, vector<Dish> otherMenu, vector<BaseAction*> otherActionsLog, bool otherOpen);
    void stealFromOther(vector <Table*> otherTables, vector<Dish> otherMenu, vector<BaseAction*> otherActionsLog, bool otherOpen);
    int nextCustomerId=0;

};

#endif