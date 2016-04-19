/*
 * DecksTest.cpp
 *
 *  Created on: Apr 11, 2016
 *      Author: david
 */

#include "Decks.h"
#include "gtest/gtest.h"

using namespace std;

// Decks creation and destruction
TEST(DecksTest, CreateAndDestroyDecks) {
    Decks decks = Decks(1);
    Decks* decks_p = new Decks(1);
    delete decks_p;
}

// Test size()
TEST(DecksTest, CheckSize) {
    ASSERT_EQ(0, Decks(0).size());
    ASSERT_EQ(520, Decks(10).size());
}

// Test drawCard()
TEST(DecksTest, CheckDrawCardFromFoureDecks) {
    Decks decks = Decks(4);
    cout << endl;
    for (int i = 0; i < 52 * 4; i++) {
        Card* card_p = decks.drawCard();
        ASSERT_EQ(52 * 4 - i - 1, decks.size());
        cout << card_p->getUnicodeString() << " ";
        if (i % 26 == 25) cout << endl;
        delete card_p;
    }
    cout << endl;
    ASSERT_EQ(NULL, decks.drawCard()) << "Drawing card from empty "
            "deck does not return NULL";
}

