/*********************************************************************
 ** Filename: Vampire.cpp
 ** Author: Ju Hye An
 ** Date: 11/21/16
 ** Description: Contains the implementation of the Vampire class
 ** member functions.
 *********************************************************************/
#include "Creature.hpp"
#include "Vampire.hpp"

/*********************************************************************
 ** Function: Vampire::Vampire()
 ** Description: Constructs a Vampire object, intializing all member
 ** variables inherited from the Creature class.
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: all member variables are initialized
 *********************************************************************/
Vampire::Vampire(string charName, string teamName) {
    armor = 1;
    strength = 18;
    damageTaken = 0;
    attackVal = 0;
    defenseVal = 0;
    lives = 1;
    name = charName;
    type = "The Vampire";
    team = teamName;
    numDiceAttack = 1;
    numSidesAttack = 12;
    numDiceDefense = 1;
    numSidesDefense = 6;
}

/*********************************************************************
 ** Function: Vampire::~Vampire()
 ** Description: Destructor for Vampire class
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
Vampire::~Vampire() {
    
}

/*********************************************************************
 ** Function: Vampire::attack()
 ** Description: Determines the amount of the attack for the current
 ** round and returns it.
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: sum of attack dice rolls is returned
 *********************************************************************/
int Vampire::attack() {
    
    attackVal = diceRoll(numDiceAttack, numSidesAttack);
    
    return attackVal;
    
}

/*********************************************************************
 ** Function: Vampire::defend()
 ** Description: Determines the amount of the defense for the current
 ** round and calculates damage done. Then, it sets the new strength
 ** value. Vampire's special power, Charm, is also implemented here.
 ** Parameters: none
 ** Pre-Conditions: Vampire class's attack int value
 ** Post-Conditions: Strength is changed, depending on the damage
 *********************************************************************/
void Vampire::defend(int attack) {
    
    int charm = diceRoll(1, 2); // Generate random number 1 or 2.
    defenseVal = 1000;
    if (charm == 2) {
        cout << " " << name << " " << type;
        cout << " has charmed his opponent into not attacking him this round." << endl;
        return;
    }
    
    defenseVal = diceRoll(numDiceDefense, numSidesDefense);
    
    int damageTaken = (attack - armor) - defenseVal;
    if (damageTaken > 0 && charm == 1) {
        strength -= damageTaken;
    }
    
    
    if (strength <= 0) {
        cout << " " << name << " " << type << " has died." << endl;
        lives = 0;
    }
    
}
