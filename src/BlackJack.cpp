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
    int unitTestResult = RUN_ALL_TESTS();
    if (unitTestResult != 0) return unitTestResult;

    /*
    cout << endl << "!!!!Now, let's play Black Jack!!!!" << endl << endl;
    Game().run();
    */
}
