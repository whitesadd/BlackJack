/*
 * Game.cpp
 *
 *  Created on: Apr 17, 2016
 *      Author: david
 */

#include <iostream>
#include <cassert>
#include "Game.h"
#include "DecksImp.h"

using namespace std;

Game::Game() : _deck_p(new DecksImp(4)) {}

Game::Game(Decks* decks_p) : _deck_p(decks_p) {}

Game::~Game() {
    delete _deck_p;
}

void Game::run() {

    dealCardToPlayer();
    dealCardToDealer(Card::FACING_DOWN);
    dealCardToPlayer();
    dealCardToDealer();
    printGame();

    dealCardToPlayerUntilValue(18);
    printGame();

    if (_playersHand.isBusted()) return;

    revealDealersHand();
    printGame();

    dealCardToDealerUntilValue(17);
    printGame();
}

bool Game::houseWins() {return true;}
bool Game::playerWins() {return true;}


void Game::dealCardToPlayer(bool facingUp) {
    dealCard(&_playersHand, facingUp);
}

void Game::dealCardToDealer(bool facingUp) {
    dealCard(&_dealersHand, facingUp);
}

void Game::dealCard(Hand* hand_p, bool facingUp) {
    Card* card_p = _deck_p->drawCard();
    assert(card_p != NULL);
    if ((card_p->isFacingUp() && !facingUp) ||
        (!card_p->isFacingUp() && facingUp)) {
        card_p->flip();
    }
    hand_p->addCard(card_p);
}


void Game::dealCardToPlayerUntilValue(unsigned short limit) {
    return dealCardUntilValue(&_playersHand, limit);
}

void Game::dealCardToDealerUntilValue(unsigned short limit) {
    dealCardUntilValue(&_dealersHand, limit);
}

void Game::dealCardUntilValue(Hand* hand_p, unsigned short limit) {
    while (hand_p->getValue() < limit) {
        dealCard(hand_p);
    }
}

void  Game::revealDealersHand() {
    _dealersHand.reveal();
}


void Game::printGame() {
    cout << endl;
    cout << "Dealer: " << _dealersHand.getUnicode();
    if (_dealersHand.isBusted()) cout << " BUSTED";
    cout << endl;
    cout << "Player: " << _playersHand.getUnicode();
    if (_playersHand.isBusted()) cout << " BUSTED";
    cout << endl;
    cout << endl;
}

