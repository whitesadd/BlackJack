/*
 * UserInterface.h
 *
 *  Created on: May 10, 2016
 *      Author: david
 */

#ifndef USERINTERFACE_H_
#define USERINTERFACE_H_

class UserInterface {
public:
    virtual ~UserInterface() {}
    virtual char getPlayerMove() = 0;
};

#endif /* USERINTERFACE_H_ */
