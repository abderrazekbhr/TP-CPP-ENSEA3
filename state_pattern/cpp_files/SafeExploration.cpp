#include "../h_files/State.h"
#include "../h_files/SafeExploration.h"
#include <iostream>
#include "../../Game.h"
#include <time.h>
#include <unistd.h>
void SafeExploration::handel()
{

    std::cout << "\033[1;31m------------- Start exploration -------------\033[0m\n";

    std::vector<Player *> players = Game::getPlayers();
    int sizePlayers = players.size();
    const int NB_POKEMONES = 6;
    std::vector<Pokemon *> all = Pokedex::getPokdexInstance()->getPokemons();
    srand((unsigned)time(NULL));
    for (int i = 0; i < sizePlayers; i++)
    {

        std::cout << "\033[38;2;255;165;0m" << players[i]->getName() << " starts exploring:" << "\033[0m" << std::endl;

        // std::cout << players[i]->getName() << " start exploring:" << std::endl;
        for (size_t j = 0; j < NB_POKEMONES; j++)
        {
            int randomIndex = rand() % all.size();
            all[randomIndex]->displayInfo();
            players[i]->getPokeball()->addNewPokemon(all[randomIndex]);
        }
        sleep(2);
    }
}
SafeExploration::~SafeExploration()
{
    // std::cout << "Exploration ended" << std::endl;
}
