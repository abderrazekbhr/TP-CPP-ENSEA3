#include "Player.h"
#include "Pokeball.h"
#include <iostream>
#include <string>

Player::Player(std::string name)
{
    
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

void Player::addPokemon(Pokemone *pokemone)
{
    myPokemonsForBattle.push_back(pokemone);
}

std::vector<Pokemone*> Player::getMyPokemonsForBattle()
{
    return myPokemonsForBattle;
}

Player::~Player()
{
    std::cout << "Player destructor called" << std::endl;
    delete myballs;
}