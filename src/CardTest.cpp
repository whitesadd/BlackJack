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

    static std::string const unicodeDeckDump =
           "\u0020\u0041\u2660\u0020\u0020\u0041\u2665\u0020\u0020\u0041\u2666\u0020\u0020\u0041\u2663\u0020\u000A"
           "\u0020\u0032\u2660\u0020\u0020\u0032\u2665\u0020\u0020\u0032\u2666\u0020\u0020\u0032\u2663\u0020\u000A"
           "\u0020\u0033\u2660\u0020\u0020\u0033\u2665\u0020\u0020\u0033\u2666\u0020\u0020\u0033\u2663\u0020\u000A"
           "\u0020\u0034\u2660\u0020\u0020\u0034\u2665\u0020\u0020\u0034\u2666\u0020\u0020\u0034\u2663\u0020\u000A"
           "\u0020\u0035\u2660\u0020\u0020\u0035\u2665\u0020\u0020\u0035\u2666\u0020\u0020\u0035\u2663\u0020\u000A"
           "\u0020\u0036\u2660\u0020\u0020\u0036\u2665\u0020\u0020\u0036\u2666\u0020\u0020\u0036\u2663\u0020\u000A"
           "\u0020\u0037\u2660\u0020\u0020\u0037\u2665\u0020\u0020\u0037\u2666\u0020\u0020\u0037\u2663\u0020\u000A"
           "\u0020\u0038\u2660\u0020\u0020\u0038\u2665\u0020\u0020\u0038\u2666\u0020\u0020\u0038\u2663\u0020\u000A"
           "\u0020\u0039\u2660\u0020\u0020\u0039\u2665\u0020\u0020\u0039\u2666\u0020\u0020\u0039\u2663\u0020\u000A"
           "\u0031\u0030\u2660\u0020\u0031\u0030\u2665\u0020\u0031\u0030\u2666\u0020\u0031\u0030\u2663\u0020\u000A"
           "\u0020\u004A\u2660\u0020\u0020\u004A\u2665\u0020\u0020\u004A\u2666\u0020\u0020\u004A\u2663\u0020\u000A"
           "\u0020\u0051\u2660\u0020\u0020\u0051\u2665\u0020\u0020\u0051\u2666\u0020\u0020\u0051\u2663\u0020\u000A"
           "\u0020\u004B\u2660\u0020\u0020\u004B\u2665\u0020\u0020\u004B\u2666\u0020\u0020\u004B\u2663\u0020\u000A";

    std::stringbuf sb;
    std::ostream outTest(&sb);
    for (Rank rank = Card::FIRST_RANK; rank <= Card::LAST_RANK; rank++) {
        for (Suit suit = Card::FIRST_SUIT; suit <= Card::LAST_SUIT; suit++) {
            outTest << Card(rank, suit, Card::FACING_UP).getUnicodeString() << " ";
        }
        outTest << std::endl;
    }
    ASSERT_EQ(0, unicodeDeckDump.compare(sb.str()));
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
