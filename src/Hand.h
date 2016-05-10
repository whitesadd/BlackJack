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

class Hand : public vector<Card *> {
public:
    Hand();
    ~Hand();
    void addCard(Card* card_p);
    void reveal();
    const string getUnicode();
    list<unsigned short> const * getValues();
    unsigned short getValue();
    bool isBusted();

    static const unsigned short HIDDEN_VALUE = USHRT_MAX;

private:
    list<unsigned short>* _handValues_p;
    void addCardValues(Card* newCard_p);

};


#endif /* HAND_H_ */
