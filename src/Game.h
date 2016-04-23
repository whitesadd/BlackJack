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
#include "gtest/gtest.h"

using namespace std;

class Game {
public:
    Game();
    Game(Decks*);
    virtual ~Game();
    void run();

private:

    FRIEND_TEST(GameTest, CheckDealUntilSoftLimitWithoutAce);
    FRIEND_TEST(GameTest, CheckDealUntilSoftLimitWithAce);

    Decks* _deck_p;
    Hand _dealersHand;
    Hand _playersHand;

    void dealCardToPlayer(bool facingUp = Card::FACING_UP);
    void dealCardToDealer(bool facingUp = Card::FACING_UP);
    void dealCardToPlayerUntilSoft(unsigned short limit);
    void dealCardToDealerUntilSoft(unsigned short limit);
    void dealCardUntilSoft(Hand* hand_p, unsigned short limit);
    void dealCard(Hand* hand_p, bool facingUp = Card::FACING_UP);
    void printGame();
};

#endif /* GAME_H_ */
