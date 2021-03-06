/*
 * Hand.h
 *
 *  Created on: Apr 17, 2016
 *      Author: david
 */

#ifndef HAND_H_
#define HAND_H_

#include <vector>
#include <list>
#include "Card.h"

#define UNICODE_SPACE_STR        "\u0020"

class Hand : public std::vector<Card *> {

public:
    Hand();
    Hand(const Hand& hand);
    ~Hand();
    void addCard(Card* card_p);
    void reveal();
    const std::string getUnicode();
    std::list<unsigned short> const * getValues();
    unsigned short getValue();
    bool isBusted();
    bool isPair();

    static const unsigned short HIDDEN_VALUE = USHRT_MAX;

private:
    std::list<unsigned short>* _handValues_p;
    void addCardValues(Card* newCard_p);

};


#endif /* HAND_H_ */
