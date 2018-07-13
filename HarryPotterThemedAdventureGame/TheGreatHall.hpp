/*********************************************************************
 ** Filename: TheGreatHall.hpp
 ** Author: Ju Hye An
 ** Date: 12/6/16
 ** Description: Contains the derived TheGreatHall class definition and
 ** member declarations.
 *********************************************************************/
#ifndef TheGreatHall_hpp
#define TheGreatHall_hpp
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "Space.hpp"
#include "Player.hpp"
#include "Item.hpp"
#include "Inventory.hpp"

class TheGreatHall : public Space {
private:
    Item* hat;
    Item* lantern;
    Item* candle;
    bool tournamentNotDone;
public:
    TheGreatHall(): Space("The Great Hall") {
        hat = new Item("Sorting Hat");
        lantern = new Item("Owl lantern");
        candle = new Item("Floating Candle");
        tournamentNotDone = true;
    };
    void specialAction(Player* player);
        void displaySpace();
    ~TheGreatHall();
};

#endif /* TheGreatHall_hpp */
