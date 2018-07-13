
/*********************************************************************
 ** Filename: Creature.cpp
 ** Author: Ju Hye An
 ** Date: 11/21/16
 ** Description: Contains the implementation of the Creature class
 ** member functions.
 *********************************************************************/

#include "Creature.hpp"

/*********************************************************************
 ** Function: Creature::Creature()
 ** Description: Constructor for Creature class
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
Creature::Creature() {
    // INTENTIONALLY LEFT BLANK
}

/*********************************************************************
 ** Function: Creature::~Creature()
 ** Description: Destructor for Creature class
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
Creature::~Creature() {
    
}

/******************************************************************************************
 ** Function: isDead
 ** Description: This function returns a bool value associated with whether or not a given
 **		creature is dead.
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditons: N/A
 ******************************************************************************************/
bool Creature::isDead() {
    if (lives == 0) {
        return true;
    }
    
    else {
        return false;
    }
}

/*********************************************************************
 ** Function: Creature::diceRoll()
 ** Description: Rolls dice with specified sides each, and
 **              returns their sum.
 ** Parameters: int numDice, int numSides
 ** Pre-Conditions: number of dices and sides of specific creature type
 ** Post-Conditions: returns the sum of dice rolls
 *********************************************************************/
int Creature::diceRoll(int numDice, int numSides) {
    int sum = 0;
    for (int i = 0; i < numDice; ++i) {
        sum = sum + ((rand() % numSides) + 1);
    }
    return sum;
}

// GETTER FUNCTIONS

/*********************************************************************
 ** Function: Creature::getStrength()
 ** Description: Returns the strength value of this creature.
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: the strength of this creature is returned
 *********************************************************************/
int Creature::getStrength() {
    return strength;
}

/*********************************************************************
 ** Function: Creature::getName()
 ** Description: Returns the name of this creature's name
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: the name of the user-picked creature
 *********************************************************************/
string Creature::getName() {
    return name;
}

/*********************************************************************
 ** Function: Creature::getType()
 ** Description: Returns the name of this creature's name
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: the name of the user-picked creature
 *********************************************************************/
string Creature::getType() {
    return type;
}

/*********************************************************************
 ** Function: Creature::getDamageTaken()
 ** Description: Returns the damage value of this creature.
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: the damage value of this creature is returned
 *********************************************************************/
int Creature::getDamageTaken() {
    return damageTaken;
}

/*********************************************************************
 ** Function: Creature::getattackVal()
 ** Description: Returns the attack value of this creature.
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: the attack value of this creature is returned
 *********************************************************************/
int Creature::getattackVal() {
    return attackVal;
}

/*********************************************************************
 ** Function: Creature::getDefenseVal()
 ** Description: Returns the defense value of this creature.
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: the defense value of this creature is returned
 *********************************************************************/
int Creature::getDefenseVal() {
    return defenseVal;
}

/*********************************************************************
 ** Function: Creature::getArmor()
 ** Description: Returns the armor value of this creature.
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: the armor value of this creature is returned
 *********************************************************************/
int Creature::getArmor() {
    return armor;
}

/*********************************************************************
 ** Function: Creature::recovery()
 ** Description: Returns the strength value of this creature.
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: the strength of this creature is returned
 *********************************************************************/
int Creature::recovery() {
    int recoverRoll = diceRoll(1, 6);
    if (recoverRoll == 1) { strength = strength + 1;}
    if (recoverRoll == 2) { strength = strength + 2;}
    if (recoverRoll == 3) { strength = strength + 3;}
    if (recoverRoll == 4) { strength = strength + 4;}
    if (recoverRoll == 5) { strength = strength + 5;}
    if (recoverRoll == 6) { strength = strength + 6;}
    return recoverRoll;
}
