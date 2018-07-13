/*********************************************************************
 ** Filename: Medusa.hpp
 ** Author: Ju Hye An
 ** Date: 11/21/16
 ** Description: Contains the derived Medusa class definition and
 ** member declarations.
 *********************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Creature.hpp"

class Medusa : public Creature{
    
private:
    
public:
    Medusa(string, string);
    ~Medusa();
    int attack();
    void defend(int);
    
    
};


#endif
