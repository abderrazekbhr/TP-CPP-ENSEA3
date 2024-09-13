#include <iostream>
#include "SetOfPokemon.h"

// findByName and findById are protected methods returning the index of the pokemone in the vector
int SetOfPokemon::findByName(std::string name)
{
    int i = 0;
    for (auto pok : pokemones)
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
    for (auto pok : pokemones)
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
std::vector<Pokemone *> SetOfPokemon::getPokemones()
{
    return pokemones;
}

// affiche method to display the pokemones
void SetOfPokemon::affiche()
{
    int i = 0;
    for (auto pok : pokemones)
    {
        std::cout << "index=" << i << "| Pokemone ID:" << pok->getId() << " | Pokemone name:" << pok->getName() << std::endl;
        i++;
    }
}

// addNewPokemone method to add a new pokemone to the vector
void SetOfPokemon::addNewPokemone(Pokemone *p)
{
    Pokemone *pok=new Pokemone(*p);
    pokemones.push_back(p);
}


// removePokemone method to remove a pokemone from the vector
void SetOfPokemon::removePokemone(int index){
    pokemones.erase(pokemones.begin() + index);
}