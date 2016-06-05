/*
 * PlayerTest.cpp
 *
 *  Created on: Jun 5, 2016
 *      Author: david
 */

#include "gtest/gtest.h"
#include "Player.h"
#include "Hand.h"

TEST(PlayerTest, CreatePlayer) {
    Player player;
    ASSERT_EQ(1, player.getNoOfHands());
}

TEST(PlayerTest, CheckSplit) {
    Player player;
    ASSERT_EQ(1, player.getNoOfHands());
    std::list<Hand>::iterator it = player.hands.begin();
    it->addCard(new Card(Card::KING, Card::DIAMONDS));
    it->addCard(new Card(Card::JACK, Card::CLUBS));
    ASSERT_TRUE(it->isPair());
}
