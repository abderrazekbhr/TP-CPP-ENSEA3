#include <iostream>
#include "SetOfPokemon.h"

void SetOfPokemon::affiche(){
    int i=0;
    for(auto pok : pokemones){
        std::cout<<"index="<<i<<"| Pokemone ID:"<<pok->getId()<<" | Pokemone name:"<<pok->getName()<<std::endl;
        i++;
    }
}

void SetOfPokemon::addNewPokemone(Pokemone* p){
    pokemones.push_back(p);
}
std::vector<Pokemone*> SetOfPokemon::getPokemones(){
    return pokemones;
}