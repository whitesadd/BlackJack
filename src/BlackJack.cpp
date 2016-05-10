//============================================================================
// Name        : BlackJack.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Black Jack Game
//============================================================================

#include <iostream>
#include "Game.h"
#include "gtest/gtest.h"


using namespace std;

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    cout << endl << "!!!Welcome to Black Jack TDD!!!" << endl << endl;
    if (RUN_ALL_TESTS() !=0) {
        return -1;
    }

    cout << endl << "!!!!Now, let's play Black Jack!!!!" << endl;
    Game().run();
}
