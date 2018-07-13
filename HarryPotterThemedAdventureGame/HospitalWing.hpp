/*********************************************************************
 ** Filename: HospitalWing.hpp
 ** Author: Ju Hye An
 ** Date: 12/6/16
 ** Description: Contains the derived HospitalWing class definition and
 ** member declarations.
 *********************************************************************/
#ifndef HospitalWing_hpp
#define HospitalWing_hpp
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "Space.hpp"
#include "Player.hpp"
#include "Item.hpp"
#include "Inventory.hpp"

class HospitalWing : public Space {
private:
    Item* recoveryPortion;
    Item* strengthSolution;
    
    
public:
    HospitalWing(): Space("Hospital Wing") {
        recoveryPortion = new Item("Recovery Portion");
        strengthSolution = new Item("Strengthening Solution");
        
    };
    void specialAction(Player* player);
    void displaySpace();
    ~HospitalWing();
};
#endif /* HospitalWing_hpp */
