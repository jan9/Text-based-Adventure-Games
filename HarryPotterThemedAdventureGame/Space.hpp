/*********************************************************************
 ** Filename: Space.hpp
 ** Author: Ju Hye An
 ** Date: 12/6/16
 ** Description: Contains the abstract Space class definition and
 ** member declarations.
 *********************************************************************/
#ifndef Space_hpp
#define Space_hpp

#include <string>
using std::string;
#include "Player.hpp"

class Space {
protected:
    string name;
    Space* HogwartsExpress;
    Space* GreatHall;
    Space* ForbiddenForrest;
    Space* HospitalWing;
    Space* QuidditchPitch;
    Space* HeadmastersOffice;
    Space* GryffindorCommons;
    Space* DefenseAgainsttheDarkArts;
    
public:
    // constructor
    Space(string);
    
    // pure virtual function
    virtual void specialAction(Player* player) = 0;
    virtual void displaySpace() = 0;
    
    // setters and getters
    void setGreatHall(Space*);
    void setForbiddenForrest(Space*);
    void setHospitalWing(Space*);
    void setQuidditchPitch(Space*);
    void setHogwartsExpress(Space*);
    void setHeadmastersOffice(Space*);
    void setGryffindorCommons(Space*);
    void setDefenseAgainsttheDarkArts(Space*);
    void setName(string n);
    string getName();

    // destructor
    virtual ~Space();
};

#endif /* Space_hpp */
