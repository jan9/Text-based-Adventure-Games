/*********************************************************************
 ** Filename: HeadmastersOffice.hpp
 ** Author: Ju Hye An
 ** Date: 12/6/16
 ** Description: Contains the derived HeadmastersOffice class definition and
 ** member declarations.
 *********************************************************************/
#ifndef HeadmastersOffice_hpp
#define HeadmastersOffice_hpp
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "Space.hpp"
#include "Player.hpp"
#include "Item.hpp"
#include "Inventory.hpp"


class HeadmastersOffice : public Space {
private:
    bool firstMeeting;
public:
    HeadmastersOffice(): Space("Headmaster's Office") {
        firstMeeting = true;
    };
    void specialAction(Player* player);
    void displaySpace();
    ~HeadmastersOffice();
};

#endif /* HeadmastersOffice_hpp */
