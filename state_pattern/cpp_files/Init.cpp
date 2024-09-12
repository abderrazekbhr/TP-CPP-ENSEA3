
#include <iostream>
#include "../h_files/Init.h"
#include "../../Game.h"
#include "../h_files/Exploration.h"

void Init::handle()
{
    const int NB_PLAYERS = 2;
    for (int i = 0; i < NB_PLAYERS; i++)
    {
        Game::addPlayer(new Player("Player "+std::to_string(i+1)));
    }
    // context->setState(new Exploration());
}

Init::~Init()
{
    std::cout << "Init deleted" << std::endl;
}
