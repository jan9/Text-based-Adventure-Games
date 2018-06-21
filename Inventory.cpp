/*********************************************************************
 ** Filename: Inventory.cpp
 ** Author: Ju Hye An
 ** Date: 12/6/16
 ** Description: Contains the implementation of the Item class member
 ** member functions.
 *********************************************************************/
#include <iostream>
#include "Inventory.hpp"

/*********************************************************************
 ** Function: Inventory::Inventory()
 ** Description: Inventory class constructor
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: Initializes Inventory objects as NULL
 *********************************************************************/
Inventory::Inventory() {
    numItems = 1;
    maxItems = 11;
    for (int i = 1; i < maxItems; i++) {
        items[i] = NULL;
    }
}

/*********************************************************************
 ** Function: Inventory::addItem()
 ** Description: Adds item to inventory list
 ** Parameters: Item* newitem
 ** Pre-Conditions: Item must be created before adding
 ** Post-Conditions: Item added to inventory
 *********************************************************************/
void Inventory::addItem(Item* newitem) {
    items[numItems] = newitem;
    if (numItems == 9) {
        cout << endl;
        cout << "BACKPACK IS ALMOST FULL!\nYou can only add 1 more item." << endl;
        cout << endl;
    }
    if (numItems == maxItems) {
        removeItem(numItems);
        cout << "BACKPACK IS FULL!\nNo more Item can be added." << endl;
        cout << endl;
    }
    numItems++;
}

/*********************************************************************
 ** Function: Inventory::removeItem()
 ** Description: Removes item from inventory list
 ** Parameters: int item_number
 ** Pre-Conditions: Item location must exist
 ** Post-Conditions: Item removed from inventory and next items move up
 *********************************************************************/
void Inventory::removeItem(int item_number) {
    if (items[item_number] != NULL) {
        delete items[item_number];
        items[item_number] = NULL;
        int next = item_number + 1;
        while (next < maxItems && items[next] != NULL) {
            items[item_number] = items[next];
            items[next] = NULL;
            ++item_number;
            ++next;
        }
        --numItems;
    }
}

/*********************************************************************
 ** Function: Inventory::display()
 ** Description: Displays inventory list
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: a list of inventory displayed on console
 *********************************************************************/
void Inventory::display() {
    // 1 - 11 array numbers so 1 is zeroth
    if (numItems == 1) {
        cout << " -------------------------------------------------------" << endl;
        cout << "[               Harry Potter's Backpack                 ]" << endl;
        cout << " -------------------------------------------------------" << endl;
        cout << "NO ITEMS FOUND!" << endl;
    }
    else {
        cout << " -------------------------------------------------------" << endl;
        cout << "[               Harry Potter's Backpack                 ]" << endl;
        cout << " -------------------------------------------------------" << endl;
        for (int i = 1; i < numItems; i++) {
            cout << i << ": " << items[i]->getItem() << endl;
        }
    }
}

/*********************************************************************
 ** Function: Inventory::findItem()
 ** Description: Finds the item from inventory and is returned.
 ** Parameters: int item_number
 ** Pre-Conditions: Item location must exist
 ** Post-Conditions: n/a
 *********************************************************************/
Item* Inventory::findItem(int item_number){
    if (numItems == 1) {
        cout << " -------------------------------------------------------" << endl;
        cout << "[               Harry Potter's Backpack                 ]" << endl;
        cout << " -------------------------------------------------------" << endl;
        cout << "NO ITEMS FOUND!" << endl;
        return 0;
    }
    else {
        Item *tempItem = items[item_number];
        return tempItem;
    }
}

/*********************************************************************
 ** Function: Inventory::getNumItems()
 ** Description: Returns numItems
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
int Inventory::getNumItems() {
    return numItems;
}

/*********************************************************************
 ** Function: Inventory::~Inventory()
 ** Description: Destructor
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: Deallocate memory 
 *********************************************************************/
Inventory::~Inventory() {
    for (int i = 1; i < maxItems; i++) {
        if (items[i] != NULL) {
            delete items[i];
            items[i] = NULL;
        }
    }
}
