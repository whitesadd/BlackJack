/*
 * Decks.cpp
 *
 *  Created on: Apr 11, 2016
 *      Author: david
 */

#include <iostream>
#include <cstdlib>
#include "Decks.h"

using namespace std;

Decks::Decks(int noOfDecks) {
    srand(time(NULL));
    int i = 1;
    for (int deck = 0; deck < noOfDecks; deck++) {
        for (Suit suit = Card::FIRST_SUIT; suit <= Card::LAST_SUIT; suit++) {
            for (Rank rank = Card::FIRST_RANK; rank <= Card::LAST_RANK; rank++) {
                int offset = rand() % i;
                stack.insert(stack.begin() + offset, new Card(rank, suit));
                i++;
            }
        }
    }
}


Decks::~Decks() {
    while (!stack.empty()) {
        delete stack.back();
        stack.pop_back();
    }
}

unsigned int Decks::size() {
    return stack.size();
}

Card* Decks::drawCard() {
    if (stack.empty()) {
        return NULL;
    }
    Card* card_p = stack.back();
    stack.pop_back();
    return card_p;
}
