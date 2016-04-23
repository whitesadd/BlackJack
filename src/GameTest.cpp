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

class GameTest : public ::testing::Test {

protected:
    virtual void SetUp() {
        cards_p = new(vector<Card*>);
    }

    virtual void TearDown() {
        delete cards_p;
    }

    vector<Card*>* cards_p;
};

// Test Game with stubbed decks
TEST_F(GameTest, TestGameWithStubbedDeck) {
    cards_p->push_back(new Card(Card::TWO, Card::SPADES)); // card to Player
    cards_p->push_back(new Card(Card::JACK, Card::CLUBS)); // card to Dealer
    cards_p->push_back(new Card(Card::KING, Card::HEARTS)); // card to Player
    cards_p->push_back(new Card(Card::SEVEN, Card::DIAMONDS)); // card to Dealer
    Game game(new DecksStub(cards_p));
    game.run();
}

/*
TEST_F(GameTest, CheckDealUntilSoftLimit) {
    cards_p->push_back(new Card(Card::TWO, Card::SPADES));
    cards_p->push_back(new Card(Card::SIX, Card::CLUBS));
    cards_p->push_back(new Card(Card::KING, Card::HEARTS));
    cards_p->push_back(new Card(Card::SEVEN, Card::DIAMONDS));
    Game game(new DecksStub(cards_p));
    game.dealCardToPlayerUntilSoft(18);
    ASSERT_EQ(1, game._dealersHand.getValues()->size());
    ASSERT_EQ(18, game._dealersHand.getValues()->front());
}
*/
