/*********************************************************************
 ** Filename: Vampire.hpp
 ** Author: Ju Hye An
 ** Date: 11/21/16
 ** Description: Contains the derived Vampire class definition and
 ** member declarations.
 *********************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Creature.hpp"

class Vampire : public Creature {
    
private:
    
public:
    Vampire(string, string);
    ~Vampire();
    int attack();
    void defend(int);
    
    
};

#endif
