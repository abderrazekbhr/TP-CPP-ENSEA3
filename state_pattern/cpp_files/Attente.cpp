#include <iostream>
#include "../h_files/State.h"
#include "../h_files/Attente.h"
#include "../h_files/Init.h"

void Attente::handle()
{
    std::cout << "Loading Game" << std::endl;
}

Attente::~Attente()
{
    std::cout << "Game Loaded" << std::endl;
}