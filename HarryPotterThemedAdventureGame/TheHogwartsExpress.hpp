/*********************************************************************
 ** Filename: TheHogwartsExpress.hpp
 ** Author: Ju Hye An
 ** Date: 12/6/16
 ** Description: Contains the derived TheHogwartsExpress class definition and
 ** member declarations.
 *********************************************************************/
#ifndef TheHogwartsExpress_hpp
#define TheHogwartsExpress_hpp
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "Space.hpp"
#include "Player.hpp"
#include "Item.hpp"
#include "Inventory.hpp"

class TheHogwartsExpress : public Space {
private:
    Item* item;
    bool letterNotDelivered;
    
public:
    TheHogwartsExpress(): Space("The Hogwarts Express") {
        item = new Item("Letter");
        letterNotDelivered = true;
    }
    void specialAction(Player* player);
    void displaySpace();
    ~TheHogwartsExpress();
};

#endif /* TheHogwartsExpress_hpp */
