/*********************************************************************
 ** Filename: Creature.hpp
 ** Author: Ju Hye An
 ** Date: 11/21/16
 ** Description: Contains the abstract Creature class definition and
 ** member declarations. This is the base class.
 *********************************************************************/


#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

class Creature {
    
protected:
    int armor;
    int strength;
    int damageTaken;
    int attackVal;
    int defenseVal;
    int lives;
    string name;
    string type;
    string team;
    
    int numDiceAttack;
    int numSidesAttack;
    int numDiceDefense;
    int numSidesDefense;
    
    
public:
    Creature();
    virtual ~Creature();
    string getName();
    string getType();
    int getattackVal();
    int getDefenseVal();
    virtual int attack() = 0;
    virtual void defend(int) = 0;
    bool isDead();
    int diceRoll(int, int);
    int getStrength();
    int getArmor();
    int recovery();
    int getDamageTaken();
    
    
public:
    
};




#endif
