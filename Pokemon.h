#include<iostream>
#pragma once
class Pokemon
{
private:
    int id;
    std::string name;
    std::string game;
    double hitPoint;
    double attack;
    double defence;
    int generation;
    static int instance; 
    /* data */
public:
    Pokemon();
    Pokemon(const int id, const std::string name, const std::string game, const double hitPoint, const double attack, const double defence, const int generation);
    Pokemon(Pokemon &p);
    const void displayInfo();
    const int getId();
    const std::string getGame();
    void setGame(std::string nameOfTheGame);
    const double getHitPoint();
    void setHitPoint(const double hitPoint);
    const double getAttack();
    void setAttack(const double attack);
    const double getDefence();
    void setDefence(const double defence);
    const int getGeneration();
    void setGeneration(const int generation);
    std::string getName();
    void setName(const std::string newName);
    void attackEnemy(Pokemon* p);
    static int getNbInstance();
    ~Pokemon();
};