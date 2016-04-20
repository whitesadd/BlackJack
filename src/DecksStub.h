/*
 * DecksStub.h
 *
 *  Created on: Apr 20, 2016
 *      Author: david
 */

#ifndef DECKSSTUB_H_
#define DECKSSTUB_H_

#include "Decks.h"

using namespace std;

class DecksStub : public Decks {

public:
    DecksStub(vector<Card*>* decks_p);
    virtual ~DecksStub();
};

#endif /* DECKSSTUB_H_ */
