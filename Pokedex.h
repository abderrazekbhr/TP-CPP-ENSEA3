#include"SetOfPokemon.h"
#pragma once
class Pokedex:public SetOfPokemon{
private:
    static Pokedex* pokedexInstance; 
    Pokedex(std::string fileName);
public :
    static Pokedex* getPokdexInstance();
    Pokemon* getPokemonById(int id);
    Pokemon* getPokemonByName(std::string name);
    Pokemon* getPokemonByIdNewV(int id);
    Pokemon* getPokemonByNameNewV(std::string name);
    std::vector<Pokemon *> getPokemonByIdNewVAllInstance(int id);
    std::vector<Pokemon *> getPokemonByNameNewVAllInstance(std::string name);
};