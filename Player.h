#pragma once
#include <iostream>
#include <string>
#include "Pokeball.h"
#include "Pokemon.h"
class Player
{
private:
    Pokeball *myballs;
    std::string name;
    int points;
    std::vector<Pokemon*> myPokemonsForBattle;
public:
    Player(std::string name);
    std::string getName();
    Pokeball *getPokeball();
    void addPokemon(Pokemon *pokemon);
    std::vector<Pokemon*> getMyPokemonsForBattle();
    int getPoints();
    void addPoint();
    ~Player();


};
