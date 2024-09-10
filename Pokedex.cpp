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
            // std::cout<<"----------- instanciate new pokemone ------------"<<std::endl;
            Pokemone *p = new Pokemone(std::stoi(tokens.at(0)), tokens.at(1), tokens.at(2), std::stod(tokens.at(5)), std::stod(tokens.at(6)), std::stod(tokens.at(7)), std::stoi(tokens.at(10)));
            this->addNewPokemone(p);
            // std::cout<<"----------- add new pokemone ------------"<<std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

Pokemone *Pokedex::getPokemoneByName(std::string name)
{
    for (auto pok : Pokedex::getPokdexInstance()->getPokemones())
    {
        if (pok->getName() == name)
        {
            return pok;
        }
    }
    return nullptr;
}
Pokemone *Pokedex::getPokemoneById(int id)
{
    for (auto pok : Pokedex::getPokdexInstance()->getPokemones())
    {
        if (pok->getId() == id)
        {
            return pok;
        }
    }
    return nullptr;
}

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
