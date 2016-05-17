/*
 * UserInterfaceImp.cpp
 *
 *  Created on: May 10, 2016
 *      Author: david
 */

#include "UserInterfaceImp.h"

#include <iostream>

char UserInterfaceImp::getPlayerMove() {
    char move;
    std::cin >> move;
    return move;
};

