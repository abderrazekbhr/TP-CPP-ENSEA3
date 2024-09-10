#include"SetOfPokemon.h"
class Pokedex:public SetOfPokemon{
private:
    static Pokedex* pokedexInstance; 
    Pokedex(std::string fileName);
public :
    static Pokedex* getPokdexInstance();
    Pokemone* getPokemoneById(int id);
    Pokemone* getPokemoneByName(std::string name);
};