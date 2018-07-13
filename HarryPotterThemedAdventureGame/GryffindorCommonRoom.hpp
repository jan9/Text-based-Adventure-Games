/*********************************************************************
 ** Filename: GryffindorCommonRoom.hpp
 ** Author: Ju Hye An
 ** Date: 12/6/16
 ** Description: Contains the derived GryffindorCommonRoom class definition and
 ** member declarations.
 *********************************************************************/
#ifndef GryffindorCommonRoom_hpp
#define GryffindorCommonRoom_hpp
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "Space.hpp"
#include "Player.hpp"
#include "Item.hpp"
#include "Inventory.hpp"

class GryffindorCommonRoom : public Space {
private:
    Item* returnItem;
    bool hasItem;
    string keep;
    Item* suitcase;
    Item* trophy;
public:
    GryffindorCommonRoom(): Space("Gryffindor Common Room") {
        suitcase = new Item("Suitcase");
        trophy = new Item("Tri-Wizard Cup Trophy");
        hasItem = true;
    };
    void specialAction(Player* player);
    void displaySpace();
    string getKeep();
    ~GryffindorCommonRoom();
};

#endif /* GryffindorCommonRoom_hpp */
