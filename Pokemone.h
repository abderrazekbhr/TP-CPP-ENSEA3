#include<iostream>
#pragma once
class Pokemone
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
    Pokemone();
    Pokemone(const int id, const std::string name, const std::string game, const double hitPoint, const double attack, const double defence, const int generation);
    Pokemone(Pokemone &p);
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
    void attackEn(const Pokemone p);
    static int getNbInstance();
    ~Pokemone();
};