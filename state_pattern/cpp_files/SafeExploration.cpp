#pragma once
#include "../h_files/State.h"
#include "../h_files/SafeExploration.h"
#include <iostream>
#include "../../Game.h"
void SafeExploration::handle()
{
    std::cout << "Start exploration" << std::endl;
    std::vector<Player*> players= Game::getPlayers();
    int sizePlayers= players.size();
    const int NB_POKEMONES = 6;
    std::vector<Pokemone*> all= Pokedex::getPokdexInstance()->getPokemones();
    for(int i = 0; i < sizePlayers; i++)
    {
        for (size_t j = 0; j < NB_POKEMONES; j++)
        {
            int randomIndex = rand() % all.size();
            all[randomIndex]->displayInfo();
            players[i]->addPokemon(all[randomIndex]);        
            
        }
        
    }
    // context->setState(new SafeExploration());
}
SafeExploration::~SafeExploration(){
    std::cout << "Exploration ended" << std::endl;
}
