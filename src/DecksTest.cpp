/*
 * DecksTest.cpp
 *
 *  Created on: Apr 11, 2016
 *      Author: david
 */

#include "DecksImp.h"
#include "DecksStub.h"
#include "gtest/gtest.h"


// Decks creation and destruction
TEST(DecksTest, CreateAndDestroyDecks) {
    Decks* decks_p = new DecksImp(4);
    delete decks_p;
}


// Test size()
TEST(DecksTest, CheckSize) {
    Decks* emptyDeck_p = new DecksImp();
    ASSERT_EQ(0, emptyDeck_p->size());
    delete emptyDeck_p;

    Decks* fourDecks_p = new DecksImp(4);
    ASSERT_EQ(208, emptyDeck_p->size());
    delete fourDecks_p;
}

// Test drawCard()
TEST(DecksTest, CheckDrawCardFromFourDecks) {
    Decks* decks_p = new DecksImp(4);

    for (int i = 0; i < 52 * 4; i++) {
        Card* card_p = decks_p->drawCard();
        ASSERT_EQ(52 * 4 - i - 1, decks_p->size());
        delete card_p;
    }

    ASSERT_EQ(NULL, decks_p->drawCard()) << "Drawing card from empty "
            "deck does not return NULL";
    delete decks_p;
}
