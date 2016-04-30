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
    bool houseWins();
    bool playerWins();

private:

    FRIEND_TEST(GameTest, CheckDealUntilLimitWithoutAce);
    FRIEND_TEST(GameTest, CheckDealUntilLimitWithAce);
    FRIEND_TEST(GameTest, TestGameNoAcesPlayerWins);
    FRIEND_TEST(GameTest, TestGameNoAcesHouseWins);

    Decks* _deck_p;
    Hand _dealersHand;
    Hand _playersHand;

    void dealCardToPlayer(bool facingUp = Card::FACING_UP);
    void dealCardToDealer(bool facingUp = Card::FACING_UP);
    void dealCardToPlayerUntilValue(unsigned short limit);
    void dealCardToDealerUntilValue(unsigned short limit);
    void dealCardUntilValue(Hand* hand_p, unsigned short limit);
    void dealCard(Hand* hand_p, bool facingUp = Card::FACING_UP);
    void revealDealersHand();
    void printGame();
};

#endif /* GAME_H_ */
