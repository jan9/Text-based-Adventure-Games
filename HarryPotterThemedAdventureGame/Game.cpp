/*********************************************************************
 ** Filename: Game.cpp
 ** Author: Ju Hye An
 ** Date: 12/6/16
 ** Description: Contains the implementation of the Game class member
 ** functions.
 *********************************************************************/
#include "Game.hpp"

/*********************************************************************
 ** Function: Game::Game()
 ** Description: Constructor
 ** Parameters: n/a
 ** Pre-Conditions: Space class and its derived classes must exist
 ** Post-Conditions: Game object initialized
 *********************************************************************/
Game::Game() {
    // POINTERS TO DERIVED CLASSES
    train = new TheHogwartsExpress();
    greatHall = new TheGreatHall();
    forrest = new ForbiddenForrest();
    hospital = new HospitalWing();
    field = new QuidditchPitch();
    commonRoom = new GryffindorCommonRoom();
    classRoom = new DefenseAgainsttheDarkArts();
    office = new HeadmastersOffice();
    // HOGWARTS EXPRESS
    train->setGreatHall(greatHall);
    train->setGryffindorCommons(commonRoom);
    train->setForbiddenForrest(forrest);
    train->setHeadmastersOffice(office);
    // THE GREAT HALL
    greatHall->setForbiddenForrest(forrest);
    greatHall->setHospitalWing(hospital);
    greatHall->setDefenseAgainsttheDarkArts(classRoom);
    greatHall->setGryffindorCommons(commonRoom);
    // FORBIDDEN FORREST
    forrest->setQuidditchPitch(field);
    forrest->setHospitalWing(hospital);
    forrest->setDefenseAgainsttheDarkArts(classRoom);
    forrest->setHeadmastersOffice(office);
    // HOSPITAL
    hospital->setGryffindorCommons(commonRoom);
    hospital->setQuidditchPitch(field);
    hospital->setDefenseAgainsttheDarkArts(classRoom);
    hospital->setHeadmastersOffice(office);
    // QUIDDITCH PITCH
    field->setGreatHall(greatHall);
    field->setHospitalWing(hospital);
    field->setForbiddenForrest(forrest);
    field->setGryffindorCommons(commonRoom);
    // GRYFFINDOR COMMON ROOM
    commonRoom->setQuidditchPitch(field);
    commonRoom->setHospitalWing(hospital);
    commonRoom->setDefenseAgainsttheDarkArts(classRoom);
    commonRoom->setHeadmastersOffice(office);
    // DEFENSE AGAINST THE DARK ARTS
    classRoom->setQuidditchPitch(field);
    classRoom->setHospitalWing(hospital);
    classRoom->setGreatHall(greatHall);
    classRoom->setHeadmastersOffice(office);
    // HEADMASTER'S OFFICE
    office->setGreatHall(greatHall);
    office->setHospitalWing(hospital);
    office->setDefenseAgainsttheDarkArts(classRoom);
    office->setGryffindorCommons(commonRoom);
    // PLAYER OBJECT INITIALIZED
    player = new Player();
    player->setLocation(train);
}

/*********************************************************************
 ** Function: Game::play()
 ** Description: Each run of the game
 ** Parameters: n/a
 ** Pre-Conditions: Space and its derived classes must exist
 ** Post-Conditions: print mission success or mission failed
 *********************************************************************/
void Game::play() {
    Space* currentlocation;
    int movesLeft = 32;
    bool questComplete = false;

    while (movesLeft > 0) {
        cout << endl;
        movesLeft--;
        // Move counter starts when Harry gets off the train
        if ((movesLeft < 31 && movesLeft > -1) && (questComplete == false)) {
        cout << "===================" << endl;
        cout << "  Moves left: " << movesLeft << endl;
        cout << "===================" << endl;
        }
        currentlocation = player->getLocation();
        currentlocation->displaySpace();
        currentlocation->specialAction(player);
        
        if (((player->getItem1()) == "Tri-Wizard Cup Trophy")&& ((player->getItem2()) == "Firebolt")&& ((player->getItem3()) == "Unicorn's Blood")) {
            questComplete = true;
            cout << endl;
            cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << endl;
            cout << "   MISSION SUCCESS: Harry found all the items" << endl;
            cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << endl;
            cout << "[Harry Potter] Here you go Professor Dumbledore!" << endl;
            cout << "[Dumbledore] Thank you Harry for your great help!" << endl;
            cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << endl;
            cout << endl;
            return;
        }
        
        if (movesLeft == 0) {
            cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << endl;
            cout << "   MISSION FAILED: Harry ran out of time" << endl;
            cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << endl;
            cout << " [Voldemort] I am coming for you Harry Potter!\n";
            cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << endl;
            return;
        }
    }
}

/*********************************************************************
 ** Function: Game::~Game()
 ** Description: Destructor for Game object
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
Game::~Game() {
    delete train;
    train = NULL;
    delete greatHall;
    greatHall = NULL;
    delete forrest;
    forrest = NULL;
    delete hospital;
    hospital = NULL;
    delete field;
    field = NULL;
    delete commonRoom;
    commonRoom = NULL;
    delete classRoom;
    classRoom = NULL;
    delete office;
    office = NULL;
    delete player;
    player = NULL;
}
