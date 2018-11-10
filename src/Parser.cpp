#include "../include/Parser.h"
#include "regex"

void Parser::parse(std::string firstWord, std::string fullLine) {

    regex openReg("open\\s*(\\d+)\\s*(.*)");
    regex orderReg("order\\s*(\\d+)");
    regex moveReg("move\\s*(\\d+)\\s*(\\d+)\\s*(\\d+)");
    regex closeReg("close\\s*(\\d+)");
    regex closeAllReg("closeall\\s*");
    regex printMenuReg("menu\\s*");
    regex printTableStatusReg("status\\s*(\\d+)");
    regex printActionsLogReg("log");
    regex backupRestaurantReg("backup");
    regex restoreReg("restore");

    map<string, regex> regexDict ={
            {"open", openReg},
            {"order", orderReg},
            {"move", moveReg},
            {"close",closeReg},
            {"closeall",closeAllReg},
            {"menu",printMenuReg},
            {"status",printTableStatusReg},
            {"log",printActionsLogReg},
            {"backup",backupRestaurantReg},
            {"restore",restoreReg}
    };

    std::smatch smatch1;
    if(regex_search(fullLine, smatch1, regexDict[firstWord])){
        cout<< smatch1[0]<<endl;
//        cout<< smatch1[1]<<endl;
    }
    if(!smatch1.empty() ){
        cout<<"hi"<<endl;

        if(firstWord == "open"){
            string stringOfMatch= smatch1[2].str();
            istringstream is1 (stringOfMatch);
            string customer;
            while(getline(is1, customer , ' ')) {
                istringstream is2(customer);
                string name;
                string strategy;
                getline(is2, name, ',');
                getline(is2,strategy, ',');
                // TODO :: build new customer and push it down the Customer Vector.
            }
            string adva = "adva";
        }

        if(firstWord == "order"){

        }

        if(firstWord == "move"){

        }
        if(firstWord == "close"){

        }
        if(firstWord == "closeall"){

        }
        if(firstWord == "menu"){

        }
        if(firstWord == "status"){

        }
        if(firstWord == "log"){

        }
        if(firstWord == "backuo"){

        }

        if(firstWord == "restore"){

        }
    }

    string ohad = "ohad";



}