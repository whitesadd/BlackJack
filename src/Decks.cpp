/*
 * Decks.cpp
 *
 *  Created on: Apr 11, 2016
 *      Author: david
 */

#include <iostream>
#include "Decks.h"

using namespace std;

Decks::Decks() {}

Decks::~Decks() {
    while (!_stack.empty()) {
        delete _stack.back();
        _stack.pop_back();
    }
}

unsigned int Decks::size() {
    return _stack.size();
}

Card* Decks::drawCard() {
    if (_stack.empty()) {
        return NULL;
    }
    Card* card_p = _stack.back();
    _stack.pop_back();
    return card_p;
}
