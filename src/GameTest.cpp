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
    Game game(new DecksStub(new vector<Card*>));
}

