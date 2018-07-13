/*********************************************************************
 ** Filename: BlueMen.cpp
 ** Author: Ju Hye An
 ** Date: 11/21/16
 ** Description: Contains the implementation of the Blue Men class
 ** member functions.
 *********************************************************************/

#include "Creature.hpp"
#include "BlueMen.hpp"

/*********************************************************************
 ** Function: BlueMen::BlueMen()
 ** Description: Constructs a Blue Men object, intializing all member
 ** variables inherited from the Blue Men class.
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: all member variables are initialized
 *********************************************************************/
BlueMen::BlueMen(string charName, string teamName) {
    armor = 3;
    strength = 12;
    damageTaken = 0;
    attackVal = 0;
    defenseVal = 0;
    lives = 1;
    mob = 2;
    name = charName;
    team = teamName;
    type = "The Blue Men";
    numDiceAttack = 2;
    numSidesAttack = 10;
    numDiceDefense = 3;
    numSidesDefense = 6;
}

/*********************************************************************
 ** Function: BlueMen::~BlueMen()
 ** Description: Destructor for Barbarian class
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
BlueMen::~BlueMen() {
    
}


/*********************************************************************
 ** Function: BlueMen::attack()
 ** Description: Determines the amount of the attack for the current
 ** round and returns it.
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: sum of attack dice rolls is returned
 *********************************************************************/
int BlueMen::attack() {
    attackVal = diceRoll(numDiceAttack, numSidesAttack);
    
    return attackVal;
    
    
}

/*********************************************************************
 ** Function: BlueMen::defend()
 ** Description: Determines the amount of the defense for the current
 ** round and calculates damage done. Then, it sets the new strength
 ** value.
 ** Parameters: none
 ** Pre-Conditions: BlueMen class's attack int value
 ** Post-Conditions: Strength is changed, depending on the damage
 *********************************************************************/
void BlueMen::defend(int attack) {
    
    defenseVal = diceRoll(numDiceDefense, numSidesDefense);
    
    damageTaken = (attack - armor) - defenseVal;
    
    if (damageTaken > 0 ) {
        strength -= damageTaken;
    }
    if (strength <= 8 && mob == 2) {
        numDiceDefense--;
        cout << " Oh no! A member of the BlueMen mob dies. Their defense is now reduced." << endl;
        cout << "NEW Mob Status: " << mob + 1 << endl;
        cout << "Number of defense dice: " << numDiceDefense << endl;
        --mob;
        
        
    }
    if (strength <= 4 && mob == 1) {
        numDiceDefense--;
        cout << " Oh no! Another member of the BlueMen mob dies. Their defense is now reduced." << endl;
        cout << "NEW Mob Status: " << mob + 1 << endl;
        cout << "Number of defense dice: " << numDiceDefense << endl;
        --mob;
    }
    
    if (strength <= 0) {
        strength = 0;
        cout << " " << name << " " << type << " has died." << endl;
        lives = 0;
    }
    
}
