/*
 * Player.cpp
 *
 *  Created on: Jun 5, 2016
 *      Author: david
 */

#include "Player.h"
#include <iostream>

Player::Player() {
    Hand* hand_p = new Hand;
    hands.push_front(*hand_p);
}

Player::~Player() {
}


int Player::getNoOfHands() {
    return hands.size();
}
