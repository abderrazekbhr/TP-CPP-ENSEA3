#include <iostream>
#include "Pokeball.h"

Pokemon* Pokeball::getPokemonByName(std::string name){
    int index=findByName(name);
    if(index!=-1){
        Pokemon * p=getPokemons()[index];
        removePokemon(index);      
        return p;
    }
    
    return nullptr;
}

Pokemon* Pokeball::getPokemonById(int id){
    int index=findById(id);
    if(index!=-1){
        Pokemon *p= getPokemons()[index];
        removePokemon(index);
        return p;      
    }
    return nullptr;
    
}

Pokemon* Pokeball::getPokemonByIndex(int id){
    // std::cout<<"/////////"<<getPokemons().size()<<"/////////"<<std::endl;
    if(id>=0 && id<getPokemons().size()){
        Pokemon *p= getPokemons()[id];
        return p;      
    }
    return nullptr;
}