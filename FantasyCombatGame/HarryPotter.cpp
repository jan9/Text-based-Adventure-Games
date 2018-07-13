/*********************************************************************
 ** Filename: HarryPotter.cpp
 ** Author: Ju Hye An
 ** Date: 11/21/16
 ** Description: Contains the derived Harry Potter class definition and
 ** member declarations.
 *********************************************************************/

#include "Creature.hpp"
#include "HarryPotter.hpp"

/*********************************************************************
 ** Function: HarryPotter::HarryPotter()
 ** Description: Constructs a Harry Potter object, intializing all member
 ** variables inherited from the Creature class.
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: all member variables are initialized
 *********************************************************************/
HarryPotter::HarryPotter(string charName, string teamName) {
    armor = 0;
    strength = 10;
    lives = 2;
    damageTaken = 0;
    attackVal = 0;
    defenseVal = 0;
    name = charName;
    type = "The Harry Potter";
    team = teamName;
    numDiceAttack = 2;
    numSidesAttack = 6;
    numDiceDefense = 2;
    numSidesDefense = 6;
}

/*********************************************************************
 ** Function: HarryPotter::~HarryPotter()
 ** Description: Destructor for HarryPotter class
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
HarryPotter::~HarryPotter() {
    
}

/*********************************************************************
 ** Function: HarryPotter::attack()
 ** Description: Determines the amount of the attack for the current
 ** round and returns it.
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: sum of attack dice rolls is returned
 *********************************************************************/
int HarryPotter::attack() {
    
    attackVal = diceRoll(numDiceAttack, numSidesAttack);
    
    return attackVal;
    
    
}

/*********************************************************************
 ** Function: HarryPotter::defend()
 ** Description: Determines the amount of the defense for the current
 ** round and calculates damage done. Then, it sets the new strength
 ** value.
 ** Parameters: none
 ** Pre-Conditions: HarryPotter class's attack value
 ** Post-Conditions: Strength is changed, depending on the damage
 *********************************************************************/
void HarryPotter::defend(int attack) {
    
    defenseVal = diceRoll(numDiceDefense, numSidesDefense);
    
    int damageTaken = (attack - armor) - defenseVal;
    
    if (damageTaken > 0) {
        strength -= damageTaken;
        
    }
    
    if (strength <= 0 && lives == 2) {
        strength = 20;
        lives = 1;
        cout << "******* HOGWARTS USED ******* " << endl;
        cout << " " << name << " " << type << " dies but magically recovers! He gained new strength" << endl;
    }
    
    else if (strength <= 0) {
        strength = 0;
        cout << " " << name << " " << type << " is unable to recover, and he dies." << endl;
        lives = 0;
    }
    
}
