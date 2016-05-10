/*
 * UserInput.h
 *
 *  Created on: May 10, 2016
 *      Author: david
 */

#ifndef USERINPUT_H_
#define USERINPUT_H_

class UserInput {
public:
    virtual ~UserInput();
    virtual char getPlayerMove() = 0;
};

#endif /* USERINPUT_H_ */
