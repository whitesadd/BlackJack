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
        _userInterface_p(new UserInterfaceImp()) {}

Game::Game(Decks* decks_p) :
        _deck_p(decks_p),
        _userInterface_p(new UserInterfaceImp()) {}

Game::Game(Decks* decks_p, UserInterface* userInterface_p) :
        _deck_p(decks_p),
        _userInterface_p(userInterface_p) {}

Game::~Game() {
    delete _deck_p;
}

void Game::run() {

    int noOfPlayers = 0;
    std::cout << std::endl;
    while (noOfPlayers <= 0) {
        std::cout << "How many players (1 - 7)? ";
        noOfPlayers = _userInterface_p->getNoOfPlayers();
    }
    std::cout << std::endl;

    dealCardToPlayer();
    dealCardToDealer(Card::FACING_DOWN);
    dealCardToPlayer();
    dealCardToDealer();
    printGame();

    while (!_playersHand.isBusted()) {
        std::cout << "Select Draw (D) or Hold (H): ";
        if (_userInterface_p->getPlayerMove() == 'H')
            break;
        dealCardToPlayer();
        printGame();
    }

    if (!_playersHand.isBusted()) {
        _dealersHand.reveal();
        printGame();

        dealCardToDealerUntilValue(Game::DEALER_STOP_VALUE);
        printGame();
    }
    printWinner();
}

bool Game::houseWins() {
    if (_playersHand.isBusted())
        return true;
    if (_dealersHand.isBusted())
        return false;
    if (_playersHand.size() == 2 && _playersHand.getValue() == 21)
        return false;
    if (_dealersHand.getValue() >= _playersHand.getValue())
        return true;
    return false;
}

bool Game::playerWins() {
    if (_playersHand.isBusted())
        return false;
    if (_dealersHand.isBusted())
        return true;
    if (_playersHand.size() == 2 && _playersHand.getValue() == 21)
        return true;
    if (_dealersHand.getValue() >= _playersHand.getValue())
        return false;
    return true;
}


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

void Game::printGame() {
    std::cout << std::endl;
    std::cout << "Dealer: " << _dealersHand.getUnicode();
    if (_dealersHand.isBusted()) std::cout << " BUSTED";
    std::cout << std::endl;
    std::cout << "Player: " << _playersHand.getUnicode();
    if (_playersHand.isBusted()) std::cout << " BUSTED";
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

