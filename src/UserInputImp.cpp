/*
 * UserInputImp.cpp
 *
 *  Created on: May 10, 2016
 *      Author: david
 */

#include <iostream>
#include "UserInputImp.h"

char UserInputImp::getPlayerMove() {
    char move;
    std::cin >> move;
    return move;
};

