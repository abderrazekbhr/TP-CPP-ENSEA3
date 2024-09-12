#pragma once
#include "PokemonParty.h"
#include "SetOfPokemon.h"
#include "Pokeball.h"
#include "PokemonParty.h"
#include "Game.h"
#include <iostream>
#include "Pokedex.h"

PokemonParty::PokemonParty(int indexP1, int indexP2, std::vector<int> pokemonesP1, std::vector<int> pokemonesP2)
{
    std::cout<<Game::getPlayers().size()<<"PokemonParty constructor"<<std::endl;
    player1 = Game::getPlayers()[indexP1];
    player2 = Game::getPlayers()[indexP2];
    for (int i = 0; i < pokemonesP1.size(); i++)
    {

        player1->getPokeball()->getPokemoneById(pokemonesP1[i])->displayInfo();
        player1->addPokemon(player1->getPokeball()->getPokemoneById(pokemonesP1[i]));
    }
    for (int i = 0; i < pokemonesP2.size(); i++)
    {
        player2->getPokeball()->getPokemoneById(pokemonesP1[i])->displayInfo();
        player2->addPokemon(player2->getPokeball()->getPokemoneById(pokemonesP2[i]));

    }
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
    for (int i = 0; i < pokemonesPlayer1.size(); i++)
    {
        while (pokemonesPlayer1[i]->getHitPoint() > 0 && pokemonesPlayer2[i]->getHitPoint() > 0)
        {
            pokemonesPlayer1[i]->attackEn(*pokemonesPlayer2[i]);
            pokemonesPlayer2[i]->attackEn(*pokemonesPlayer1[i]);
        }
        if (pokemonesPlayer1[i]->getHitPoint() <= 0)
        {
            pointP2++;
            std::cout << "Player1 :" << pokemonesPlayer1[i]->getName() << " is dead" << std::endl;
        }
        else
        {
            pointP1++;
            std::cout << "Player2 :" << pokemonesPlayer2[i]->getName() << " is dead" << std::endl;
        }
    }
    afterCombat(pokemonesPlayer1,pokemonesPlayer2);

    if (pointP1 > pointP2)
    {
        std::cout << "Player1 win" << std::endl;
    }
    else
    {
        if (pointP1 == pointP2)
        {
            std::cout << "Draw" << std::endl;
        }
        else
        {
            std::cout << "Player2 win" << std::endl;
        }
    }
}

void PokemonParty::afterCombat(std::vector<Pokemone *>pokemonesAfterPartyP1,std::vector<Pokemone *>pokemonesAfterPartyP2)
{
    for(auto pokemone : pokemonesAfterPartyP1)
    {
        if(pokemone->getHitPoint() > 0)
        {
            player1->addPokemon(pokemone);
        }
    }
    for(auto pokemone : pokemonesAfterPartyP2)
    {
        if(pokemone->getHitPoint() > 0)
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
