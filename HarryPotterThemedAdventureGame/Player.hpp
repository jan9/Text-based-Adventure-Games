/*********************************************************************
 ** Filename: Player.hpp
 ** Author: Ju Hye An
 ** Date: 12/6/16
 ** Description: Contains the Player class definition and member declarations.
 *********************************************************************/
#ifndef Player_hpp
#define Player_hpp
#include <string>
using std::string;

#include "Inventory.hpp"

//class Inventory;
class Space;

class Player {
private:
    Space* location;
    Inventory* backpack;
    string item1;
    string item2;
    string item3;
    
public:
    Player();
    void setLocation(Space *space);
    void setItem1(string);
    void setItem2(string);
    void setItem3(string);
    
    Space* getLocation();
    string getItem1();
    string getItem2();
    string getItem3();
    string getName();

    Inventory* getInventory();
    ~Player();
};

#endif /* Player_hpp */
