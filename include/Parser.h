//
// Created by ohadkoren on 08/11/18.
//

#ifndef ASSIGNMENT1RESTAURANT_PARSER_H
#define ASSIGNMENT1RESTAURANT_PARSER_H

#include <map>
#include "Action.h"
#include "Customer.h"
#
class Parser{
public:
static void parse(std::string firstWord, std::string restOfLine, Restaurant &restaurant);

private:

    static vector<Customer*> parseOpen(string match);
    static void runAction(BaseAction *action, Restaurant &restaurant);
};


#endif //ASSIGNMENT1RESTAURANT_PARSER_H
