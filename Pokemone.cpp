#include <iostream>
#include "Pokemone.h"

int Pokemone::instance=0;
//default constructor
Pokemone::Pokemone(){
    this->id=-1;
    this->name="none";
    this->game="new Game";
    this->hitPoint=1.0;
    this->attack=1.0;
    this->defence=1.0;
    this->generation=0;
    instance+=1;
}

// constructor with params
Pokemone::Pokemone(const int id, const std::string name, const std::string game, const double hitPoint, const double attack, const double defence, const int generation)
{

    this->id = id;
    this->name=name;
    this->game = game;
    this->hitPoint = hitPoint;
    this->attack = attack;
    this->defence = defence;
    this->generation = generation;
    instance+=1;
}

// copy constructor 
Pokemone::Pokemone(Pokemone &p)
{
    this->id = p.getId();
    this->game = p.getGame();
    this->hitPoint = p.getHitPoint();
    this->attack = p.getAttack();
    this->defence = p.getDefence();
    this->generation = p.getGeneration();
    instance+=1;

}


// id Getter 
const int Pokemone::getId()
{
    return this->id;
}

// Game getter and Setter
const std::string Pokemone::getGame()
{
    return this->game;
}
void Pokemone::setGame(std::string nameOfTheGame)
{
    this->game = nameOfTheGame;
}

// hitPoint Getter and Setter
const double Pokemone::getHitPoint()
{
    return this->hitPoint;
}

void Pokemone::setHitPoint(const double hitPoint)
{
    if (hitPoint > 0)
    {
        this->hitPoint = hitPoint;
    }
    else
    {
        this->hitPoint = 0;
    }
};

// atack Getter and Setter
const double Pokemone::getAttack()
{
    return this->attack;
}
void Pokemone::setAttack(const double attack)
{
    if (attack > 0)
    {
        this->attack = attack;
    }
    else
    {
        this->attack = 1;
    }
}

// defence Getter and Setter
const double Pokemone::getDefence()
{
    return this->defence;
}
void Pokemone::setDefence(const double defence)
{
    if (defence > 0)
    {
        this->defence = defence;
    }
    else
    {
        this->defence = 0;
    }
}

// generation Getter and Setter
const int Pokemone::getGeneration()
{
    return this->generation;
}
void Pokemone::setGeneration(const int generation)
{
    if (generation > 0)
    {
        this->generation = generation;
    }
    else
    {
        this->generation = 0;
    }
}


// display all params
const void Pokemone::displayInfo(){
    std::cout<<"id:"<<this->id<<", name:"<<this->name<<", game:"<<this->game<<", hitPoint:"<<this->hitPoint<<", attack:"<<this->attack<<", defence:"<<this->defence<<", generation:" <<this->generation<<std::endl;
}

// attack pokemone
void Pokemone::attackEn(Pokemone p){
    double diff= this->getAttack()-p.getDefence();
    // std::cout<<"--------------"<<diff<<"--------------"<<std::endl;
    if(diff>0){
        p.setHitPoint(p.getHitPoint()-diff);
    }
    
}

int Pokemone::getNbInstance(){
    return Pokemone::instance;
}

//getter and stter of Name
std::string Pokemone::getName(){
    return this->name;
}

void Pokemone::setName(std::string newName){
    this->name=newName;
}

// destructor 
Pokemone::~Pokemone(){
    Pokemone::instance --;
    // std::cout<<"end Pokemone id:"<<this->getId()<<"| and nb_instance:"<<Pokemone::getNbInstance()<<std::endl;

}
