#include<iostream>  
#include "SetOfPokemon.h"
#pragma once
class Pokeball : public SetOfPokemon {
    public:
        Pokemon* getPokemonByName(std::string name);
        Pokemon* getPokemonById(int id);
        Pokemon* getPokemonByIndex(int id);
};