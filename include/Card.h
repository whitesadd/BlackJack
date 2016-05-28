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

#define UNICODE_ACE_STR         "\u0020\u0041"
#define UNICODE_TWO_STR         "\u0020\u0032"
#define UNICODE_THREE_STR       "\u0020\u0033"
#define UNICODE_FOUR_STR        "\u0020\u0034"
#define UNICODE_FIVE_STR        "\u0020\u0035"
#define UNICODE_SIX_STR         "\u0020\u0036"
#define UNICODE_SEVEN_STR       "\u0020\u0037"
#define UNICODE_EIGHT_STR       "\u0020\u0038"
#define UNICODE_NINE_STR        "\u0020\u0039"
#define UNICODE_TEN_STR         "\u0031\u0030"
#define UNICODE_JACK_STR        "\u0020\u004A"
#define UNICODE_QUEEN_STR       "\u0020\u0051"
#define UNICODE_KING_STR        "\u0020\u004B"

#define UNICODE_SPADES_STR      "\u2660"
#define UNICODE_HEARTS_STR      "\u2665"
#define UNICODE_DIAMONDS_STR    "\u2666"
#define UNICODE_CLUBS_STR       "\u2663"

#define UNICODE_QUESTION_STR    "\u0020\u003F\u003F"

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
    std::string getUnicodeString();
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
