#pragma once
#include "./State.h"
#include "../../PokemonParty.h"

class Combat : public State
{
private:
    PokemonParty *party;
public:
    void handle();
    Combat(PokemonParty *party);
    PokemonParty *getParty();    
    ~Combat();
};