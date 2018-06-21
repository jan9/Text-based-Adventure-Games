/*********************************************************************
 ** Filename: ForbiddenForrest.hpp
 ** Author: Ju Hye An
 ** Date: 12/6/16
 ** Description: Contains the derived ForbiddenForrest class definition and
 ** member declarations.
 *********************************************************************/
#ifndef ForbiddenForrest_hpp
#define ForbiddenForrest_hpp
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "Space.hpp"
#include "Player.hpp"
#include "Item.hpp"
#include "Inventory.hpp"

class ForbiddenForrest : public Space {
private:
    Item* unicornBlood;
    bool ub_NotTaken;
public:
    ForbiddenForrest(): Space("Forbidden Forrest") {
        unicornBlood = new Item("Unicorn's blood");
         ub_NotTaken = true;
    };
    void specialAction(Player* player);
    void displaySpace();
    ~ForbiddenForrest();
};

#endif /* ForbiddenForrest_hpp */
