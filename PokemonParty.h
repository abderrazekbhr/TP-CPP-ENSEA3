#include "SetOfPokemon.h"
#pragma once
class PokemonParty: public SetOfPokemon {
    PokemonParty(int p1, int p2, int p3, int p4, int p5, int p6);
    PokemonParty(std::string nameP1, std::string nameP2, std::string nameP3, std::string nameP4, std::string nameP5, std::string nameP6);
    ~PokemonParty();
    

};