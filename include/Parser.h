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
static void parse(std::string firstWord, std::string restOfLine);

private:

    static vector<Customer*> parseOpen(string match);
};


#endif //ASSIGNMENT1RESTAURANT_PARSER_H
