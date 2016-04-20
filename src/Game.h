/*
 * Game.h
 *
 *  Created on: Apr 17, 2016
 *      Author: david
 */

#ifndef GAME_H_
#define GAME_H_

#include "decks.h"
#include "Hand.h"

using namespace std;

class Game {
public:
    Game();
    Game(Decks*);
    virtual ~Game();
    void run();

private:

    Decks* _deck_p;
    Hand _dealersHand;
    Hand _playersHand;

    void dealCardToPlayer(bool facingUp = Card::FACING_UP);
    void dealCardToDealer(bool facingUp = Card::FACING_UP);
    void dealCard(Hand* hand_p, bool facingUp);
    void printGame();
};

#endif /* GAME_H_ */
