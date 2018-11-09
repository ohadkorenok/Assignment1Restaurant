cmake_minimum_required(VERSION 3.12)
project(Assignment1Restaurant)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment1Restaurant main.cpp src/Dishes/Dish.cpp src/Customers/Customer.cpp src/Customers/VegeterianCustomer.cpp src/Restaurant.cpp src/Customers/CheapCustomer.cpp src/Customers/SpicyCustomer.cpp src/Customers/AlchoholicCustomer.cpp)