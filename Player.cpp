#include "Player.h"
#include <iostream>
#include <string>

Player::Player(std::string name)
{
    points = 0;
    this->name = name;
    myballs = new Pokeball();
}
std::string Player::getName()
{
    return name;
}
Pokeball *Player::getPokeball()
{
    return myballs;
}

void Player::addPokemon(Pokemon *pokemon)
{
    myPokemonsForBattle.push_back(pokemon);
}

std::vector<Pokemon *> Player::getMyPokemonsForBattle()
{
    return myPokemonsForBattle;
}
int Player::getPoints()
{
    return points;
}

void Player::addPoint()
{
    this->points += 1;
}

Player::~Player()
{
    std::cout << "Player destructor called" << std::endl;
    delete myballs;
}