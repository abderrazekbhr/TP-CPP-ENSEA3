#pragma once
#include "./state_pattern/h_files/State.h"
#include "Pokedex.h"
#include "Player.h"
class Game
{
private:
    State* gameSate;
    Pokedex* pokedex;
    static std::vector<Player*> players;
public:

public:
    Game();
    static void addPlayer(Player* player);
    static std::vector<Player*> getPlayers();
    void setState(State *state);
    void request();
    
    ~Game();

};

