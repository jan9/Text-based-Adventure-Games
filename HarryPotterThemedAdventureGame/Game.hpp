/*********************************************************************
 ** Filename: Game.hpp
 ** Author: Ju Hye An
 ** Date: 12/6/16
 ** Description: Contains the Game class definition and member declarations.
 *********************************************************************/

#ifndef Game_hpp
#define Game_hpp
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

#include "Space.hpp"
#include "TheHogwartsExpress.hpp"
#include "TheGreatHall.hpp"
#include "ForbiddenForrest.hpp"
#include "HospitalWing.hpp"
#include "QuidditchPitch.hpp"
#include "GryffindorCommonRoom.hpp"
#include "DefenseAgainsttheDarkArts.hpp"
#include "HeadmastersOffice.hpp"
#include "Player.hpp"

class Game {
private:
    string name;
    TheHogwartsExpress* train;
    TheGreatHall* greatHall;
    ForbiddenForrest* forrest;
    HospitalWing* hospital;
    QuidditchPitch* field;
    GryffindorCommonRoom* commonRoom;
    DefenseAgainsttheDarkArts* classRoom;
    HeadmastersOffice* office;
    Player* player;
    
public:
    Game();
    void play();
    ~Game();
};

#endif /* Game_hpp */
