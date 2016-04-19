/*
 * Card.cpp
 *
 *  Created on: Apr 10, 2016
 *      Author: david
 */

#include "Card.h"

#define IS_FACE_CARD()    \
    (_rank == JACK || _rank == QUEEN || _rank == KING)

Card::Card(Rank rank, Suit suit, bool facingUp) : _rank(rank), _suit(suit), _facingUp(facingUp) {
}

Card::~Card() {
}

RankValues Card::getValues() {
    const unsigned short faceCardValue = 10;
    const unsigned short alternativeAceValue = 11;
    RankValues rankValues;
    if (IS_FACE_CARD()) {
        rankValues.firstValue = faceCardValue;
        rankValues.secondValue = NO_ALTERNATE_VALUE;
    } else if (_rank == ACE) {
        rankValues.firstValue = _rank;
        rankValues.secondValue = alternativeAceValue;
    } else {
        rankValues.firstValue = _rank;
        rankValues.secondValue = NO_ALTERNATE_VALUE;
    }
    return rankValues;
}

string Card::getUnicodeString() {
    if (!_facingUp) {
        return "\u0020\u003F\u003F";
    }

    int rankIndex = _rank - 1;
    int suitIndex = _suit;
    static string const unicodeArray[][4] = {
           {"\u0020\u0041\u2660", "\u0020\u0041\u2665", "\u0020\u0041\u2666", "\u0020\u0041\u2663"},
           {"\u0020\u0032\u2660", "\u0020\u0032\u2665", "\u0020\u0032\u2666", "\u0020\u0032\u2663"},
           {"\u0020\u0033\u2660", "\u0020\u0033\u2665", "\u0020\u0033\u2666", "\u0020\u0033\u2663"},
           {"\u0020\u0034\u2660", "\u0020\u0034\u2665", "\u0020\u0034\u2666", "\u0020\u0034\u2663"},
           {"\u0020\u0035\u2660", "\u0020\u0035\u2665", "\u0020\u0035\u2666", "\u0020\u0035\u2663"},
           {"\u0020\u0036\u2660", "\u0020\u0036\u2665", "\u0020\u0036\u2666", "\u0020\u0036\u2663"},
           {"\u0020\u0037\u2660", "\u0020\u0037\u2665", "\u0020\u0037\u2666", "\u0020\u0037\u2663"},
           {"\u0020\u0038\u2660", "\u0020\u0038\u2665", "\u0020\u0038\u2666", "\u0020\u0038\u2663"},
           {"\u0020\u0039\u2660", "\u0020\u0039\u2665", "\u0020\u0039\u2666", "\u0020\u0039\u2663"},
           {"\u0031\u0030\u2660", "\u0031\u0030\u2665", "\u0031\u0030\u2666", "\u0031\u0030\u2663"},
           {"\u0020\u004A\u2660", "\u0020\u004A\u2665", "\u0020\u004A\u2666", "\u0020\u004A\u2663"},
           {"\u0020\u0051\u2660", "\u0020\u0051\u2665", "\u0020\u0051\u2666", "\u0020\u0051\u2663"},
           {"\u0020\u004B\u2660", "\u0020\u004B\u2665", "\u0020\u004B\u2666", "\u0020\u004B\u2663"}};

    return unicodeArray[rankIndex][suitIndex];
}

void Card::flip() {
    _facingUp = !_facingUp;
}

bool Card::isFacingUp() {
    return _facingUp;
}

