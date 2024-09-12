#pragma once
#include <iostream>
#include <string>
#include "Pokeball.h"
#include "Pokemone.h"
class Player
{
private:
    Pokeball *myballs;
    std::string name;
    std::vector<Pokemone*> myPokemonsForBattle;
public:
    Player(std::string name);
    std::string getName();
    Pokeball *getPokeball();
    void addPokemon(Pokemone *pokemone);
    std::vector<Pokemone*> getMyPokemonsForBattle();
    ~Player();


};
