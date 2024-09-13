#include "PokemonParty.h"
#include "SetOfPokemon.h"
#include "PokemonParty.h"
#include "Game.h"
#include <iostream>
#include "Pokedex.h"

PokemonParty::PokemonParty(int indexP1, int indexP2, std::vector<int> pokemonesP1, std::vector<int> pokemonesP2)
{
    player1 = Game::getPlayers()[indexP1];
    player2 = Game::getPlayers()[indexP2];
    // Game::getPlayers()[indexP1]->getPokeball()->affiche();
    std::cout << "start of PokemonParty constructor" << std::endl;
    std::cout << "P1.size()=" << player1->getPokeball()->getPokemones().size() << std::endl;
    std::cout << "P2.size()=" << player2->getPokeball()->getPokemones().size() << std::endl;

    for (int i = 0; i < pokemonesP1.size(); i++)
    {
        // player1->getPokeball()->getPokemoneByIndex(pokemonesP1[i])->displayInfo();
        player1->addPokemon(player1->getPokeball()->getPokemoneByIndex(pokemonesP1[i]));
    }
    for (int i = 0; i < pokemonesP2.size(); i++)
    {
        // player2->getPokeball()->getPokemoneByIndex(pokemonesP1[i])->displayInfo();
        player2->addPokemon(player2->getPokeball()->getPokemoneByIndex(pokemonesP2[i]));
    }
    std::cout << "end of PokemonParty constructor" << std::endl;
}

PokemonParty::PokemonParty(int indexP1, int indexP2, std::vector<std::string> pokemonesP1, std::vector<std::string> pokemonesP2)
{
    player1 = Game::getPlayers()[indexP1];
    player2 = Game::getPlayers()[indexP2];
    for (int i = 0; i < pokemonesP1.size(); i++)
    {
        player1->addPokemon(player1->getPokeball()->getPokemoneByName(pokemonesP1[i]));
    }

    for (int i = 0; i < pokemonesP2.size(); i++)
    {
        player2->addPokemon(player2->getPokeball()->getPokemoneByName(pokemonesP2[i]));
    }
}
void PokemonParty::fullbattle()
{
    int pointP1 = 0, pointP2 = 0;
    std::vector<Pokemone *> pokemonesPlayer1 = player1->getMyPokemonsForBattle();
    std::vector<Pokemone *> pokemonesPlayer2 = player2->getMyPokemonsForBattle();

    std::cout << "Player1 has " << pokemonesPlayer1.size() << " pokemones" << std::endl;
    std::cout << "Player2 has " << pokemonesPlayer2.size() << " pokemones" << std::endl;
    for (auto p : pokemonesPlayer1)
    {
        if (p != nullptr)
            p->displayInfo();
        else
            std::cout << "null" << std::endl;
    }
    int battleCount = std::min(pokemonesPlayer1.size(), pokemonesPlayer2.size());

    for (int i = 0; i < battleCount; i++)
    {
        Pokemone *pokemon1 = pokemonesPlayer1[i];
        Pokemone *pokemon2 = pokemonesPlayer2[i];

        // Safety check: Ensure the pointers are not null
        if (!pokemon1 || !pokemon2)
        {
            std::cerr << "Error: Null pointer encountered for Pokemon. Skipping battle." << std::endl;
            continue; // Skip this battle if any Pokémon is null
        }

        // Battle between Pokemon1 and Pokemon2
        while (pokemon1->getHitPoint() > 0 && pokemon2->getHitPoint() > 0)
        {
            if (pokemon1->getAttack() <= pokemon2->getDefence() && pokemon2->getAttack() <= pokemon1->getDefence())
            {
                break;
            }
            pokemon1->attackEnemy(pokemon2);
            pokemon2->attackEnemy(pokemon1);
            pokemon1->displayInfo();
            pokemon2->displayInfo();
        }

        if (pokemon1->getHitPoint() <= 0)
        {
            pointP2++;
            std::cout << "Player1's " << pokemon1->getName() << " is defeated" << std::endl;
        }
        else if (pokemon1->getHitPoint())
        {
            pointP1++;
            std::cout << "Player2's " << pokemon2->getName() << " is defeated" << std::endl;
        }
    }
    std::cout << "----------------------" << std::endl;
    std::cout << "pointP1=" << pointP1 << std::endl;
    std::cout << "pointP2=" << pointP2 << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << "size1="<< player1->getPokeball()->getPokemones().size() << ", size2=" <<player1->getPokeball()->getPokemones().size() << std::endl;

    afterCombat(pokemonesPlayer1, pokemonesPlayer2);

    if (pointP1 > pointP2)
    {
        std::cout << "Player1 wins" << std::endl;
    }
    else if (pointP1 == pointP2)
    {
        std::cout << "Draw" << std::endl;
    }
    else
    {
        std::cout << "Player2 wins" << std::endl;
    }
    std::cout << "size1="<< player1->getPokeball()->getPokemones().size() << ", size2=" <<player1->getPokeball()->getPokemones().size() << std::endl;

}

void PokemonParty::afterCombat(std::vector<Pokemone *> &pokemonesAfterPartyP1, std::vector<Pokemone *> &pokemonesAfterPartyP2)
{
    for (auto pokemone : pokemonesAfterPartyP1)
    {
        if (pokemone && pokemone->getHitPoint() > 0) // Check if not null and has hit points
        {
            player1->addPokemon(pokemone);
        }
    }
    for (auto pokemone : pokemonesAfterPartyP2)
    {
        if (pokemone && pokemone->getHitPoint() > 0) // Check if not null and has hit points
        {
            player2->addPokemon(pokemone);
        }
    }
}

PokemonParty::~PokemonParty()
{
    std::cout << "end of game party: PokemonParty deleted" << std::endl;
    delete player1;
    delete player2;
}
