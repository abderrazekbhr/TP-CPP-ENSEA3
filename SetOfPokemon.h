#include<iostream>
#include"Pokemone.h"
#include<vector>
#include<map>
#include<string>
class SetOfPokemon{
    private:
        std::vector<Pokemone*> pokemones;
    public:
        std::map<int, std::vector<Pokemone*>> pokemonesById;
        std::map<std::string, std::vector<Pokemone*>> pokemonesByName;
        virtual Pokemone* getPokemoneByName(std::string name)=0;
        virtual Pokemone* getPokemoneById(int id)=0;
        std::vector<Pokemone*> getPokemones();
        void addNewPokemone(Pokemone* p);

        void affiche();
};