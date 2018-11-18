#!/bin/bash
clear
echo "BASH COMPILE STARTED"
rm -rf bin/*
echo "deleted bin! "
make
valgrind --leak-check=full --show-reachable=yes ./bin/rest config/config2.txt < config/input_example2.txt > config/ohadOutput.txt
 
