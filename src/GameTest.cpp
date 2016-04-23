/*
 * GameTest.cpp
 *
 *  Created on: Apr 17, 2016
 *      Author: david
 */

#include "Game.h"
#include "DecksStub.h"
#include "gtest/gtest.h"

using namespace std;

// Test Game with stubbed decks
TEST(GameTest, TestGameWithStubbedDeck) {
    vector<Card*>* cards_p = new(vector<Card*>);
    cards_p->push_back(new Card(Card::ACE, Card::SPADES));
    cards_p->push_back(new Card(Card::JACK, Card::CLUBS));
    cards_p->push_back(new Card(Card::KING, Card::HEARTS));
    cards_p->push_back(new Card(Card::SEVEN, Card::DIAMONDS));
    Decks* deck_p = new DecksStub(cards_p);
    Game game(deck_p);
    game.run();
    delete deck_p;
    delete cards_p;
}

