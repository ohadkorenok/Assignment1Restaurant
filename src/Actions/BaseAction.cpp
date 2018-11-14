//
// Created by nitzan on 10/11/18.
//
#include "../../include/Action.h"
#include "../../include/Restaurant.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
BaseAction::BaseAction() : errorMsg("") {status=PENDING;}
ActionStatus BaseAction::getStatus() const {return status;}
std::string BaseAction::getErrorMsg() const {return errorMsg;}
void BaseAction::complete() {status=COMPLETED;}
void BaseAction::error(std::string errorMsg) {status=ERROR;this->errorMsg=errorMsg;}



