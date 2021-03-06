/*
 * HandTest.cpp
 *
 *  Created on: Apr 17, 2016
 *      Author: david
 */

#include "gtest/gtest.h"
#include "Hand.h"
#include "Card.h"


TEST(HandTest, TestCopyConstruct) {
    Hand originalHand;
    originalHand.addCard(new Card(Card::ACE, Card::SPADES));
    originalHand.addCard(new Card(Card::JACK, Card::CLUBS));
    Hand copyHand = originalHand;
    ASSERT_EQ(0, originalHand.getUnicode().compare(copyHand.getUnicode()));
}

TEST(HandTest, AddCardToHand) {
    Hand hand;
    ASSERT_EQ(0, hand.getUnicode().compare(""));
    Card* firstCard_p = new Card(Card::ACE, Card::SPADES, Card::FACING_UP);
    hand.addCard(firstCard_p);
    ASSERT_EQ(1, hand.size());
    ASSERT_EQ(0, hand.getUnicode().compare(UNICODE_ACE_STR UNICODE_SPADES_STR));
    ASSERT_FALSE(hand.isPair());
    Card* secondCard_p = new Card(Card::ACE, Card::SPADES, Card::FACING_DOWN);
    hand.addCard(secondCard_p);
    ASSERT_EQ(2, hand.size());
    ASSERT_EQ(0, hand.getUnicode().compare(UNICODE_ACE_STR UNICODE_SPADES_STR UNICODE_SPACE_STR
                                           UNICODE_QUESTION_STR));
    ASSERT_TRUE(hand.isPair());
    Card* thirdCard_p = new Card(Card::TEN, Card::CLUBS, Card::FACING_UP);
    hand.addCard(thirdCard_p);
    ASSERT_EQ(3, hand.size());
    ASSERT_EQ(0, hand.getUnicode().compare(UNICODE_ACE_STR UNICODE_SPADES_STR UNICODE_SPACE_STR
                                           UNICODE_QUESTION_STR UNICODE_SPACE_STR
                                           UNICODE_TEN_STR UNICODE_CLUBS_STR));
    ASSERT_FALSE(hand.isPair());
    hand.reveal();
    ASSERT_EQ(3, hand.size());
    ASSERT_EQ(0, hand.getUnicode().compare(UNICODE_ACE_STR UNICODE_SPADES_STR UNICODE_SPACE_STR
                                           UNICODE_ACE_STR UNICODE_SPADES_STR UNICODE_SPACE_STR
                                           UNICODE_TEN_STR UNICODE_CLUBS_STR));
    delete firstCard_p;
    delete secondCard_p;
    delete thirdCard_p;
}

TEST(HandTest, EvalSingleHandValues) {
    Hand hand;
    std::list<unsigned short> const * handValues_p;
    handValues_p = hand.getValues();
    ASSERT_EQ(1, handValues_p->size());
    ASSERT_EQ(0, handValues_p->front());
    ASSERT_FALSE(hand.isPair());
    hand.addCard(new Card(Card::TEN, Card::CLUBS));
    handValues_p = hand.getValues();
    ASSERT_EQ(1, handValues_p->size());
    ASSERT_EQ(10, handValues_p->front());
    hand.addCard(new Card(Card::TEN, Card::CLUBS));
    handValues_p = hand.getValues();
    ASSERT_EQ(1, handValues_p->size());
    ASSERT_EQ(20, handValues_p->front());
    ASSERT_TRUE(hand.isPair());
    hand.addCard(new Card(Card::TEN, Card::CLUBS));
    handValues_p = hand.getValues();
    ASSERT_EQ(1, handValues_p->size());
    ASSERT_EQ(30, handValues_p->front());
    ASSERT_FALSE(hand.isPair());
}


TEST(HandTest, EvalDoubleAceValues) {
    Hand hand;
    std::list<unsigned short> const * handValues_p;
    std::list<unsigned short>::const_iterator it;

    handValues_p = hand.getValues();
    ASSERT_EQ(1, handValues_p->size());
    ASSERT_EQ(0, handValues_p->front());

    hand.addCard(new Card(Card::ACE, Card::CLUBS));
    handValues_p = hand.getValues();
    ASSERT_EQ(2, handValues_p->size());
    ASSERT_EQ(1, handValues_p->front());
    ASSERT_EQ(11, handValues_p->back());

    hand.addCard(new Card(Card::ACE, Card::CLUBS));
    handValues_p = hand.getValues();
    ASSERT_EQ(3, handValues_p->size());
    it = handValues_p->begin();
    ASSERT_EQ(2, *it);
    it++;
    ASSERT_EQ(12, *it);
    it++;
    ASSERT_EQ(22, *it);
}

TEST(HandTest, CheckBustedAndValueWithoutAce) {
    Hand hand;
    hand.addCard(new Card(Card::TWO, Card::CLUBS));
    ASSERT_FALSE(hand.isBusted());
    ASSERT_EQ(2, hand.getValue());
    ASSERT_FALSE(hand.isPair());
    hand.addCard(new Card(Card::KING, Card::DIAMONDS));
    ASSERT_FALSE(hand.isBusted());
    ASSERT_EQ(12, hand.getValue());
    ASSERT_FALSE(hand.isPair());
    hand.addCard(new Card(Card::SEVEN, Card::DIAMONDS));
    ASSERT_FALSE(hand.isBusted());
    ASSERT_EQ(19, hand.getValue());
    ASSERT_FALSE(hand.isPair());
    hand.addCard(new Card(Card::FOUR, Card::SPADES));
    ASSERT_TRUE(hand.isBusted());
    ASSERT_EQ(23, hand.getValue());
    ASSERT_FALSE(hand.isPair());
}

TEST(HandTest, CheckBustedAndValueWithtAce) {
    Hand hand;
    hand.addCard(new Card(Card::ACE, Card::CLUBS));
    ASSERT_FALSE(hand.isBusted());
    ASSERT_EQ(11, hand.getValue());
    ASSERT_FALSE(hand.isPair());
    hand.addCard(new Card(Card::KING, Card::DIAMONDS));
    ASSERT_FALSE(hand.isBusted());
    ASSERT_EQ(21, hand.getValue());
    ASSERT_FALSE(hand.isPair());
    hand.addCard(new Card(Card::SEVEN, Card::DIAMONDS));
    ASSERT_FALSE(hand.isBusted());
    ASSERT_EQ(18, hand.getValue());
    ASSERT_FALSE(hand.isPair());
    hand.addCard(new Card(Card::FOUR, Card::SPADES));
    ASSERT_TRUE(hand.isBusted());
    ASSERT_EQ(22, hand.getValue());
    ASSERT_FALSE(hand.isPair());
}
