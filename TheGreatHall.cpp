/*********************************************************************
 ** Filename: TheGreatHall.cpp
 ** Author: Ju Hye An
 ** Date: 12/6/16
 ** Description: Contains the implementation of the TheGreatHall class
 ** member functions.
 *********************************************************************/
#include "TheGreatHall.hpp"

/*********************************************************************
 ** Function: TheGreatHall::displaySpace()
 ** Description: Displays the location name using ASCII art
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
void TheGreatHall::displaySpace() {
    cout << endl;
    cout << "   +-++-++-+ +-++-++-++-++-+ +-++-++-++-+" << endl;
    cout << "   |T||h||e| |G||r||e||a||t| |H||a||l||l|" << endl;
    cout << "   +-++-++-+ +-++-++-++-++-+ +-++-++-++-+" << endl;
    cout << endl;
}

/*********************************************************************
 ** Function: TheGreatHall::specialAction()
 ** Description: Contains special actions for the TheGreatHall
 ** Parameters: Player* player
 ** Pre-Conditions: user has to chose the the Great Hall as the next
 **                 location
 ** Post-Condition: user can obtain an owl lantern, floating candle, 
 **          or a sorting hat, and will be taken to a different location
 *********************************************************************/
void TheGreatHall::specialAction(Player* player) {
    // First encounter
    if (tournamentNotDone) {
        char choice;
        cout << "There is a Dueling tournament taking place in the Great Hall.\n";
        cout << "The ultimate winner will be awarded an Owl Lantern!\n";
        cout << "=========================================================" << endl;
        cout << "=              What would you like to do?               =" << endl;
        cout << "=========================================================" << endl;
        cout << "Enter a letter:" << endl;
        cout << " [Y] Participate in the tournament." << endl;
        cout << " [Any other key] Don't participate and continue." << endl;
        cout << "=========================================================" << endl;
        cout << "Your selection: ";
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            cout << "You choose to participate in the tournament. \n";
            cout << "And ... you have made it to the final round!" << endl;
            cout << endl;
            cout << "[Announcer] 'And the winner is .... Harry Potter!!!'" << endl;
            player->getInventory()->addItem(lantern);
            cout << "***< ITEM ADDED! Harry Potter obtains an Owl Lantern >***" << endl;
            tournamentNotDone = false;
        }
        else {
            cout << "You choose not to participate in the tournament.\n";
            cout << "Instead, you carefully search around the Great Hall." << endl;
            cout << endl;
            cout << "[Harry Potter] 'Hmmm... What are those?'" << endl;
            cout << "You find the Sorting Hat and a Floating Candle." << endl;
            player->getInventory()->addItem(hat);
            cout << "***< ITEM ADDED! Harry Potter obtains the Sorting Hat >***" << endl;
            player->getInventory()->addItem(candle);
            cout << "***< ITEM ADDED! Harry Potter obtains a Floating Candle >***" << endl;
            tournamentNotDone = true;
        }
    }
    // If tournament finished
    else {
        cout << endl;
        cout << "The dueling tournament has ended." << endl;
    }
    cout << endl;
    int choice1;
    cout << "=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=" << endl;
    cout << "=              Where would you like to go now?              =" << endl;
    cout << "=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=" << endl;
    cout << "1. Forbidden Forrest" << endl;
    cout << "2. Hospital Wing" << endl;
    cout << "3. Defense Against the Dark Arts Room" << endl;
    cout << "4. Gryffindor Common Room" << endl;
    cout << "5. View backpack contents" << endl;
    cout << "=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=" << endl;
    cout << "Your selection: ";
    cin >> choice1;
    while (choice1 < 1 || choice1 > 5 || !cin) {
        cout << "Invalid selection, please try again" << endl;
        cin >> choice1;
        cin.clear();
        cin.ignore(100, '\n');
    }
    switch (choice1) {
        case 1:
            player->setLocation(ForbiddenForrest);
            break;
        case 2:
            player->setLocation(HospitalWing);
            break;
        case 3:
            player->setLocation(DefenseAgainsttheDarkArts);
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
 ** Function: TheGreatHall::~TheGreatHall()
 ** Description: Deconstructor
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
TheGreatHall::~TheGreatHall(){
   /* hat = NULL;
    delete hat;
    lantern = NULL;
    delete lantern;
    candle = NULL;
    delete candle;
    */
    
}
