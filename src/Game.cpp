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
#include "UserInterfaceImp.h"

Game::Game() :
        _deck_p(new DecksImp(4)),
        _userInterface_p(new UserInterfaceImp()) {
    _playersHands.push_back(Hand());
}

Game::Game(Decks* decks_p) :
        _deck_p(decks_p),
        _userInterface_p(new UserInterfaceImp()) {
    _playersHands.push_back(Hand());
}

Game::Game(Decks* decks_p, UserInterface* userInterface_p) :
        _deck_p(decks_p),
        _userInterface_p(userInterface_p) {
    _playersHands.push_back(Hand());
}

Game::~Game() {
    delete _deck_p;
}

void Game::run() {

    int noOfPlayers = 0;
    assert(_playersHands.size() == 1); // One player already created during
                                       // construct time.

    std::cout << std::endl;
    do {
        std::cout << "How many players? ";
        noOfPlayers = _userInterface_p->getNoOfPlayers();
        std::cout << "You have selected " << noOfPlayers << " players." << std::endl;
    } while (noOfPlayers <= 0 || 7 < noOfPlayers);
    std::cout << std::endl;

    for (int i = 1; i < noOfPlayers; i++) {
        _playersHands.push_back(Hand());
    }

    for (int i = 0; i < noOfPlayers; i++) {
        dealCardToPlayer(i);
    }
    dealCardToDealer(Card::FACING_DOWN);
    for (int i = 0; i < noOfPlayers; i++) {
        dealCardToPlayer(i);
    }

    dealCardToDealer();
    printGame();

    for (int i = 0; i < noOfPlayers; i++) {
        while (!_playersHands[0].isBusted()) {
            std::cout << "Select Draw (D) or Hold (H): ";
            if (_userInterface_p->getPlayerMove() == 'H')
                break;
            dealCardToPlayer(i);
            printGame();
        }
    }

    if (!_playersHands[0].isBusted()) {
        _dealersHand.reveal();
        printGame();

        dealCardToDealerUntilValue(Game::DEALER_STOP_VALUE);
        printGame();
    }
    printWinner();
}

bool Game::houseWins() {
    if (_playersHands[0].isBusted())
        return true;
    if (_dealersHand.isBusted())
        return false;
    if (_playersHands[0].size() == 2 && _playersHands[0].getValue() == 21)
        return false;
    if (_dealersHand.getValue() >= _playersHands[0].getValue())
        return true;
    return false;
}

bool Game::playerWins() {
    if (_playersHands[0].isBusted())
        return false;
    if (_dealersHand.isBusted())
        return true;
    if (_playersHands[0].size() == 2 && _playersHands[0].getValue() == 21)
        return true;
    if (_dealersHand.getValue() >= _playersHands[0].getValue())
        return false;
    return true;
}


void Game::dealCardToPlayer(int playerId, bool facingUp) {
    dealCard(&(_playersHands[playerId]), facingUp);
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
    return dealCardUntilValue(&(_playersHands[0]), limit);
}

void Game::dealCardToDealerUntilValue(unsigned short limit) {
    dealCardUntilValue(&_dealersHand, limit);
}

void Game::dealCardUntilValue(Hand* hand_p, unsigned short limit) {
    while (hand_p->getValue() < limit) {
        dealCard(hand_p);
    }
}

void Game::printGame() {
    std::cout << std::endl;
    std::cout << "Dealer: " << _dealersHand.getUnicode();
    if (_dealersHand.isBusted()) std::cout << " BUSTED";
    std::cout << std::endl;
    std::cout << "Player: " << _playersHands[0].getUnicode();
    if (_playersHands[0].isBusted()) std::cout << " BUSTED";
    std::cout << std::endl << std::endl;
}

void Game::printWinner() {
    if (houseWins()) {
        std::cout << "House Wins!" << std::endl;
    }
    else if (playerWins()) {
        std::cout << "Player Wins!" << std::endl;
    }
}
