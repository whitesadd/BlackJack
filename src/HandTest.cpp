/*
 * HandTest.cpp
 *
 *  Created on: Apr 17, 2016
 *      Author: david
 */

#include "gtest/gtest.h"
#include "Hand.h"
#include "Card.h"

using namespace std;

TEST(HandTest, AddCardToHand) {
    Hand hand;
    ASSERT_EQ(0, hand.getUnicode().compare(""));
    Card* firstCard_p = new Card(Card::ACE, Card::SPADES, Card::FACING_UP);
    hand.addCard(firstCard_p);
    ASSERT_EQ(1, hand.size());
    ASSERT_EQ(0, hand.getUnicode().compare("\u0020\u0041\u2660"));
    Card* secondCard_p = new Card(Card::ACE, Card::SPADES, Card::FACING_DOWN);
    hand.addCard(secondCard_p);
    ASSERT_EQ(2, hand.size());
    ASSERT_EQ(0, hand.getUnicode().compare("\u0020\u0041\u2660\u0020\u0020\u003F\u003F"));
    Card* thirdCard_p = new Card(Card::TEN, Card::CLUBS, Card::FACING_UP);
    hand.addCard(thirdCard_p);
    ASSERT_EQ(3, hand.size());
    ASSERT_EQ(0, hand.getUnicode().compare("\u0020\u0041\u2660\u0020\u0020\u003F\u003F\u0020\u0031\u0030\u2663"));
    cout << endl << "Hand: " << hand.getUnicode() << endl << endl;
    delete firstCard_p;
    delete secondCard_p;
    delete thirdCard_p;
}

TEST(HandTest, EvalHandValues) {
    Hand hand;
    list<unsigned short> const * handValues_p;
    handValues_p = hand.getValues();
    ASSERT_EQ(1, handValues_p->size());
    ASSERT_EQ(0, handValues_p->front());
    hand.addCard(new Card(Card::TEN, Card::CLUBS));
    handValues_p = hand.getValues();
    ASSERT_EQ(1, handValues_p->size());
    ASSERT_EQ(10, handValues_p->front());
    hand.addCard(new Card(Card::TEN, Card::CLUBS));
    handValues_p = hand.getValues();
    ASSERT_EQ(1, handValues_p->size());
    ASSERT_EQ(20, handValues_p->front());
    hand.addCard(new Card(Card::TEN, Card::CLUBS));
    handValues_p = hand.getValues();
    ASSERT_EQ(1, handValues_p->size());
    ASSERT_EQ(30, handValues_p->front());
    hand.addCard(new Card(Card::ACE, Card::CLUBS));
    handValues_p = hand.getValues();
    ASSERT_EQ(2, handValues_p->size());
    ASSERT_EQ(31, handValues_p->front());
}

