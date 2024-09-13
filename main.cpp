// <------- libraries ------>
#include <iostream>
// <------- classes ------>
#include "Pokedex.h"
#include "Pokeball.h"
#include "SetOfPokemon.h"
#include "Pokemone.h"
#include "Game.h"
#include "Player.h"
#include "PokemonParty.h"
// <------- state pattern ------>
#include "./state_pattern/h_files/Attente.h"
#include "./state_pattern/h_files/Init.h"
#include "./state_pattern/h_files/SafeExploration.h"
#include "./state_pattern/h_files/Exploration.h"
#include "./state_pattern/h_files/Combat.h"

int secondMain()
{
    std::string name = "Volcanion";
    int id = 1;
    Pokedex *p = Pokedex::getPokdexInstance();
    Pokemone *searcbByName = p->getPokemoneByNameNewV(name);
    Pokemone *searcbByID = p->getPokemoneByIdNewV(id);
    if (searcbByName != nullptr)
    {
        std::cout << "Search by name= " << name << ":" << std::endl;
        searcbByName->displayInfo();
    }
    else
    {
        std::cout << "Pokemone called " << name << " found" << std::endl;
    }
    if (searcbByID != nullptr)
    {
        std::cout << "Search by ID= " << id << ":" << std::endl;
        searcbByID->displayInfo();
    }
    else
    {
        std::cout << "Pokemone with id " << id << " found" << std::endl;
    }
    Pokeball *pokeball = new Pokeball();
    pokeball->addNewPokemone(searcbByName);
    pokeball->addNewPokemone(searcbByID);
    // pokeball->affiche();
    return 0;
}
// <------- main function ------>
int main()
{
    // launch the combat variable
    std::string doYouWantToCombat;
    // define the players id
    int playerId1 = 0;
    int playerId2 = 1;

    // Attente state is created when the game is created
    // handel function is called by calling the request function
    // the setState function is called to change the state
    Game gamePlay = Game();
    gamePlay.request();
    //init state is created
    gamePlay.setState(new Init());
    gamePlay.request();
    do
    {
        // SafeExploration state is created
        gamePlay.setState(new SafeExploration());
        gamePlay.request();
        // Exploration state is created
        gamePlay.setState(new Exploration());
        gamePlay.request();
        // check if the player wants to combat
        std::cin >> doYouWantToCombat;
    } while (doYouWantToCombat == "No");
    
    // Combat state is created
    gamePlay.setState(new Combat(new PokemonParty(playerId1, playerId2, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5})));
    gamePlay.request();
    return 0;
}
/*
g++ ./main.cpp ./Pokedex.cpp ./Pokeball.cpp ./SetOfPokemon.cpp ./Pokemone.cpp ./Game.cpp ./Player.cpp ./PokemonParty.cpp ./state_pattern/cpp_files/Attente.cpp ./state_pattern/cpp_files/Init.cpp ./state_pattern/cpp_files/SafeExploration.cpp ./state_pattern/cpp_files/Exploration.cpp ./state_pattern/cpp_files/Combat.cpp  -o newmain && ./newmain
*/