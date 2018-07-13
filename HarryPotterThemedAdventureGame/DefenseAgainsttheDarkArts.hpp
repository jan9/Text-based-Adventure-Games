/*********************************************************************
 ** Filename: DefenseAgainsttheDarkArts.hpp
 ** Author: Ju Hye An
 ** Date: 12/6/16
 ** Description: Contains the derived DefenseAgainsttheDarkArts class 
 ** definition and member declarations.
 *********************************************************************/
#ifndef DefenseAgainsttheDarkArts_hpp
#define DefenseAgainsttheDarkArts_hpp
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "Space.hpp"
#include "Player.hpp"
#include "Item.hpp"
#include "Inventory.hpp"

class DefenseAgainsttheDarkArts : public Space {
private:
    bool examNotTaken = true;
public:
    DefenseAgainsttheDarkArts(): Space("Defense Against the Dark Arts Room") {};
    void specialAction(Player* player);
    void displaySpace();
    ~DefenseAgainsttheDarkArts();
};

#endif /* DefenseAgainsttheDarkArts_hpp */
