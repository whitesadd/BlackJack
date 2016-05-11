/*
 * GameTest.cpp
 *
 *  Created on: Apr 17, 2016
 *      Author: david
 */

#include "Game.h"
#include "DecksStub.h"
#include "UserInputMock.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::AtLeast;

class GameTest : public ::testing::Test {

protected:
    virtual void SetUp() {
        cards_p = new(std::vector<Card*>);
    }

    virtual void TearDown() {
        delete cards_p;
    }

    std::vector<Card*>* cards_p;
};

TEST_F(GameTest, CheckDealUntilLimitWithoutAce) {
    cards_p->push_back(new Card(Card::TWO, Card::SPADES));
    cards_p->push_back(new Card(Card::SIX, Card::CLUBS));
    cards_p->push_back(new Card(Card::KING, Card::HEARTS));
    cards_p->push_back(new Card(Card::SEVEN, Card::DIAMONDS));
    Game game(new DecksStub(cards_p));
    game.dealCardToPlayerUntilValue(18);
    ASSERT_EQ(1, game._playersHand.getValues()->size());
    ASSERT_EQ(18, game._playersHand.getValues()->front());
    ASSERT_EQ(1, game._deck_p->size());
}

TEST_F(GameTest, CheckDealUntilLimitWithAce) {
    cards_p->push_back(new Card(Card::ACE, Card::SPADES));
    cards_p->push_back(new Card(Card::KING, Card::CLUBS));
    cards_p->push_back(new Card(Card::KING, Card::HEARTS));
    cards_p->push_back(new Card(Card::SEVEN, Card::DIAMONDS));
    Game game(new DecksStub(cards_p));
    game.dealCardToPlayerUntilValue(18);
    ASSERT_EQ(2, game._playersHand.getValues()->size());
    ASSERT_EQ(11, game._playersHand.getValues()->front());
    ASSERT_EQ(21, game._playersHand.getValues()->back());
    ASSERT_EQ(2, game._deck_p->size());
}

// Test Game with stubbed decks
TEST_F(GameTest, TestGameNoAcesHouseWins) {
    cards_p->push_back(new Card(Card::TWO, Card::SPADES)); // card to Player, 2
    cards_p->push_back(new Card(Card::JACK, Card::CLUBS)); // card to Dealer, 10
    cards_p->push_back(new Card(Card::KING, Card::HEARTS)); // card to Player, 12
    cards_p->push_back(new Card(Card::SEVEN, Card::DIAMONDS)); // card to Dealer, 17.
    // Player ask Deal card
    cards_p->push_back(new Card(Card::THREE, Card::DIAMONDS)); // card to Player, 15
    // Player ask Deal card
    cards_p->push_back(new Card(Card::THREE, Card::CLUBS)); // card to Player, 18, Stop. Player Wins!!
    // Player ask Hold
    cards_p->push_back(new Card(Card::FOUR, Card::SPADES)); // Not used

    UserInputMock userInputMock;
    Game game(new DecksStub(cards_p), &userInputMock);

    game.run();
    ASSERT_EQ(game.houseWins(), false);
    ASSERT_EQ(game.playerWins(), true);
}

// Test Game with stubbed decks
TEST_F(GameTest, TestGameNoAcesPlayerWins) {
    cards_p->push_back(new Card(Card::TWO, Card::SPADES)); // card to Player, 2
    cards_p->push_back(new Card(Card::JACK, Card::CLUBS)); // card to Dealer, 10
    cards_p->push_back(new Card(Card::KING, Card::HEARTS)); // card to Player, 12
    cards_p->push_back(new Card(Card::SEVEN, Card::DIAMONDS)); // card to Dealer, 17, Stop.
    cards_p->push_back(new Card(Card::THREE, Card::DIAMONDS)); // card to Player, 15
    cards_p->push_back(new Card(Card::NINE, Card::CLUBS)); // card to Player, 24, Busted! House Wins.
    cards_p->push_back(new Card(Card::QUEEN, Card::SPADES)); // Not used
    Game game(new DecksStub(cards_p));
    game.run();
    ASSERT_EQ(game.houseWins(), true);
    ASSERT_EQ(game.playerWins(), false);
}
