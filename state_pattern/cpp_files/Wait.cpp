#include <iostream>
#include "../h_files/State.h"
#include "../h_files/Wait.h"
#include "../h_files/Init.h"
#include<unistd.h>
void Wait::handel()
{
    std::cout << "\033[1;3;31m------------- Loading Game ------------- \033[0m" << std::endl;
    sleep(2);
}

Wait::~Wait()
{
    // std::cout << "Game Loaded" << std::endl;
}