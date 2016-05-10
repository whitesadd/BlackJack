/*
 * Decks.cpp
 *
 *  Created on: Apr 11, 2016
 *      Author: david
 */

#include <iostream>
#include "Decks.h"

Decks::Decks() : _stack(0) {}

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
    Card* card_p = _stack.front();
    _stack.erase(_stack.begin());
    return card_p;
}
