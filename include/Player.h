/*
 * Player.h
 *
 *  Created on: Jun 5, 2016
 *      Author: david
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <list>
#include "Hand.h"

class Player {
public:
    Player();
    virtual ~Player();
    int getNoOfHands();
    void splitHand(std::list<Hand>::iterator& it,
                   Card* card0_p,
                   Card* card1_p);

    std::list<Hand> hands;
};

#endif /* PLAYER_H_ */
