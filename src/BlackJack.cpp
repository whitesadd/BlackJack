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


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    std::cout << std::endl << "!!!Welcome to Black Jack TDD!!!" << std::endl << std::endl;
    if (RUN_ALL_TESTS() !=0) {
        return -1;
    }

    std::cout << std::endl << "!!!!Now, let's play Black Jack!!!!" << std::endl;
    Game().run();
}
