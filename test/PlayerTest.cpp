/*
 * PlayerTest.cpp
 *
 *  Created on: Jun 5, 2016
 *      Author: david
 */

#include "gtest/gtest.h"
#include "Player.h"
#include "Hand.h"

TEST(PlayerTest, CheckSplit) {
    Player player;
    ASSERT_EQ(1, player.getNoOfHands());
    std::list<Hand>::iterator it;
    it = player.hands.begin();
    it->addCard(new Card(Card::KING, Card::DIAMONDS));
    it->addCard(new Card(Card::JACK, Card::CLUBS));
    ASSERT_TRUE(it->isPair());

    player.splitHand(it,
            new Card(Card::SEVEN, Card::DIAMONDS),
            new Card(Card::TEN, Card::HEARTS));
    ASSERT_EQ(2, player.getNoOfHands());

    it = player.hands.begin();
    ASSERT_FALSE(it->isBusted());
    ASSERT_EQ(17, it->getValue());
    ASSERT_FALSE(it->isPair());

    it++;
    ASSERT_FALSE(it->isBusted());
    ASSERT_EQ(20, it->getValue());
    ASSERT_TRUE(it->isPair());
}
