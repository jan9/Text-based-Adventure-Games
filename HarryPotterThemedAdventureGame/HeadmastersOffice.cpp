/*********************************************************************
 ** Filename: HeadmastersOffice.cpp
 ** Author: Ju Hye An
 ** Date: 12/6/16
 ** Description: Contains the implementation of the HeadmastersOffice
 ** class member functions.
 *********************************************************************/
#include "HeadmastersOffice.hpp"

/*********************************************************************
 ** Function: HeadmastersOffice::displaySpace()
 ** Description: Displays the location name using ASCII art
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
void HeadmastersOffice::displaySpace() {
    cout << endl;
    cout << "   +-++-++-++-++-++-++-++-++-++-++-++-+" << endl;
    cout << "   |H||e||a||d||m||a||s||t||e||r||'||s|" << endl;
    cout << "   +-++-++-++-++-++-++-++-++-++-++-++-+" << endl;
    cout << "                                   +-++-++-++-++-++-+" << endl;
    cout << "                                   |O||f||f||i||c||e|" << endl;
    cout << "                                   +-++-++-++-++-++-+" << endl;
    cout << endl;
}


/*********************************************************************
 ** Function: HeadmastersOffice::specialAction()
 ** Description: Contains special actions for the HospitalWing location
 ** Parameters: Player* player
 ** Pre-Conditions: user has to chose HospitalWing as their next location
 ** Post-Conditions: user will obtain recovery portion and strengthening
 **                  portion, and will be taken to a different location
 *********************************************************************/
void HeadmastersOffice::specialAction(Player* player) {
    cout << "'knock, knock, knock'" << endl;
    cout << "Harry Potter enters the Headmaster's Office." << endl;
    cout << endl;
    
    // FIRST ENCOUNTER WITH DUMBLEDORE
    if (firstMeeting) {
        cout << "[Dumbledore] 'Oh Harry, exactly the person I wanted to see." << endl;
        cout << "I heard from the Order of Phenoix this morning that" << endl;
        cout << "He-who-must-not-be-named is leaving portkeys around Hogwarts.'" << endl;
        cout << endl;
        cout << "If don't find the portkeys, dementors will teleport themselves" << endl;
        cout << "to the school and it will jeopardize the safety of students." << endl;
        cout << endl;
        cout << "'I need you to help me search the entire Hogwarts grounds and" << endl;
        cout << "find 3 items that we have found to be portkeys: " << endl;
        cout << "\t1. Tri-Wizard Cup Trophy\n";
        cout << "\t\tHINT: Captain of the last Hogwarts's Team is in Gryffindor.\n";
        cout << "\t2. Unicorn's Blood\n";
        cout << "\t\tHINT: Unicorns often appear in the Forbidden Forrest.\n";
        cout << "\t3. A broomstick\n";
        cout << "\t\tHINT: You ride this to play Quidditch, right?\n";
        cout << "You might be required to do some special actions. Good luck!'" << endl;
        cout << endl;
        firstMeeting = false;
    }
        else {
            cout << "But Professor Dumbledore not in sight." << endl;
            cout << endl;
            cout << "( A pheonix brings a scrolled message to you and you read it ) " << endl;
            cout << "()-----------------------------------------------------------()" << endl;
            cout << "||                                                           ||" << endl;
            cout << "||  Dear Harry,                                              ||" << endl;
            cout << "||                                                           ||" << endl;
            cout << "||  Remember to search the ENTIRE Hogwarts grounds and look  ||" << endl;
            cout << "||  for the following items. You might be required to do     ||" << endl;
            cout << "||  some special actions in order to obtain the items.       ||" << endl;
            cout << "||  The itmes that you need find are:                        ||" << endl;
            cout << "||   1. Tri-Wizard Cup Trophy                                ||" << endl;
            cout << "||    (Captain of the last Hogwarts's Team is in Gryffindor) ||" << endl;
            cout << "||   2. Unicorn's Blood                                      ||" << endl;
            cout << "||    (Unicorns often appear in the Forbidden Forrest)       ||" << endl;
            cout << "||   3. A broomstick                                         ||" << endl;
            cout << "||    (You ride this to play Quidditch, right?)              ||" << endl;
            cout << "||                                                           ||" << endl;
            cout << "||                                                           ||" << endl;
            cout << "||                           - Professor Dumbledore          ||" << endl;
            cout << "||                                                           ||" << endl;
            cout << "()-----------------------------------------------------------()" << endl;
            cout << endl;
        }
    cout << endl;
    cout << "=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=" << endl;
    cout << "=              Where would you like to go now?              =" << endl;
    cout << "=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=" << endl;
    cout << "1. The Great Hall" << endl;
    cout << "2. Hospital Wing" << endl;
    cout << "3. Defense Against the Dark Arts Room" << endl;
    cout << "4. Gryffindor Common Room" << endl;
    cout << "5. View backpack contents" << endl;
    cout << "=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=" << endl;
    cout << "Your selection: ";
    int choice1;
    cin >> choice1;
    while (choice1 < 1 || choice1 > 5 || !cin) {
        cout << "Invalid selection, please try again" << endl;
        cin >> choice1;
        cin.clear();
        cin.ignore(100, '\n');
    }
    switch (choice1) {
        case 1:
            player->setLocation(GreatHall);
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
 ** Function: HeadmastersOffice::~HeadmastersOffice()
 ** Description: Deconstructor
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
HeadmastersOffice::~HeadmastersOffice() {
    // LEFT BLANK
}
