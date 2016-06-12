/*
 * Player.cpp
 *
 *  Created on: Jun 5, 2016
 *      Author: david
 */

#include "Player.h"
#include <iostream>
#include <cassert>

Player::Player() {
    hands.push_front(Hand());
}

Player::~Player() {
}


int Player::getNoOfHands() {
    return hands.size();
}

void Player::splitHand(std::list<Hand>::iterator& it,
        Card* card0_p,
        Card* card1_p) {

    assert(it->isPair());

    // Create new hand #0,...
    Hand hand0;
    hand0.addCard((*it)[0]);
    hand0.addCard(card0_p);
    hands.insert(it, hand0);

    // ...new hand #1,...
    Hand hand1;
    hand1.addCard((*it)[1]);
    hand1.addCard(card1_p);
    hands.insert(it, hand1);

    // ...and get rid of the old one.
    hands.erase(it);
}
