/*********************************************************************
 ** Filename: Medusa.cpp
 ** Author: Ju Hye An
 ** Date: 11/21/16
 ** Description: Contains the derived Medusa class definition and
 ** member declarations.
 *********************************************************************/
#include "Medusa.hpp"

/*********************************************************************
 ** Function: Medusa::Medusa()
 ** Description: Constructs a Medusa object, intializing all member
 ** variables inherited from the Creature class.
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: all member variables are initialized
 *********************************************************************/
Medusa::Medusa (string charName, string teamName) {
    armor = 3;
    strength = 8;
    damageTaken = 0;
    attackVal = 0;
    defenseVal = 0;
    lives = 1;
    name = charName;
    type = "The Medusa";
    team = teamName;
    numDiceAttack = 2;
    numSidesAttack = 6;
    numDiceDefense = 1;
    numSidesDefense = 6;
}

/*********************************************************************
 ** Function: Medusa::~Medusa()
 ** Description: Destructor for Medusa class
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
Medusa::~Medusa() {
    
}

/*********************************************************************
 ** Function: Medusa::attack()
 ** Description: Determines the amount of the attack for the current
 ** round and returns it. Medusa's special power, Glare, is also implemented
 ** here. Glare kills the opponent right away with an attack of 10000;
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: sum of attack dice rolls is returned, Glare is the
 ** dice roll is equal to 12.
 *********************************************************************/
int Medusa::attack() {
    attackVal = 0;
    int glare = 10000;
    
    attackVal = diceRoll(numDiceAttack, numSidesDefense);
    
    if (attackVal == 12) {
        cout << "******* GLARE USED ******* " << endl;
        cout << " Oh no! The target has looked into ";
        cout << name << " " << type << "'s eyes and is turned to stone." << endl;
        return glare;
    }
    
    else {
        return attackVal;
    }
    
}

/*********************************************************************
 ** Function: Medusa::defend()
 ** Description: Determines the amount of the defense for the current
 ** round and calculates damage done. Then, it sets the new strength
 ** value.
 ** Parameters: none
 ** Pre-Conditions: Medusa class's attack value
 ** Post-Conditions: Strength is changed, depending on the damage
 *********************************************************************/
void Medusa::defend(int attack) {
    
    defenseVal = diceRoll(numDiceDefense, numSidesDefense);
    
    int damageTaken = (attack - armor) - defenseVal;
    
    if (damageTaken > 0) {
        strength -= damageTaken;
    }
    
    if (strength <= 0) {
        strength = 0;
        cout << " " << name << " " << type << " has died." << endl;
        lives = 0;
    }
    
}
