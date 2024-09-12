#include "Game.h"
#include "state_pattern/h_files/Attente.h"

std::vector<Player*> Game::players;
Game::Game()
{
    setState(new Attente());
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
    gameSate->handle();
}

Game::~Game()
{
    delete gameSate;
    std::cout << "End of Game (Game deleted)" << std::endl;
}
