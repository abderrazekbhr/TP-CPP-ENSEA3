#include "PokemonParty.h"
#include "SetOfPokemon.h"
#include "Game.h"
#include <iostream>
#include "Pokedex.h"

PokemonParty::PokemonParty(int indexP1, int indexP2, std::vector<int> pokemonsP1, std::vector<int> pokemonsP2)
{
    player1 = Game::getPlayers()[indexP1];
    player2 = Game::getPlayers()[indexP2];

    // Clear the battle team for both players
    player1->getMyPokemonsForBattle().clear();
    player2->getMyPokemonsForBattle().clear();

    // Add Pokémon to player1's battle team
    for (int index : pokemonsP1)
    {
        Pokemon *pokemon = player1->getPokeball()->getPokemonByIndex(index);

        if (pokemon) // Check if the Pokemon exists
        {
            player1->addPokemon(pokemon);
        }
    }

    // Collect and remove Pokémon from player1's Pokéball after adding to battle team
    std::vector<Pokemon *> pokemonsToRemove1 = player1->getMyPokemonsForBattle();
    for (Pokemon *pokemon : pokemonsToRemove1)
    {
        player1->getPokeball()->removePokemon(pokemon);
    }

    // Add Pokémon to player2's battle team
    for (int index : pokemonsP2)
    {
        Pokemon *pokemon = player2->getPokeball()->getPokemonByIndex(index);

        if (pokemon) // Check if the Pokemon exists
        {
            player2->addPokemon(pokemon);
        }
    }

    // Collect and remove Pokémon from player2's Pokéball after adding to battle team
    std::vector<Pokemon *> pokemonsToRemove2 = player2->getMyPokemonsForBattle();
    for (Pokemon *pokemon : pokemonsToRemove2)
    {
        player2->getPokeball()->removePokemon(pokemon);
    }
}



PokemonParty::PokemonParty(int indexP1, int indexP2, std::vector<std::string> pokemonsP1, std::vector<std::string> pokemonsP2)
{
    player1 = Game::getPlayers()[indexP1];
    player2 = Game::getPlayers()[indexP2];

    for (const auto &name : pokemonsP1)
    {
        Pokemon *pokemon = player1->getPokeball()->getPokemonByName(name);
        if (pokemon)
        {
            player1->addPokemon(pokemon);
        }
    }

    for (const auto &name : pokemonsP2)
    {
        Pokemon *pokemon = player2->getPokeball()->getPokemonByName(name);
        if (pokemon)
        {
            player2->addPokemon(pokemon);
        }
    }
}

void PokemonParty::fullbattle()
{
    int pointP1 = 0, pointP2 = 0;
    std::vector<Pokemon *> pokemonsPlayer1 = player1->getMyPokemonsForBattle();
    std::vector<Pokemon *> pokemonsPlayer2 = player2->getMyPokemonsForBattle();

    int battleCount = 6;

    for (int i = 0; i < battleCount; i++)
    {
        Pokemon *pokemon1 = pokemonsPlayer1[i];
        Pokemon *pokemon2 = pokemonsPlayer2[i];

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
        else if (pokemon2->getHitPoint() == 0)
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

}

void PokemonParty::afterCombat(std::vector<Pokemon *> &pokemonsAfterPartyP1, std::vector<Pokemon *> &pokemonsAfterPartyP2)
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
