/*********************************************************************
 ** Filename: Item.hpp
 ** Author: Ju Hye An
 ** Date: 12/6/16
 ** Description: Contains the implementation of the Item class member
 ** functions.
 *********************************************************************/

#include "Item.hpp"

/*********************************************************************
 ** Function: Item::Item(string)
 ** Description: Item class constructor. It initializes input string as
 **              string item
 ** Parameters: string str
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
Item::Item(string str) {
    item = str;
}

/*********************************************************************
 ** Function: string Item::getItem()
 ** Description: Returns string item
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
string Item::getItem() {
    return item;
}

/*********************************************************************
 ** Function: Item::~Item()
 ** Description: Item class destructor
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
Item::~Item() {
    // LEFT BLANK
}
