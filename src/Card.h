/*
 * Card.h
 *
 *  Created on: Apr 10, 2016
 *      Author: david
 */

#ifndef CARD_H_
#define CARD_H_

#include <climits>
#include <string>

using namespace std;

typedef int Rank;
typedef int Suit;

typedef struct RankValues {
    unsigned short firstValue;
    unsigned short secondValue;
} RankValues;

class Card {
public:
    Card(Rank rank, Suit suit, bool facingUp = Card::FACING_UP);
    virtual ~Card();

    RankValues getValues();
    string getUnicodeString();
    void flip();
    bool isFacingUp();

    static const Suit SPADES = 0;
    static const Suit HEARTS = 1;
    static const Suit DIAMONDS = 2;
    static const Suit CLUBS = 3;

    static const Suit FIRST_SUIT = SPADES;
    static const Suit LAST_SUIT = CLUBS;

    static const Rank ACE = 1;
    static const Rank TWO = 2;
    static const Rank THREE = 3;
    static const Rank FOUR = 4;
    static const Rank FIVE = 5;
    static const Rank SIX = 6;
    static const Rank SEVEN = 7;
    static const Rank EIGHT = 8;
    static const Rank NINE = 9;
    static const Rank TEN = 10;
    static const Rank JACK = 11;
    static const Rank QUEEN = 12;
    static const Rank KING = 13;

    static const Rank FIRST_RANK = ACE;
    static const Rank LAST_RANK = KING;

    static const unsigned short NO_ALTERNATE_VALUE = 0;

    static const bool FACING_UP = true;
    static const bool FACING_DOWN = false;


private:
    Rank _rank;
    Suit _suit;
    bool _facingUp;

};

#endif /* CARD_H_ */
