/*
 * Game.cpp
 *
 *  Created on: Apr 17, 2016
 *      Author: david
 */

#include <iostream>
#include "Game.h"

using namespace std;

Game::Game() {}

Game::Game(Decks* decks_p) : _deck_p(decks_p) {}

Game::~Game() {}

void Game::run() {

    dealCardToPlayer();
    dealCardToDealer(Card::FACING_DOWN);
    dealCardToPlayer();
    dealCardToDealer();

    printGame();
}

void Game::dealCardToPlayer(bool facingUp) {
    dealCard(&_playersHand, facingUp);
}

void Game::dealCardToDealer(bool facingUp) {
    dealCard(&_dealersHand, facingUp);
}

void Game::dealCard(Hand* hand_p, bool facingUp) {
    Card* card_p = _deck_p->drawCard();
    if ((card_p->isFacingUp() && !facingUp) ||
        (!card_p->isFacingUp() && facingUp)) {
        card_p->flip();
    }
    hand_p->addCard(card_p);
}

void Game::printGame() {
    cout << "Dealer: " << _dealersHand.getUnicode() << endl;
    cout << "Player: " << _playersHand.getUnicode() << endl;
    cout << endl;
}

