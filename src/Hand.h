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

using namespace std;

class Hand : public vector<Card *> {
public:
    Hand();
    ~Hand();
    void addCard(Card* card_p);
    string getUnicode();
    list<unsigned short> const * getValues();
    unsigned short getSoftValue();
    unsigned short getHardValue();
    bool isBusted();

    static const unsigned short HIDDEN_VALUE = USHRT_MAX;

private:
    string _unicodeStr;
    list<unsigned short>* _handValues_p;
    void appendCardUnicodeStr(Card* newCard_p);
    void addCardValues(Card* newCard_p);

};


#endif /* HAND_H_ */
