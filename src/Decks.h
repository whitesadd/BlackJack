/*
 * Decks.h
 *
 *  Created on: Apr 11, 2016
 *      Author: david
 */

#ifndef DECKS_H_
#define DECKS_H_

using namespace std;

#include <vector>
#include "Card.h"

class Decks {
public:
    virtual ~Decks();
    unsigned int size();
    Card* drawCard();

protected:
    Decks();
    vector<Card*> _stack;

};

#endif /* DECKS_H_ */
