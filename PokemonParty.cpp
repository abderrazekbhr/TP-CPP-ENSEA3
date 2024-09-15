#include "PokemonParty.h"
#include "SetOfPokemon.h"
#include "Game.h"
#include <iostream>
#include "Pokedex.h"

PokemonParty::PokemonParty(int indexP1, int indexP2, std::vector<int> pokemonsP1, std::vector<int> pokemonsP2)
{
    player1 = Game::getPlayers()[indexP1];
    player2 = Game::getPlayers()[indexP2];

    for (int i = 0; i < pokemonsP1.size(); i++)
    {
        Pokemon* pokemon = player1->getPokeball()->getPokemonByIndex(pokemonsP1[i]);
        if (pokemon) {
            player1->addPokemon(pokemon);
            player1->getPokeball()->removePokemon(pokemonsP1[i]);
        }
    }
    for (int i = 0; i < pokemonsP2.size(); i++)
    {
        Pokemon* pokemon = player2->getPokeball()->getPokemonByIndex(pokemonsP2[i]);
        if (pokemon) {
            player2->addPokemon(pokemon);
            player2->getPokeball()->removePokemon(pokemonsP2[i]);
        }
    }
}

PokemonParty::PokemonParty(int indexP1, int indexP2, std::vector<std::string> pokemonsP1, std::vector<std::string> pokemonsP2)
{
    player1 = Game::getPlayers()[indexP1];
    player2 = Game::getPlayers()[indexP2];

    for (const auto& name : pokemonsP1)
    {
        Pokemon* pokemon = player1->getPokeball()->getPokemonByName(name);
        if (pokemon) {
            player1->addPokemon(pokemon);
        }
    }

    for (const auto& name : pokemonsP2)
    {
        Pokemon* pokemon = player2->getPokeball()->getPokemonByName(name);
        if (pokemon) {
            player2->addPokemon(pokemon);
        }
    }
}

void PokemonParty::fullbattle()
{
    int pointP1 = 0, pointP2 = 0;
    std::vector<Pokemon*> pokemonsPlayer1 = player1->getMyPokemonsForBattle();
    std::vector<Pokemon*> pokemonsPlayer2 = player2->getMyPokemonsForBattle();

    int battleCount = std::min(pokemonsPlayer1.size(), pokemonsPlayer2.size());
    battleCount = std::min(battleCount, 6); // Ensure we have a maximum of 6 battles

    for (int i = 0; i < battleCount; i++)
    {
        Pokemon* pokemon1 = pokemonsPlayer1[i];
        Pokemon* pokemon2 = pokemonsPlayer2[i];

        if (!pokemon1 || !pokemon2)
        {
            std::cerr << "Error: Null pointer encountered for Pokemon. Skipping battle." << std::endl;
            continue;
        }

        while (pokemon1->getHitPoint() > 0 && pokemon2->getHitPoint() > 0)
        {
            if (pokemon1->getAttack() <= pokemon2->getDefence() && pokemon2->getAttack() <= pokemon1->getDefence())
            {
                break; // Exit loop to avoid infinite battle
            }
            if (pokemon1->getHitPoint() > 0)
            {
                pokemon1->attackEnemy(pokemon2);
            }
            if (pokemon2->getHitPoint() > 0)
            {
                pokemon2->attackEnemy(pokemon1);
            }
        }

        std::cout << "\033[38;2;255;165;0m" << "***** Part " << i + 1 << " *****" << "\033[0m" << std::endl;
        std::cout << "\033[38;2;255;165;100m" << "Player 1 has :" << "\033[0m" << std::endl;
        pokemon1->displayInfo();
        std::cout << "\033[38;2;255;165;100m" << "Player 2 has :" << "\033[0m" << std::endl;
        pokemon2->displayInfo();

        if (pokemon1->getHitPoint() == 0)
        {
            pointP2++;
        }
        else
        {
            pointP1++;
        }
    }

    afterCombat(pokemonsPlayer1, pokemonsPlayer2);

    std::cout << "\033[1m\033[38;2;255;165;100m" << "-------------------------- Score partie " << pointP1 << "-" << pointP2 << " --------------------------" << "\033[0m" << std::endl;

    if (pointP1 > pointP2)
    {
        player1->addPoint();
        std::cout << "\033[1m\033[38;2;255;165;100m" << "-------------------------- Player1 wins --------------------------" << "\033[0m" << std::endl;
    }
    else if (pointP1 == pointP2)
    {
        std::cout << "\033[1m\033[38;2;200;165;100m" << "-------------------------- Draw --------------------------" << "\033[0m" << std::endl;
    }
    else
    {
        player2->addPoint();
        std::cout << "\033[1m\033[38;2;255;165;100m" << "-------------------------- Player2 wins --------------------------" << "\033[0m" << std::endl;
    }

    std::cout << "\033[1m\033[38;2;200;165;100m------------------ size of pokeball of first player=" << player1->getPokeball()->getPokemons().size() << ", size of pokeball of second player=" << player2->getPokeball()->getPokemons().size() << " ------------------\033[0m" << std::endl;
}

void PokemonParty::afterCombat(std::vector<Pokemon*>& pokemonsAfterPartyP1, std::vector<Pokemon*>& pokemonsAfterPartyP2)
{
    for (auto pokemon : pokemonsAfterPartyP1)
    {
        if (pokemon && pokemon->getHitPoint() > 0)
        {
            player1->getPokeball()->addNewPokemon(pokemon);
        }
    }
    for (auto pokemon : pokemonsAfterPartyP2)
    {
        if (pokemon && pokemon->getHitPoint() > 0)
        {
            player2->getPokeball()->addNewPokemon(pokemon);
        }
    }
    pokemonsAfterPartyP1.clear();
    pokemonsAfterPartyP2.clear();
}

PokemonParty::~PokemonParty()
{
    std::cout << "end of game party: PokemonParty deleted" << std::endl;
    // player1 and player2 should not be deleted if they are managed elsewhere
}
