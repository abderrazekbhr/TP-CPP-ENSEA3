#include <iostream>
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
/* 
g++ ./main.cpp ./Pokedex.cpp ./Pokeball.cpp ./SetOfPokemon.cpp ./Pokemone.cpp ./Game.cpp ./Player.cpp ./PokemonParty.cpp ./state_pattern/cpp_files/Attente.cpp ./state_pattern/cpp_files/Init.cpp ./state_pattern/cpp_files/SafeExploration.cpp ./state_pattern/cpp_files/Exploration.cpp ./state_pattern/cpp_files/Combat.cpp  -o newmain && ./newmain

*/
// void firstMain()
// {
//     Pokemone p;
//     Pokemone p1(1, "", "game 1", 30, 10.0, 1.2, 10);
//     Pokemone p2 = p;

//     std::cout << "----- display -----" << std::endl;
//     //----- display -----
//     p.displayInfo();
//     p1.displayInfo();
//     p2.displayInfo();
//     // ----- display -----

//     p.setAttack(14.47);
//     p.setGame("game o.o");
//     p1.attackEn(p);
//     // ----- changes -----
//     // ----verify attack-----
//     p.displayInfo();
//     // ----verify attack-----

//     // ---- get nb instance ----
//     std::cout << "nb_instance=" << Pokemone::getNbInstance() << std::endl;
//     // ---- get nb instance ----
// }
// int secondMain()
// {
//     std::string name = "Volcanion";
//     int id = 1;
//     Pokedex *p = Pokedex::getPokdexInstance();
//     Pokemone *searcbByName = p->getPokemoneByNameNewV(name);
//     Pokemone *searcbByID = p->getPokemoneByIdNewV(id);
//     if (searcbByName != nullptr)
//     {
//         std::cout << "Search by name= " << name << ":" << std::endl;
//         searcbByName->displayInfo();
//     }
//     else
//     {
//         std::cout << "Pokemone called " << name << " found" << std::endl;
//     }
//     if (searcbByID != nullptr)
//     {
//         std::cout << "Search by ID= " << id << ":" << std::endl;
//         searcbByID->displayInfo();
//     }
//     else
//     {
//         std::cout << "Pokemone with id " << id << " found" << std::endl;
//     }
//     Pokeball *pokeball = new Pokeball();
//     pokeball->addNewPokemone(searcbByName);
//     pokeball->addNewPokemone(searcbByID);
//     pokeball->affiche();
//     return 0;
// }

int main()
{

    std::string doYouWantToCombat;
    Game gamePlay = Game();
    gamePlay.request();
    gamePlay.setState(new Init());
    gamePlay.request();
    do
    {
        gamePlay.setState(new SafeExploration());
        gamePlay.request();
        gamePlay.setState(new Exploration());
        gamePlay.request();
        std::cin >> doYouWantToCombat;
    } while (doYouWantToCombat == "No");
    int playerId1 = 0;
    int playerId2 = 1;
    
    gamePlay.setState(new Combat(new PokemonParty(playerId1, playerId2, {1, 2, 3, 4, 5, 6}, {1, 2, 3, 4, 5, 6})));
    gamePlay.request();
    return 0;
}
