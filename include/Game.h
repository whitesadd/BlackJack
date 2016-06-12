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
#include "UserInterface.h"

class Game {
public:
    Game();
    Game(Decks*);
    Game(Decks*, UserInterface*);
    virtual ~Game();
    void run();
    bool houseWins();
    bool playerWins();

    static const unsigned int PLAYER_STOP_VALUE = 18;
    static const unsigned int DEALER_STOP_VALUE = 17;

private:

    FRIEND_TEST(GameTest, CheckDealUntilLimitWithoutAce);
    FRIEND_TEST(GameTest, CheckDealUntilLimitWithAce);
    FRIEND_TEST(GameTest, TestGameNoAcesPlayerWins);
    FRIEND_TEST(GameTest, TestGameNoAcesHouseWins);

    Decks* _deck_p;
    UserInterface* _userInterface_p;
    Hand _dealersHand;
    std::vector<Hand> _playersHands;

    void dealCardToPlayer(int playerId, bool facingUp = Card::FACING_UP);
    void dealCardToDealer(bool facingUp = Card::FACING_UP);
    void dealCardToPlayerUntilValue(unsigned short limit);
    void dealCardToDealerUntilValue(unsigned short limit);
    void dealCardUntilValue(Hand* hand_p, unsigned short limit);
    void dealCard(Hand* hand_p, bool facingUp = Card::FACING_UP);
    void printGame();
    void printWinner();
};

#endif /* GAME_H_ */
