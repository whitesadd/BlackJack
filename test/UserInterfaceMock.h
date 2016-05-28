/*
 * UserInterfaceMock.h
 *
 *  Created on: 11 maj 2016
 *      Author: ebladav
 */

#ifndef USERINTERFACEMOCK_H_
#define USERINTERFACEMOCK_H_

#include "gmock/gmock.h"
#include "UserInterface.h"

class UserInterfaceMock : public UserInterface {
public:
    MOCK_METHOD0(getPlayerMove, char());
};

#endif /* USERINTERFACEMOCK_H_ */
