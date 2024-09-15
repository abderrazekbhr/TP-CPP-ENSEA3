#include <iostream>
#include "../h_files/Result.h"
#include "../../Game.h"

void Result::handel()
{
    std::cout << "\033[1;3;31m------------- Result ------------- \033[0m" << std::endl;
    int pP1 = Game::getPlayers()[0]->getPoints();
    int pP2 = Game::getPlayers()[1]->getPoints();
    std::cout << "\033[1m\033[38;2;0;255;0m********** Player 1 has " << pP1 << " points **********\033[0m" << std::endl;
    std::cout << "\033[1m\033[38;2;0;255;0m********** Player 2 has " << pP2 << " points **********\033[0m" << std::endl;

    if (pP1 > pP2)
    {
        std::cout << "\033[1m\033[38;2;0;0;0m********** Player 1 wins **********\033[0m" << std::endl;
    }
    else if (pP1 == pP2)
    {
        std::cout << "\033[1m\033[38;2;0;0;0m********** Draw **********\033[0m" << std::endl;
    }
    else
    {
        std::cout << "\033[1m\033[38;2;0;0;0m********** Player 2 wins **********\033[0m" << std::endl;
    }
}