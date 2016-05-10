/*
 * Hand.cpp
 *
 *  Created on: Apr 17, 2016
 *      Author: david
 */

#include <string>
#include <iostream>
#include "Hand.h"

#define UNICODE_SPACE_STR        ("\u0020")

Hand::Hand() {
    _handValues_p = new list<unsigned short>(1,0);
}

Hand::~Hand() {
    delete _handValues_p;
}

void Hand::addCard(Card* card_p) {
    this->push_back(card_p);
    addCardValues(card_p);
}

void Hand::reveal() {
    Hand::iterator it = begin();
    while (it != end()) {
        if (!(*it)->isFacingUp()) {
            (*it)->flip();
        }
        it++;
    }
}


const string Hand::getUnicode() {
    string unicodeStr = "";
    if (size() == 0) return unicodeStr;

    Hand::iterator card_pp = begin();
    unicodeStr += (*card_pp)->getUnicodeString();
    card_pp++;
    while (card_pp != end()) {
        unicodeStr += UNICODE_SPACE_STR;
        unicodeStr += (*card_pp)->getUnicodeString();
        card_pp++;
    }
    return unicodeStr;
}

void Hand::addCardValues(Card* newCard_p) {
    unsigned short value1 = newCard_p->getValues().firstValue;
    unsigned short value2 = newCard_p->getValues().secondValue;
    list<unsigned short>::iterator it;

    it = _handValues_p->begin();
    while (it != _handValues_p->end()) {
        unsigned short tmpValue = *it;
        *it = tmpValue + value1;
        if (value2 != Card::NO_ALTERNATE_VALUE) {
            _handValues_p->insert(it, tmpValue + value2);
        }
        it++;
    }
    _handValues_p->sort();
    _handValues_p->unique();
}

list<unsigned short> const * Hand::getValues() {
    return _handValues_p;
}

bool Hand::isBusted() {
    return (_handValues_p->front() > 21);
}

unsigned short Hand::getValue() {
    if (isBusted()) {
        return _handValues_p->front();
    }
    list<unsigned short>::iterator it = _handValues_p->end();
    it--;
    while (true) {
        if (*it <= 21) {
            return *it;
        }
        it--;
    }
}
