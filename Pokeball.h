#include<iostream>  
#include "SetOfPokemon.h"
#pragma once
class Pokeball : public SetOfPokemon {
    public:
        Pokemone* getPokemoneByName(std::string name);
        Pokemone* getPokemoneById(int id);
        Pokemone* getPokemoneByIndex(int id);
};