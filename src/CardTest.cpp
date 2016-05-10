/*
 * CardTest.cpp
 *
 *  Created on: Apr 10, 2016
 *      Author: david
 */

#include <iostream>
#include "Card.h"
#include "gtest/gtest.h"

// Basic card creation and destruction
TEST(CardTest, CreateAndDestroyCard) {
    Card card = Card(Card::ACE, Card::SPADES);
    Card* card_p = new Card(Card::ACE, Card::SPADES);
    delete card_p;
}

// Test values for cards
TEST(CardTest, GetValueForFaceCard) {
    ASSERT_EQ(10, Card(Card::KING, Card::SPADES).getValues().firstValue);
    ASSERT_EQ(7, Card(Card::SEVEN, Card::CLUBS).getValues().firstValue);
    ASSERT_EQ(1, Card(Card::ACE, Card::CLUBS).getValues().firstValue);
    ASSERT_EQ(11, Card(Card::ACE, Card::CLUBS).getValues().secondValue);
}

TEST(CardTest, DumpUnicodeDeck) {
    std::cout << std::endl;

    for (Suit suit = Card::FIRST_SUIT; suit <= Card::LAST_SUIT; suit++) {
        for (Rank rank = Card::FIRST_RANK; rank <= Card::LAST_RANK; rank++) {
            std::cout << Card(rank, suit, Card::FACING_UP).getUnicodeString() << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

TEST(CardTest, ManipulateCardFacingUp) {
    Card cardFacingUp(Card::ACE, Card::SPADES);
    ASSERT_EQ(1, cardFacingUp.getValues().firstValue);
    ASSERT_EQ(11, cardFacingUp.getValues().secondValue);
}

TEST(CardTest, ManipulateCard) {
    Card card(Card::ACE, Card::SPADES, Card::FACING_DOWN);
    ASSERT_FALSE(card.isFacingUp());
    ASSERT_EQ(1, card.getValues().firstValue);
    ASSERT_EQ(11, card.getValues().secondValue);
    ASSERT_EQ(0, card.getUnicodeString().compare("\u0020\u003F\u003F"));
    card.flip();
    ASSERT_TRUE(card.isFacingUp());
    ASSERT_EQ(1, card.getValues().firstValue);
    ASSERT_EQ(11, card.getValues().secondValue);
    ASSERT_EQ(0, card.getUnicodeString().compare("\u0020\u0041\u2660"));
}
