#include "Game.h"
#include "state_pattern/h_files/Wait.h"

std::vector<Player *> Game::players;
Game::Game()
{
    setState(new Wait());
}

std::vector<Player *> Game::getPlayers()
{
    return players;
}
void Game::addPlayer(Player *player)
{
    players.push_back(player);
}

void Game::setState(State *state)
{
    gameSate = state;
}
void Game::request()
{
    gameSate->handel();
}

Game::~Game()
{
    for (auto p : players)
    {
        delete p;
    }
    delete pokedex;
    delete gameSate;
    std::cout << "\033[1;3;31m------------- End of Game ------------- \033[0m" << std::endl;
}
