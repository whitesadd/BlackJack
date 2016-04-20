/*
 * DecksImp.cpp
 *
 *  Created on: 20 apr. 2016
 *      Author: ebladav
 */

#include <cstdlib>
#include "DecksImp.h"

DecksImp::DecksImp() {}

DecksImp::DecksImp(int noOfDecks) {
	srand(time(NULL));
	int i = 1;
	for (int deck = 0; deck < noOfDecks; deck++) {
		for (Suit suit = Card::FIRST_SUIT; suit <= Card::LAST_SUIT; suit++) {
			for (Rank rank = Card::FIRST_RANK; rank <= Card::LAST_RANK; rank++) {
				int offset = rand() % i;
				_stack.insert(_stack.begin() + offset, new Card(rank, suit));
				i++;
			}
		}
	}
}

DecksImp::~DecksImp() {}
