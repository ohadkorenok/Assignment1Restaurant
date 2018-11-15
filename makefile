# All Targets
all: rest

# Tool invocations
# Executable "rest" depends on the files rest.o
rest: bin/AlchoholicCustomer.o bin/BackupRestaurant.o bin/BaseAction.o bin/CheapCustomer.o bin/Close.o bin/CloseAll.o bin/Customer.o bin/Dish.o bin/main.o bin/MoveCustomer.o bin/OpenTable.o bin/Order.o bin/PrintActionsLog.o bin/PrintMenu.o bin/PrintTableStatus.o bin/Restaurant.o bin/RestoreResturant.o bin/SpicyCustomer.o bin/Table.o bin/VegeterianCustomer.o bin/Parser.o
	@echo 'Building target: rest'
	@echo 'Invoking: C++ Linker'
	g++ -o bin/rest bin/AlchoholicCustomer.o bin/BackupRestaurant.o bin/BaseAction.o bin/CheapCustomer.o bin/Close.o bin/CloseAll.o bin/Customer.o bin/Dish.o bin/main.o bin/MoveCustomer.o bin/OpenTable.o bin/Order.o bin/PrintActionsLog.o bin/PrintMenu.o bin/PrintTableStatus.o bin/Restaurant.o bin/RestoreResturant.o bin/SpicyCustomer.o bin/Table.o bin/VegeterianCustomer.o bin/Parser.o
	@echo 'Finished building target: rest'
	@echo ' '

# Depends on the source and header files
bin/AlchoholicCustomer.o: src/AlchoholicCustomer.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/AlchoholicCustomer.o src/AlchoholicCustomer.cpp

# Depends on the source and header files 
bin/BackupRestaurant.o: src/BackupRestaurant.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/BackupRestaurant.o src/BackupRestaurant.cpp

# Depends on the source and header files 
bin/BaseAction.o: src/BaseAction.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/BaseAction.o src/BaseAction.cpp

# Depends on the source and header files 
bin/CheapCustomer.o: src/CheapCustomer.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/CheapCustomer.o src/CheapCustomer.cpp

# Depends on the source and header files 
bin/Close.o: src/Close.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/Close.o src/Close.cpp

# Depends on the source and header files 
bin/CloseAll.o: src/CloseAll.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/CloseAll.o src/CloseAll.cpp

# Depends on the source and header files 
bin/Customer.o: src/Customer.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/Customer.o src/Customer.cpp

# Depends on the source and header files 
bin/Dish.o: src/Dish.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/Dish.o src/Dish.cpp

# Depends on the source and header files 
bin/main.o: src/main.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/main.o src/main.cpp

# Depends on the source and header files 
bin/MoveCustomer.o: src/MoveCustomer.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/MoveCustomer.o src/MoveCustomer.cpp

# Depends on the source and header files 
bin/OpenTable.o: src/OpenTable.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/OpenTable.o src/OpenTable.cpp

# Depends on the source and header files 
bin/Order.o: src/Order.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/Order.o src/Order.cpp

# Depends on the source and header files 
bin/PrintActionsLog.o: src/PrintActionsLog.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/PrintActionsLog.o src/PrintActionsLog.cpp

# Depends on the source and header files 
bin/PrintMenu.o: src/PrintMenu.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/PrintMenu.o src/PrintMenu.cpp

# Depends on the source and header files 
bin/PrintTableStatus.o: src/PrintTableStatus.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/PrintTableStatus.o src/PrintTableStatus.cpp

# Depends on the source and header files 
bin/Restaurant.o: src/Restaurant.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/Restaurant.o src/Restaurant.cpp

# Depends on the source and header files 
bin/RestoreResturant.o: src/RestoreResturant.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/RestoreResturant.o src/RestoreResturant.cpp

# Depends on the source and header files 
bin/SpicyCustomer.o: src/SpicyCustomer.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/SpicyCustomer.o src/SpicyCustomer.cpp

# Depends on the source and header files 
bin/Table.o: src/Table.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/Table.o src/Table.cpp

# Depends on the source and header files
bin/Parser.o: src/Parser.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/Parser.o src/Parser.cpp

# Depends on the source and header files 
bin/VegeterianCustomer.o: src/VegeterianCustomer.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/VegeterianCustomer.o src/VegeterianCustomer.cpp

#Clean the build directory
clean: 
	rm -f bin/*
