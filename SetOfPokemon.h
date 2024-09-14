#pragma once
#include"Pokemon.h"
#include<vector>
#include<map>
#include<string>
class SetOfPokemon{
    private:
        std::vector<Pokemon*> pokemons;
    protected:
        int findByName(std::string name);
        int findById(int id);
    public:
        std::map<int, std::vector<Pokemon*>> pokemonsById;
        std::map<std::string, std::vector<Pokemon*>> pokemonsByName;
        virtual Pokemon* getPokemonByName(std::string name)=0;
        virtual Pokemon* getPokemonById(int id)=0;
        std::vector<Pokemon*> getPokemons();
        void addNewPokemon(Pokemon* p);
        void removePokemon(int index);
        void affiche();
};