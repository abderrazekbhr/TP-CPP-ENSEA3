#include "Pokedex.h"
#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <string>
#include <iterator>

Pokedex *Pokedex::pokedexInstance = nullptr;
Pokedex::Pokedex(std::string fileName)
{

    const std::string delimiter = ",";
    std::fstream fin;
    try
    {
        std::string line;
        fin.open(fileName);
        getline(fin, line);
        while (getline(fin, line))
        {

            // std::cout << line << std::endl;
            std::regex regex(delimiter);
            std::sregex_token_iterator it(line.begin(), line.end(), regex, -1);
            std::vector<std::string> tokens(it, {});
            // std::cout<<"----------- instanciate new pokemone ------------"<<std::endl;pokemone::Pokemone(int id, std::string name, std::string game, double hitPoint, double attack, double defence, int generation)
            int id = std::stoi(tokens.at(0));
            std::string name = tokens.at(1);
            std::string game = tokens.at(2);
            double hitPoint = std::stod(tokens.at(5));
            double attack = std::stod(tokens.at(6));
            double defence = std::stod(tokens.at(7));
            int generation = std::stoi(tokens.at(10));

            //  std::stoi(tokens.at(0))
            //  tokens.at(1)
            //  tokens.at(2)
            //  std::stod(tokens.at(5))
            //  std::stod(tokens.at(6))
            //  std::stod(tokens.at(7))
            //  std::stoi(tokens.at(10))
            Pokemon *p = new Pokemon(id, name, game, hitPoint, attack, defence, generation);
            Pokedex::pokemonsById[id].push_back(p);
            Pokedex::pokemonsByName[name].push_back(p);

            // Pokemone *p = new Pokemone(std::stoi(tokens.at(0)), tokens.at(1), tokens.at(2), std::stod(tokens.at(5)), std::stod(tokens.at(6)), std::stod(tokens.at(7)), std::stoi(tokens.at(10)));

            this->addNewPokemon(p);
            // std::cout<<"----------- add new pokemone ------------"<<std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

//--------------------------------- By ID and By Name V1---------------------------------
// get pokemone by name
Pokemon *Pokedex::getPokemonByName(std::string name)
{
    for (auto pok : Pokedex::getPokdexInstance()->getPokemons())
    {
        if (pok->getName() == name)
        {
            return pok;
        }
    }
    return nullptr;
}
// get pokemone by id
Pokemon *Pokedex::getPokemonById(int id)
{
    for (auto pok : Pokedex::getPokdexInstance()->getPokemons())
    {
        if (pok->getId() == id)
        {
            return pok;
        }
    }
    return nullptr;
}
//--------------------------------- By ID and By Name V1---------------------------------

//--------------------------------- By ID and By Name V2---------------------------------
// get pokemone by name
Pokemon *Pokedex::getPokemonByIdNewV(int id)
{
    if (Pokedex::pokemonsById.count(id) > 0)
    {
        return Pokedex::pokemonsById[id].at(0);
    }
    return nullptr;
}

// get pokemone by id
Pokemon *Pokedex::getPokemonByNameNewV(std::string name)
{
    if (Pokedex::pokemonsByName.count(name) > 0)
    {
        return Pokedex::pokemonsByName[name].at(0);
    }
    return nullptr;
}

//--------------------------------- By ID and By Name V2---------------------------------

//--------------------------------- By ID and By Name V3---------------------------------
// get pokemone by name
std::vector<Pokemon *> Pokedex::getPokemonByIdNewVAllInstance(int id)
{
    if (Pokedex::pokemonsById.count(id) > 0)
    {
        return Pokedex::pokemonsById[id];
    }
    return {};
}

// get pokemone by id
std::vector<Pokemon *> Pokedex::getPokemonByNameNewVAllInstance(std::string name)
{
    std::vector<Pokemon *> allpokemons;
    for (Pokemon *p : this->getPokemons())
    {
        if (p->getName().find(name) != std::string::npos)
        {
            allpokemons.push_back(p);
        }
    }
    return allpokemons;
}

//--------------------------------- By ID and By Name V2---------------------------------
Pokedex *Pokedex::getPokdexInstance()
{
    if (Pokedex::pokedexInstance)
    {
        return Pokedex::pokedexInstance;
    }
    std::string fileName = "./ressources/pokedex.csv";
    Pokedex *p = new Pokedex(fileName);
    return p;
}
