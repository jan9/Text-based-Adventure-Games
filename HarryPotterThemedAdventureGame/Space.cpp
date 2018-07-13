/*********************************************************************
 ** Filename: Space.cpp
 ** Author: Ju Hye An
 ** Date: 12/6/16
 ** Description: Contains the implementation of the Space class
 ** member functions.
 *********************************************************************/
#include <iostream>
#include "Space.hpp"

/*********************************************************************
 ** Function: Space::Space()
 ** Description: Constructor for Space class
 ** Parameters: string n
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
Space::Space(std::string n){
    name = n;
    HogwartsExpress = NULL;
    GreatHall = NULL;
    ForbiddenForrest = NULL;
    HospitalWing = NULL;
    QuidditchPitch = NULL;
    HeadmastersOffice = NULL;
    GryffindorCommons = NULL;
    DefenseAgainsttheDarkArts = NULL;
}

/*********************************************************************
 ** Function: Space::setGreatHall()
 ** Description: A Space pointer points to the "GreatHall" pointer.
 ** Parameters: Space* place
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
void Space::setGreatHall(Space* place){
    GreatHall = place;
}

/*********************************************************************
 ** Function: Space::setForbiddenForrest()
 ** Description: A Space pointer points to the "ForbiddenForrest" pointer.
 ** Parameters: Space* place
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
void Space::setForbiddenForrest(Space* place){
    ForbiddenForrest = place;
}

/*********************************************************************
 ** Function: Space::setHospitalWing()
 ** Description: A Space pointer points to the "HospitalWing" pointer.
 ** Parameters: Space* place
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
void Space::setHospitalWing(Space* place){
    HospitalWing = place;
}

/*********************************************************************
 ** Function: Space::setQuidditchPitch()
 ** Description: A Space pointer points to the "QuidditchPitch" pointer.
 ** Parameters: Space* place
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
void Space::setQuidditchPitch(Space* place){
    QuidditchPitch = place;
}

/*********************************************************************
 ** Function: Space::setHogwartsExpress()
 ** Description: A Space pointer points to the "HogwartsExpress" pointer.
 ** Parameters: Space* place
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
void Space::setHogwartsExpress(Space* place){
    HogwartsExpress = place;
}

/*********************************************************************
 ** Function: Space::setHeadmastersOffice()
 ** Description: A Space pointer points to the "HeadmastersOffice" pointer.
 ** Parameters: Space* place
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
void Space::setHeadmastersOffice(Space* place){
    HeadmastersOffice = place;
}

/*********************************************************************
 ** Function: Space::setGryffindorCommons()
 ** Description: A Space pointer points to the "GryffindorCommons" pointer.
 ** Parameters: Space* place
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
void Space::setGryffindorCommons(Space* place){
    GryffindorCommons = place;
}

/*********************************************************************
 ** Function: Space::setDefenseAgainsttheDarkArts()
 ** Description: A Space pointer points to the "DefenseAgainsttheDarkArts" pointer.
 ** Parameters: Space* place
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
void Space::setDefenseAgainsttheDarkArts(Space* place){
    DefenseAgainsttheDarkArts = place;
}

/*********************************************************************
 ** Function: Space::setName()
 ** Description: Sets user string input as name.
 ** Parameters: string n
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
void Space::setName(string n){
    name = n;
}

/*********************************************************************
 ** Function: Space::getName()
 ** Description: Returns name
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
string Space::getName(){
    return name;
}

/*********************************************************************
 ** Function: Space::~Space()
 ** Description: Deconstructor
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
Space::~Space(){
    
}
