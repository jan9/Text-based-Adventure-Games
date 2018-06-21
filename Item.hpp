/*********************************************************************
 ** Filename: Item.hpp
 ** Author: Ju Hye An
 ** Date: 12/6/16
 ** Description: Contains the Item class definition and member declarations.
 *********************************************************************/

#ifndef Item_hpp
#define Item_hpp
#include <string>
using std::string;

class Item {
protected:
    string item;
public:
    Item(string);
    string getItem();
    ~Item();
};
#endif /* Item_hpp */
