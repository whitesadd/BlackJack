/*
 * UserInputImp.h
 *
 *  Created on: 11 maj 2016
 *      Author: ebladav
 */

#ifndef USERINPUTIMP_H_
#define USERINPUTIMP_H_

#include "UserInput.h"

class UserInputImp : public UserInput {
public:
    virtual ~UserInputImp();
    char getPlayerMove();
};

#endif /* USERINPUTIMP_H_ */
