#pragma once
#include "SetOfPokemon.h"
#include "Pokeball.h"
#include "Player.h"
class PokemonParty
{
private:
    Player *player1;
    Player *player2;

public:
    PokemonParty(int indexP1, int indexP2, std::vector<int> pokemonesP1, std::vector<int> pokemonesP2);
    PokemonParty(int indexP1, int indexP2, std::vector<std::string> pokemonesP1, std::vector<std::string> pokemonesP2);
    void fullbattle();
    void afterCombat(std::vector<Pokemone *> &pokemonesAfterPartyP1, std::vector<Pokemone *> &pokemonesAfterPartyP2);
    ~PokemonParty();
};