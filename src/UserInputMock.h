/*
 * UserInputMock.h
 *
 *  Created on: 11 maj 2016
 *      Author: ebladav
 */

#ifndef USERINPUTMOCK_H_
#define USERINPUTMOCK_H_

#include "gmock/gmock.h"
#include "UserInput.h"

class UserInputMock : public UserInput {
public:
    MOCK_METHOD0(getPlayerMove, char());
};

#endif /* USERINPUTMOCK_H_ */
