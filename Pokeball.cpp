#include <iostream>
#include "Pokeball.h"

Pokemone* Pokeball::getPokemoneByName(std::string name){
    int index=findByName(name);
    if(index!=-1){
        Pokemone * p=getPokemones()[index];
        removePokemone(index);      
        return p;
    }
    
    return nullptr;
}

Pokemone* Pokeball::getPokemoneById(int id){
    int index=findById(id);
    if(index!=-1){
        Pokemone *p= getPokemones()[index];
        removePokemone(index);
        return p;      
    }
    return nullptr;
    
}

Pokemone* Pokeball::getPokemoneByIndex(int id){
    if(id>=0 && id<getPokemones().size()){
        Pokemone *p= getPokemones()[id];
        p->displayInfo();
        removePokemone(id);
        return p;      
    }
    return nullptr;
}