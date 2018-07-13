/*********************************************************************
 ** Filename: BlueMen.hpp
 ** Author: Ju Hye An
 ** Date: 11/21/16
 ** Description: Contains the derived Blue Men class definition and
 ** member declarations.
 *********************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Creature.hpp"

class BlueMen : public Creature {
    
private:
    int mob;
    
public:
    BlueMen(string, string);
    ~BlueMen();
    int attack();
    void defend(int);
    
    
};


#endif
