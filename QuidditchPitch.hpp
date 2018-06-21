/*********************************************************************
 ** Filename: QuidditchPitch.hpp
 ** Author: Ju Hye An
 ** Date: 12/6/16
 ** Description: Contains the derived QuidditchPitch class definition and
 ** member declarations.
 *********************************************************************/
#ifndef QuidditchPitch_hpp
#define QuidditchPitch_hpp
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "Space.hpp"
#include "Player.hpp"
#include "Item.hpp"
#include "Inventory.hpp"

class QuidditchPitch : public Space {
private:
    Item* broomstick;
    bool getBroomstick;
public:
    QuidditchPitch(): Space("Quidditch Pitch") {
        broomstick = new Item("Firebolt");
        getBroomstick = true;
    };
    void specialAction(Player* player);
    void displaySpace();
    ~QuidditchPitch();
};

#endif /* QuidditchPitch_hpp */
