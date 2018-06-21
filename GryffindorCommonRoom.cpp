/*********************************************************************
 ** Filename: GryffindorCommonRoom.cpp
 ** Author: Ju Hye An
 ** Date: 12/6/16
 ** Description: Contains the implementation of the GryffindorCommonRoom class
 ** member functions.
 *********************************************************************/
#include "GryffindorCommonRoom.hpp"

/*********************************************************************
 ** Function: GryffindorCommonRoom::displaySpace()
 ** Description: Displays the location name using ASCII art
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
void GryffindorCommonRoom::displaySpace() {
    cout << endl;
    cout << "    +-++-++-++-++-++-++-++-++-++-+" << endl;
    cout << "    |G||r||y||f||f||i||n||d||o||r|" << endl;
    cout << "    +-++-++-++-++-++-++-++-++-++-+" << endl;
    cout << "                    +-++-++-++-++-++-+ +-++-++-++-+" << endl;
    cout << "                    |C||o||m||m||o||n| |R||o||o||m|" << endl;
    cout << "                    +-++-++-++-++-++-+ +-++-++-++-+" << endl;
    cout << endl;    
}

/*********************************************************************
 ** Function: GryffindorCommonRoom.hpp::specialAction()
 ** Description: Contains special actions for the GryffindorCommonRoom
 **              location
 ** Parameters: Player* player
 ** Pre-Conditions: user has to chose GryffindorCommonRoom as their 
 **                  next location
 ** Post-Conditions: user will obtain Tri-Wizard Cup trophy and a suitcase,
 **                 and will be taken to a different location
 *********************************************************************/
void GryffindorCommonRoom::specialAction(Player* player) {
    cout << "You see Ron and Hermione conversing in the common room.\n";
    cout << "They are your best friends so you tell them about the mission\n";
    cout << "Dumbledore asked you to complete." << endl;
    if (player->getInventory()->getNumItems() != 0) {
        if (hasItem) {
            char choice;
            cout << endl;
            cout << "Would you like to show them the items you found to your friends?" << endl;
            cout << "=========================================================" << endl;
            cout << "=              Show Items You Found So Far              =" << endl;
            cout << "=========================================================" << endl;
            cout << "Enter a number:" << endl;
            cout << " [Y] to show all the items in your backpack.\n";
            cout << " [Any other key] to continue." << endl;
            cout << "=========================================================" << endl;
            cout << "Your selection: ";
            cin >> choice;
            if (choice == 'Y'|| choice == 'y') {
                cout << endl;
                cout << "[Harry Potter] 'Here are the items that I have so far: " << endl;
                player->getInventory()->display();
                int num;
                char choice1;
                cout << endl;
                cout << "[Hermione] 'Wow, you found all these? That's awesome!" << endl;
                cout << "Ron and I would love to help you! Would you like us to" << endl;
                cout << "give us an item that you don't want?' " << endl;
                cout << "=========================================================" << endl;
                cout << "=                  Remove an Item                       =" << endl;
                cout << "=========================================================" << endl;
                cout << "Enter a letter:" << endl;
                cout << " [Y] to save an Item with Ron and Hermione.\n";
                cout << " [Any other key] to continue." << endl;
                cout << "=========================================================" << endl;
                cout << "Your selection: ";
                cin >> choice1;
                if (choice1 == 'Y'|| choice1 == 'y') {
                    cout << endl;
                    cout << "[Ron] 'Type the number of Item that you wish us to give us: ";
                    cin >> num;
                    keep = player->getInventory()->findItem(num)->getItem();
                    cout << "***< ITEM REMOVED! Harry Potter gives " << keep << " to Ron and Hermione. >***" << endl;
                    player->getInventory()->removeItem(num);
                    cout << "[Hermione & Ron] 'Good luck on completing your mission!'" << endl;
                    cout << "[Harry Potter] 'Thanks guys!'" << endl;
                    hasItem = false;
                    
                    cout << endl;
                    cout << "Harry Potter looks around the Common Room and two objects\n";
                    cout << "caught Harry Potter's eyes.";
                    cout << "[Harry Potter] 'Hmmm, I better put thses in my inventory.'" << endl;
                    player->getInventory()->addItem(trophy);
                    player->setItem1("Tri-Wizard Cup Trophy");
                    cout << "***< ITEM ADDED! Harry Potter obtains Tri-Wizard Cup Trophy >***" << endl;
                    player->getInventory()->addItem(suitcase);
                    cout << "***< ITEM ADDED! Harry Potter obtains Suitcase >***" << endl;
                }
                else {
                    cout << endl;
                    cout << "[Ron] 'Cool item(s)!! Good luck on completing your mission!'" << endl;
                    cout << "[Harry Potter] 'Thanks Ron!'" << endl;
                    hasItem = true;
                    cout << endl;
                    cout << "Harry Potter looks around the Common Room and two objects\n";
                    cout << "caught Harry Potter's eyes.";
                    cout << "[Harry Potter] 'Hmmm, I better put thses in my inventory.'" << endl;
                    player->getInventory()->addItem(trophy);
                    player->setItem1("Tri-Wizard Cup Trophy");
                    cout << "***< ITEM ADDED! Harry Potter obtains Tri-Wizard Cup Trophy >***" << endl;
                    player->getInventory()->addItem(suitcase);
                    cout << "***< ITEM ADDED! Harry Potter obtains Suitcase >***" << endl;
                }
            }
        }
    }
    else if (player->getInventory()->getNumItems() == 0) {
        cout << endl;
        cout << "[Ron] 'Good luck on completing your mission!'" << endl;
        cout << "[Hermione] 'If you have any unwanted items, come see us!'" << endl;
        cout << "[Harry Potter] 'Thanks Ron and Hermione!'" << endl;
    }
    cout << endl;
    int choice3;
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
    cin >> choice3;
    while (choice3 < 1 || choice3 > 5 || !cin) {
        cout << "Invalid selection, please try again" << endl;
        cin >> choice3;
        cin.clear();
        cin.ignore(100, '\n');
    }
    switch (choice3) {
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
 ** Function: GryffindorCommonRoom::getKeep()
 ** Description: Returns a string stored in keep
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
string GryffindorCommonRoom::getKeep() {
    return keep;
}

/*********************************************************************
 ** Function: GryffindorCommonRoom::~GryffindorCommonRoom()
 ** Description: Deconstructor
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
GryffindorCommonRoom::~GryffindorCommonRoom() {
   /* returnItem = NULL;
    delete returnItem;
    suitcase = NULL;
    delete suitcase;
    trophy = NULL;
    delete trophy;*/
}
