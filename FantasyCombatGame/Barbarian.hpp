/*********************************************************************
 ** Filename: Barbarian.hpp
 ** Author: Ju Hye An
 ** Date: 11/21/16
 ** Description: Contains the derived Barbarian class definition and
 ** member declarations.
 *********************************************************************/


#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Creature.hpp"


class Barbarian : public Creature {
    
private:
    
public:
    Barbarian(string, string);
    ~Barbarian();
    int attack();
    void defend(int);
    
};

#endif
