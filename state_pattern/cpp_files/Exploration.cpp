#include <iostream>
#include "../h_files/Exploration.h"
#include "../h_files/SafeExploration.h"
#include <iostream>
void Exploration::handel()
{
    std::cout << "\033[1;3;31m------------- Enter combat? Tap 'Yes' to proceed or 'No' to keep exploring. -------------\033[0m" << std::endl;
}

Exploration::~Exploration()
{
    std::cout << "Exploration ended" << std::endl;
}
