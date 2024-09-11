#include"SetOfPokemon.h"
#pragma once
class Pokedex:public SetOfPokemon{
private:
    static Pokedex* pokedexInstance; 
    Pokedex(std::string fileName);
public :
    static Pokedex* getPokdexInstance();
    Pokemone* getPokemoneById(int id);
    Pokemone* getPokemoneByName(std::string name);
    Pokemone* getPokemoneByIdNewV(int id);
    Pokemone* getPokemoneByNameNewV(std::string name);
    std::vector<Pokemone *> getPokemoneByIdNewVAllInstance(int id);
    std::vector<Pokemone *> getPokemoneByNameNewVAllInstance(std::string name);
};