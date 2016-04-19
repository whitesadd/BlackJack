/*
 * Decks.h
 *
 *  Created on: Apr 11, 2016
 *      Author: david
 */

#ifndef DECKS_H_
#define DECKs_H_

using namespace std;

#include <vector>
#include "Card.h"

class Decks {
public:
    Decks(int noOfDecks);
    virtual ~Decks();
    unsigned int size();
    Card* drawCard();

private:
    vector<Card *> stack;
};


#endif /* DECKS_H_ */
