/*********************************************************************
 ** Filename: Barbarian.cpp
 ** Author: Ju Hye An
 ** Date: 11/21/16
 ** Description: Contains the implementation of the Barbarian class
 ** member functions.
 *********************************************************************/
#include "Barbarian.hpp"

/*********************************************************************
 ** Function: Barbarian::Barbarian()
 ** Description: Constructs a Barbarian object, intializing all member
 ** variables inherited from the Creature class.
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: all member variables are initialized
 *********************************************************************/
Barbarian::Barbarian(string charName, string teamName) {
    armor = 0;
    strength = 12;
    damageTaken = 0;
    attackVal = 0;
    defenseVal = 0;
    lives = 1;
    name = charName;
    type = "The Barbarian";
    team = teamName;
    numDiceAttack = 2;
    numSidesAttack = 6;
    numDiceDefense = 2;
    numSidesDefense = 6;
}

/*********************************************************************
 ** Function: Barbarian::~Barbarian()
 ** Description: Destructor for Barbarian class
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
Barbarian::~Barbarian() {
    
}

/*********************************************************************
 ** Function: Barbarian::attack()
 ** Description: Determines the amount of the attack for the current
 ** round and returns it.
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: sum of attack dice rolls is returned
 *********************************************************************/
int Barbarian::attack() {
    
    attackVal = diceRoll(numDiceAttack, numSidesAttack);
    
    return attackVal;
    
}

/*********************************************************************
 ** Function: Barbarian::defend()
 ** Description: Determines the amount of the defense for the current
 ** round and calculates damage done. Then, it sets the new strength
 ** value.
 ** Parameters: n/a
 ** Pre-Conditions: Barbarian class's attack int value
 ** Post-Conditions: Strength is changed, depending on the damage
 *********************************************************************/
void Barbarian::defend(int attack) {
    
    defenseVal = diceRoll(numDiceDefense, numSidesDefense);
    
    damageTaken = (attack - armor) - defenseVal;
    
    if (damageTaken > 0) {
        strength -= damageTaken;
    }
    
    if (strength <= 0) {
        strength = 0;
        cout << " " << name << " " << type << " has died." << endl;
        lives = 0;
    }
    
}
