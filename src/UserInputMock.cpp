/*
 * UserInputMock.cpp
 *
 *  Created on: May 10, 2016
 *      Author: david
 */

#include "gmock/gmock.h"
#include "UserInput.h"

class UserInputMock : public UserInput {
public:
    MOCK_METHOD0(getPlayerMove, char());
};
