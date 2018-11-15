cmake_minimum_required(VERSION 3.12)
project(Assignment1Restaurant)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment1Restaurant src/main.cpp src/Dish.cpp src/Customer.cpp src/AlchoholicCustomer.cpp src/VegeterianCustomer.cpp src/MoveCustomer.cpp src/Restaurant.cpp src/Parser.cpp include/Parser.h src/Table.cpp src/CheapCustomer.cpp src/SpicyCustomer.cpp src/BaseAction.cpp src/OpenTable.cpp src/Order.cpp src/Close.cpp src/CloseAll.cpp src/PrintMenu.cpp src/PrintTableStatus.cpp src/PrintActionsLog.cpp src/BackupRestaurant.cpp src/RestoreResturant.cpp)