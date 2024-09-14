#include <iostream>
#include "SetOfPokemon.h"

// findByName and findById are protected methods returning the index of the pokemone in the vector
int SetOfPokemon::findByName(std::string name)
{
    int i = 0;
    for (auto pok : pokemons)
    {
        if (pok->getName() == name)
        {
            return i;
        }
        i++;
    }
    return -1;
}
int SetOfPokemon::findById(int id)
{
    int i = 0;
    for (auto pok : pokemons)
    {
        if (pok->getId() == id)
        {
            return i;
        }
        i++;
    }
    return -1;
}

// getter for pokemones
std::vector<Pokemon *> SetOfPokemon::getPokemons()
{
    return pokemons;
}

// affiche method to display the pokemones
void SetOfPokemon::affiche()
{
    int i = 0;
    for (auto pok : pokemons)
    {
        std::cout << "index=" << i << "| Pokemone ID:" << pok->getId() << " | Pokemone name:" << pok->getName() << std::endl;
        i++;
    }
}

// addNewPokemone method to add a new pokemone to the vector
void SetOfPokemon::addNewPokemon(Pokemon *p)
{
    Pokemon *pok=new Pokemon(*p);
    pokemons.push_back(p);
}


// removePokemone method to remove a pokemone from the vector
void SetOfPokemon::removePokemon(int index){
    pokemons.erase(pokemons.begin() + index);
}