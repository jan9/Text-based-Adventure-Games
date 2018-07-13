/*********************************************************************
 ** Filename: Player.cpp
 ** Author: Ju Hye An
 ** Date: 12/6/16
 ** Description: Contains the implementation of the Player class member
 ** functions.
 *********************************************************************/

#include "Player.hpp"

/*********************************************************************
 ** Function: Player::Player()
 ** Description: Constructor
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: Memory allocated for backpack
 *********************************************************************/
Player::Player() {
    backpack = new Inventory();
    item1 = "";
    item2 = "";
    item3 = "";
}

/*********************************************************************
 ** Function: Player::getLocation()
 ** Description: Returns Space* location
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
Space* Player::getLocation() {
    return location;
}

/*********************************************************************
 ** Function: Player::setLocation()
 ** Description: Sets Space pointer as location
 ** Parameters: Space* space
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
void Player::setLocation(Space* space) {
    location = space;
}

/*********************************************************************
 ** Function: Player::getItem1()
 ** Description: Returns string item1
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
string Player::getItem1(){
    return item1;
}

/*********************************************************************
 ** Function: Player::getItem2()
 ** Description: Returns string item2
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
string Player::getItem2(){
    return item2;
}

/*********************************************************************
 ** Function: Player::getItem3()
 ** Description: Returns string item3
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
string Player::getItem3(){
    return item3;
}

/*********************************************************************
 ** Function: Player::setItem1()
 ** Description: Sets string questItem as string item1
 ** Parameters: string questItem
 ** Pre-Conditions: string questItem must exist
 ** Post-Conditions: n/a
 *********************************************************************/
void Player::setItem1(string questItem) {
    item1 = questItem;
}

/*********************************************************************
 ** Function: Player::setItem2()
 ** Description: Sets string questItem as string item2
 ** Parameters: string questItem
 ** Pre-Conditions: string questItem must exist
 ** Post-Conditions: n/a
 *********************************************************************/
void Player::setItem2(string questItem){
    item2 = questItem;

}

/*********************************************************************
 ** Function: Player::setItem3()
 ** Description: Sets string questItem as string item3
 ** Parameters: string questItem
 ** Pre-Conditions: string questItem must exist
 ** Post-Conditions: n/a
 *********************************************************************/
void Player::setItem3(string questItem) {
    item3 = questItem;
}

/*********************************************************************
 ** Function: Player::getInventory()
 ** Description: Returns backpack
 ** Parameters: n/a
 ** Pre-Conditions: Inventory* backpack must exist
 ** Post-Conditions: n/a
 *********************************************************************/
Inventory* Player::getInventory() {
    return backpack;
}

/*********************************************************************
 ** Function: Player::~Player()
 ** Description: Destructor 
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
Player::~Player() {
    delete backpack;
   // backpack = NULL;
   // delete location;
   // location = NULL;
}
