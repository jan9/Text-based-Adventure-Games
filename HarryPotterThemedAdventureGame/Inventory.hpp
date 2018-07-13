/*********************************************************************
 ** Filename: Inventory.hpp
 ** Author: Ju Hye An
 ** Date: 12/6/16
 ** Description: Contains the Inventory class definition and member 
 ** declarations.
 *********************************************************************/

#ifndef Inventory_hpp
#define Inventory_hpp

#include <string>
using std::string;
#include <iostream>
using std::endl;
using std::cout;

#include "Item.hpp"

class Inventory {
protected:
    int numItems;
    int maxItems;
    Item* items[11];
    
public:
    Inventory();
    void addItem(Item*);
    void removeItem(int);
    void display();
    Item* findItem(int);
    int getNumItems();
    ~Inventory();
};

#endif /* Inventory_hpp */
