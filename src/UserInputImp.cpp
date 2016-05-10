/*
 * UserInputImp.cpp
 *
 *  Created on: May 10, 2016
 *      Author: david
 */

#include <iostream>
#include "UserInput.h"


class UserInputImp : public UserInput {

public:
    ~UserInputImp() {}

    char getPlayerMove() {
        char move;
        std::cin >> move;
        return move;
    };
};
