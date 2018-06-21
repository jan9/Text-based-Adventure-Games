/*********************************************************************
 ** Filename: QuidditchPitch.cpp
 ** Author: Ju Hye An
 ** Date: 12/6/16
 ** Description: Contains the implementation of the QuidditchPitch class
 ** member functions.
 *********************************************************************/
#include "QuidditchPitch.hpp"

/*********************************************************************
 ** Function: TheHogwartsExpress::displaySpace()
 ** Description: Displays the location name using ASCII art
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
void QuidditchPitch::displaySpace() {
    cout << endl;
    cout << "    +-++-++-++-++-++-++-++-++-+ +-++-++-++-++-+" << endl;
    cout << "    |Q||u||i||d||d||i||t||c||h| |P||i||t||c||h|" << endl;
    cout << "    +-++-++-++-++-++-++-++-++-+ +-++-++-++-++-+" << endl;
    cout << endl;
}

/*********************************************************************
 ** Function: QuidditchPitch::specialAction()
 ** Description: Contains special actions for the QuidditchPitch location
 ** Parameters: Player* player
 ** Pre-Conditions: user has to chose QuidditchPitch as their next location
 ** Post-Conditions: user will obtain a broomstick named Firebolt,
 **                  and will be taken to a different location
 *********************************************************************/
void QuidditchPitch::specialAction(Player* player) {
    if (getBroomstick) {
        char choice;
        cout << "You play the position of seeker in Gryffindor's Quidditch Team." << endl;
        cout << "You see Oliver Wood, the Captain of the Gryffindor Team,\n";
        cout << "practicing Quidditch alone." << endl;
        cout << "=========================================================" << endl;
        cout << "=              What would you like to do?               =" << endl;
        cout << "=========================================================" << endl;
        cout << "Enter a letter:" << endl;
        cout << " [Y] Join Oliver and practice catching the Golden Snitch\n";
        cout << " [Any other key] Don't join Oliver and continue" << endl;
        cout << "=========================================================" << endl;
        cout << "Your selection: ";
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            cout << "[Harry Potter] 'Hey Oliver, can I join you?'" << endl;
            cout << "[Oliver Wood] 'Yes! Potter, go get your broomstick, Firebolt,\n";
            cout << "               and come join me!" << endl;
            cout << endl;
            cout << "You bring out your Firebolt from the locker room and \n";
            cout << "practice Quidditch for a while." << endl;
            player->getInventory()->addItem(broomstick);
            cout << "***< ITEM ADDED! Harry Potter obtains Firebolt >***" << endl;
            player->setItem2("Firebolt");
            getBroomstick = false;
        }
        else {
            cout << endl;
            cout << "You choose to observe Oliver practicing." << endl;
            getBroomstick = true;
        }
    }
    else {
        cout << endl;
        cout << "The rain is pouring down. The Quidditch Pitch is empty." << endl;
    }
    cout << endl;
    int choice1;
    cout << "=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=" << endl;
    cout << "=              Where would you like to go now?              =" << endl;
    cout << "=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=" << endl;
    cout << "1. The Great Hall" << endl;
    cout << "2. Hospital Wing" << endl;
    cout << "3. Forbidden Forrest" << endl;
    cout << "4. Gryffindor Common Room" << endl;
    cout << "5. View backpack contents" << endl;
    cout << "=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=" << endl;
    cout << "Your selection: ";
    cin >> choice1;
    while (choice1 < 1 || choice1 > 5 || !cin) {
        cout << "Invalid selection, please try again" << endl;
        cin >> choice1;
        cin.clear();
        cin.ignore(300, '\n');
    }
    switch (choice1) {
        case 1:
            player->setLocation(GreatHall);
            break;
        case 2:
            player->setLocation(HospitalWing);
            break;
        case 3:
            player->setLocation(ForbiddenForrest);
            break;
        case 4:
            player->setLocation(GryffindorCommons);
            break;
        case 5:
            player->getInventory()->display();
            break;
    }
}

/*********************************************************************
 ** Function: QuidditchPitch::~QuidditchPitch()
 ** Description: Deconstructor
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
QuidditchPitch::~QuidditchPitch() {
  /*  broomstick = NULL;
    delete broomstick;*/
}
