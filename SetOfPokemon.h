#include<iostream>
#include"Pokemone.h"
#include<vector>
class SetOfPokemon{
    private:
        std::vector<Pokemone*> pokemones;
    public:
        virtual Pokemone* getPokemoneByName(std::string name)=0;
        virtual Pokemone* getPokemoneById(int id)=0;
        std::vector<Pokemone*> getPokemones();
        void addNewPokemone(Pokemone* p); 
        void affiche();
};