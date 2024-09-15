#include "../h_files/Combat.h"

Combat::Combat(PokemonParty *party)
{
    this->party = party;
}
void Combat::handel()
{
    std::cout << "\033[1;3;31m------------- Combat started ------------- \033[0m" << std::endl;

    party->fullbattle();
}
