/*********************************************************************
 ** Filename: ForbiddenForrest.cpp
 ** Author: Ju Hye An
 ** Date: 12/6/16
 ** Description: Contains the implementation of the ForbiddenForrest class
 ** member functions.
 *********************************************************************/
#include "ForbiddenForrest.hpp"

/*********************************************************************
 ** Function: ForbiddenForrest::displaySpace()
 ** Description: Displays the location name using ASCII art
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
void ForbiddenForrest::displaySpace() {
    cout << endl;
    cout << "   +-++-++-++-++-++-++-++-++-+ +-++-++-++-++-++-++-+" << endl;
    cout << "   |F||o||r||b||i||d||d||e||n| |F||o||r||r||e||s||t|" << endl;
    cout << "   +-++-++-++-++-++-++-++-++-+ +-++-++-++-++-++-++-+" << endl;
    cout << endl;
}

/*********************************************************************
 ** Function: ForbiddenForrest::specialAction()
 ** Description: Contains special actions for the ForbiddenForrest location
 ** Parameters: Player* player
 ** Pre-Conditions: user has to chose ForbiddenForrest as their next location
 ** Post-Conditions: user will obtain unicorn's blood, and will be taken to
 ***                 a different location
 *********************************************************************/
void ForbiddenForrest::specialAction(Player* player) {
    if (ub_NotTaken) {
        char choice;
        cout << "Deep in the Forbidden Forrest, an old centaur appears." << endl;
        cout << "You ask Bane the Centaur where to find Unicorn's Blood." << endl;
        cout << "The centaur makes a deal with you. He says he will get Unicorn's\n";
        cout << "Blood for you if you can get Strengthening Solution first." << endl;
        cout << "=========================================================" << endl;
        cout << "=              What would you like to do?               =" << endl;
        cout << "=========================================================" << endl;
        cout << "Enter a number:" << endl;
        cout << " [Y] Trade the solution for Unicorn's Blood." << endl;
        cout << " [Any other key] Don't trade and continue." << endl;
        cout << "=========================================================" << endl;
        cout << "Your selection: ";
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            if (player->getInventory()->getNumItems()!=0) {
                bool tryagain = true;
                while (tryagain == true) {
                    int num;
                    string have;
                    player->getInventory()->display();
                    cout << "=========================================================" << endl;
                    cout << "Select an Item number to trade or enter -1 to exit: " << endl;
                    cin >> num;
                    if (num == -1) {
                        break;
                    }
                    cout << endl;
                    have = player->getInventory()->findItem(num)->getItem();
                    if (have == "Strengthening Solution") {
                        cout << "You trade Strengthening Solution for Unicorn's Blood!" << endl;
                        player->getInventory()->removeItem(num);
                        cout << "***< ITEM REMOVED! Harry Potter removes " << have << " >***" << endl;
                        player->getInventory()->addItem(unicornBlood);
                        cout << "***< ITEM ADDED! Harry Potter obtains Unicorn's Blood >***" << endl;
                        player->setItem3("Unicorn's Blood");
                        tryagain = false;
                        cout << endl;
                    }
                    else {
                        cout << "That's not Strengthening Solution! He won't accept that!" << endl;
                        cout << endl;
                    }
                }
            }
        }
    }
    else {
        cout << "No creatures at sight. It's Eerie here.\n Let's go somewhere else." << endl;
        cout << endl;
    }
    
    // NEXT LOCATION
    cout << endl;
    int choice1;
    cout << "=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=" << endl;
    cout << "=              Where would you like to go now?              =" << endl;
    cout << "=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=" << endl;
    cout << "1. Quidditch Pitch" << endl;
    cout << "2. Hospital Wing" << endl;
    cout << "3. Defense Against the Dark Arts Room" << endl;
    cout << "4. Headmaster's Office" << endl;
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
            player->setLocation(QuidditchPitch);
            break;
        case 2:
            player->setLocation(HospitalWing);
            break;
        case 3:
            player->setLocation(DefenseAgainsttheDarkArts);
            break;
        case 4:
            player->setLocation(HeadmastersOffice);
            break;
        case 5:
            player->getInventory()->display();
            break;
    }
}

/*********************************************************************
 ** Function: ForbiddenForrest::~ForbiddenForrest()
 ** Description: Deconstructor
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
ForbiddenForrest::~ForbiddenForrest(){
  //  unicornBlood = NULL;
   // delete unicornBlood;
}
