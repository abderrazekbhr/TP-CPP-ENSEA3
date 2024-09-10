#include <iostream>
#include "Pokedex.h"
void firstMain()
{
    Pokemone p;
    Pokemone p1(1,"", "game 1", 30, 10.0, 1.2, 10);
    Pokemone p2 = p;
    
    
    std::cout << "----- display -----" << std::endl;
    //----- display -----
    p.displayInfo();
    p1.displayInfo();
    p2.displayInfo();
    // ----- display -----
    
    p.setAttack(14.47);
    p.setGame("game o.o");
    p1.attackEn(p);
    // ----- changes -----
    // ----verify attack-----
    p.displayInfo();
    // ----verify attack-----
    
    // ---- get nb instance ----
    std::cout <<"nb_instance="<<Pokemone::getNbInstance() << std::endl;
    // ---- get nb instance ----

}
int main(){
    std::string name="Volcanion";
    int id=1;
    Pokedex *p=Pokedex::getPokdexInstance();
    Pokemone *searcbByName= p->getPokemoneByNameNewV(name);
    Pokemone *searcbByID=p->getPokemoneByIdNewV(id);
    if(searcbByName!=nullptr){
        std::cout<<"Search by name= "<<name<<":" <<std::endl;
        searcbByName->displayInfo();
    }
    else{
        std::cout<<"Pokemone called "<<name <<" found"<<std::endl;
    }
    if(searcbByID!=nullptr){
        std::cout<<"Search by ID= "<<id<<":" <<std::endl;
        searcbByID->displayInfo();
    }
    else{
        std::cout<<"Pokemone with id "<<id <<" found"<<std::endl;
    }
    // p->affiche();
    return 0;   
}