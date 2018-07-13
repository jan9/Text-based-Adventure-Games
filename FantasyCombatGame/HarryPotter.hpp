/*********************************************************************
 ** Filename: HarryPotter.hpp
 ** Author: Ju Hye An
 ** Date: 11/21/16
 ** Description: Contains the derived Harry Potter class definition and
 ** member declarations.
 *********************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Creature.hpp"

class HarryPotter : public Creature {
    
private:
    
public:
    HarryPotter(string, string);
    ~HarryPotter();
    int attack();
    void defend(int);
    
    
};


#endif
