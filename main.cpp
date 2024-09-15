// <------- libraries ------>
#include <iostream>
// <------- classes ------>
#include "Pokedex.h"
#include "Pokeball.h"
#include "SetOfPokemon.h"
#include "Pokemon.h"
#include "Game.h"
#include "Player.h"
#include "PokemonParty.h"
// <------- state pattern ------>
#include "./state_pattern/h_files/Wait.h"
#include "./state_pattern/h_files/Init.h"
#include "./state_pattern/h_files/SafeExploration.h"
#include "./state_pattern/h_files/Exploration.h"
#include "./state_pattern/h_files/Combat.h"
#include "./state_pattern/h_files/Result.h"
int secondMain()
{
    std::string name = "Volcanion";
    int id = 1;
    Pokedex *p = Pokedex::getPokdexInstance();
    Pokemon *searcbByName = p->getPokemonByNameNewV(name);
    Pokemon *searcbByID = p->getPokemonByIdNewV(id);
    if (searcbByName != nullptr)
    {
        std::cout << "Search by name= " << name << ":" << std::endl;
        searcbByName->displayInfo();
    }
    else
    {
        std::cout << "Pokemon called " << name << " found" << std::endl;
    }
    if (searcbByID != nullptr)
    {
        std::cout << "Search by ID= " << id << ":" << std::endl;
        searcbByID->displayInfo();
    }
    else
    {
        std::cout << "Pokemon with id " << id << " found" << std::endl;
    }
    Pokeball *pokeball = new Pokeball();
    pokeball->addNewPokemon(searcbByName);
    pokeball->addNewPokemon(searcbByID);
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
    State *state;


    // Attente state is created when the game is created
    // handel function is called by calling the request function
    // the setState function is called to change the state
    Game *gamePlay =new Game();
    gamePlay->request();
    // init state is created
    state = new Init();
    gamePlay->setState(state);
    gamePlay->request();
    for (size_t i = 0; i < 3; i++)
    {

        do
        {
            // SafeExploration state is created
            state = new SafeExploration();
            gamePlay->setState(state);
            gamePlay->request();

            // Exploration state is created
            state = new Exploration();
            gamePlay->setState(state);
            gamePlay->request();
            // check if the player wants to combat
            std::cin >> doYouWantToCombat;
        } while (doYouWantToCombat == "No");
        PokemonParty *party = new PokemonParty(playerId1, playerId2, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5});
        // Combat state is created
        state=new Combat(party);
        gamePlay->setState(state);
        gamePlay->request();
    }

    // Result state is created
    gamePlay->setState(new Result());
    gamePlay->request();
    delete gamePlay;
    return 0;
}
