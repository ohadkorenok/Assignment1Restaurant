#include "include/Restaurant.h"
#include <iostream>

using namespace std;

Restaurant *backup = nullptr;

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "usage: rest <config_path>" << std::endl;
        std::cout << argv[0] << endl;
        std::cout << argv[1] << endl;
        std::cout << argv[2] << endl;
        std::cout << argc << endl;
        return 0;
    }
    std::string pathname = __BASE_FILE__;
    string const configurationFile = pathname.substr(0,pathname.size() - 9)+"/"+argv[1];
    Restaurant rest(configurationFile);
}
/**
rest.start();
if(backup!=nullptr){
    delete backup;
    backup = nullptr;
}
return 0;
//}
 **/