/*********************************************************************
 ** Filename: TheHogwartsExpress.cpp
 ** Author: Ju Hye An
 ** Date: 12/6/16
 ** Description: Contains the implementation of the TheHogwartsExpress class
 ** member functions.
 *********************************************************************/
#include "TheHogwartsExpress.hpp"

/*********************************************************************
 ** Function: TheHogwartsExpress::displaySpace()
 ** Description: Displays the location name using ASCII art
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
void TheHogwartsExpress::displaySpace() {
    cout << endl;
    cout << "   +-++-++-+ +-++-++-++-++-++-++-++-+ +-++-++-++-++-++-++-+" << endl;
    cout << "   |T||h||e| |H||o||g||w||a||r||t||s| |E||x||p||r||e||s||s|" << endl;
    cout << "   +-++-++-+ +-++-++-++-++-++-++-++-+ +-++-++-++-++-++-++-+" << endl;
    cout << endl;
}

/*********************************************************************
 ** Function: TheHogwartsExpress::specialAction()
 ** Description: Special actions for the stage is carried out in this
 **              function.
 ** Parameters: Player* player
 ** Pre-Conditions: user has to choose [1] from the main menu
 ** Post-Conditions: user will obtain a letter and will be taken to 
 ***                 a different location
 *********************************************************************/
void TheHogwartsExpress::specialAction(Player* player) {
    if (letterNotDelivered) {
        cout << "You are taking the Hogwarts Express on your way to Hogwarts." << endl;
        cout << endl;
        cout << "[Conductor] 'Welcome back Mr. Potter!'" << endl;
        cout << endl;
        cout << "As you board the train, the conductor greets you\n";
        cout << "and hands you a letter with a Hogwarts seal.\n";
        cout << "=========================================================" << endl;
        cout << "=              What would you like to do?               =" << endl;
        cout << "=========================================================" << endl;
        cout << "Enter a number: \n";
        cout << " [1] Talk to the Conductor and open the letter." << endl;
        cout << " [2] Receive the letter but don't open the letter." << endl;
        cout << "=========================================================" << endl;
        cout << "Your selection: ";
        int choice;
        cin >> choice;
        while (choice < 1 || choice > 2 || !cin) {
            cout << "Invalid selection, please try again" << endl;
            cin >> choice;
            cin.clear();
            cin.ignore(100, '\n');
        }
        player->getInventory()->addItem(item);
        cout << "***< ITEM ADDED! Harry Potter obtains a Letter >***" << endl;
        cout << endl;
        
        // HARRY CHOOSES TO TALK TO THE CONDUCTOR
        if (choice == 1) {
            cout << "[Conductor] 'This letter is from Professor Dumbledore.\n";
            cout << "         He personally asked me to deliver this to you.'" << endl;
            cout << "[Harry Potter] 'Oh, thank you Sir.'" << endl;
            cout << endl;
            cout << " ( You open and read the letter ) " << endl;
            cout << "  ----------------------------------------------------------- " << endl;
            cout << " |                                                           |" << endl;
            cout << " |  Dear Harry,                                              |" << endl;
            cout << " |                                                           |" << endl;
            cout << " |  I hope this letter finds you while you are on your way   |" << endl;
            cout << " |  to the school. As soon as you arrive at Hogwarts,        |" << endl;
            cout << " |  please come see me in my office. I have a favor to ask   |" << endl;
            cout << " |  from you.                                                |" << endl;
            cout << " |                                                           |" << endl;
            cout << " |                                                           |" << endl;
            cout << " |                           - Professor Dumbledore          |" << endl;
            cout << " |                                                           |" << endl;
            cout << "  ----------------------------------------------------------- " << endl;
            cout << endl;
            cout << "[Harry Potter] 'I better go to the Headmaster's Office as soon" << endl;
            cout << "               as the train arrives at Hogwarts.'" << endl;
            letterNotDelivered = false;
            cout << endl;
            cout << "[Conductor] We have arrived at Hogwarts School of Witchcraft and Wizardry!" << endl;
            cout << "Thank you for using the Hogwarts Express. Have a great year of school!" << endl;
        }
        
        // HARRY CHOOSES NOT TO TALK TO THE CONDUCTOR
        else if (choice == 2) {
            cout << "You found an empty compartment on the train and sit down\n";
            cout << "on the seat, but you are extremely tired from staying up late. \n";
            cout << "You decide to take a nap, not opening the letter." << endl;
            letterNotDelivered = false;
            cout << endl;
            cout << "[Conductor] We have arrived at Hogwarts School of Witchcraft" << endl;
            cout << "            and Wizardry! Thank you for using the Hogwarts Express." << endl;
            cout << "            Have a great year of school!" << endl;
        }
    }
        // DECIDE WHERE TO GO NEXT
        cout << endl;
        cout << "=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=" << endl;
        cout << "=              Where would you like to go now?              =" << endl;
        cout << "=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=" << endl;
        cout << "1. The Great Hall" << endl;
        cout << "2. Gryffindor Common Room" << endl;
        cout << "3. Forbidden Forest" << endl;
        cout << "4. Headmaster's Office" << endl;
        cout << "5. View backpack contents" << endl;
        cout << "=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=" << endl;
        cout << "Your selection: ";
        int choice2;
        cin >> choice2;
        while (choice2 < 1 || choice2 > 6 || !cin) {
            cout << "Invalid selection, please try again" << endl;
            cin >> choice2;
            cin.clear();
            cin.ignore(100, '\n');
        }
        switch (choice2) {
            case 1:
                player->setLocation(GreatHall);
                break;
            case 2:
                player->setLocation(GryffindorCommons);
                break;
            case 3:
                player->setLocation(ForbiddenForrest);
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
 ** Function: TheHogwartsExpress::~TheHogwartsExpress()
 ** Description: Deconstructor
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
TheHogwartsExpress::~TheHogwartsExpress(){
    item = NULL;
    delete item;
}


