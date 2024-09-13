#include "../h_files/Combat.h"

Combat::Combat(PokemonParty *party)
{
    this->party = party;
}
void Combat::handle()
{
    std::cout << "Combat started" << std::endl;
    party->fullbattle();
    
}
