#include <iostream>
#include "../h_files/Exploration.h"
#include "../h_files/SafeExploration.h"
#include <iostream>
void Exploration::handle(){
    std::cout<<"Enter combat? Tap 'Yes' to proceed or 'No' to keep exploring."<<std::endl;
}

Exploration::~Exploration(){
    std::cout<<"Exploration ended"<<std::endl;
}

