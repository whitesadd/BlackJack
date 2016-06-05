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
    Hand* hand_p = new Hand;
    hands.push_front(*hand_p);
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

    Hand* hand_p;

    hand_p = new Hand;
    hand_p->addCard((*it)[0]);
    hand_p->addCard(card0_p);
    hands.insert(it, *hand_p);

    hand_p = new Hand;
    hand_p->addCard((*it)[1]);
    hand_p->addCard(card1_p);
    hands.insert(it, *hand_p);

    hands.erase(it);
}
