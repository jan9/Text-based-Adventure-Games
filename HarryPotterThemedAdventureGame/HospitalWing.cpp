/*********************************************************************
 ** Filename: HospitalWing.cpp
 ** Author: Ju Hye An
 ** Date: 12/6/16
 ** Description: Contains the implementation of the HospitalWing class
 ** member functions.
 *********************************************************************/
#include "HospitalWing.hpp"
#include <ctime>
#include <cstdlib>

/*********************************************************************
 ** Function: HospitalWing::displaySpace()
 ** Description: Displays the location name using ASCII art
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
void HospitalWing::displaySpace() {
    cout << endl;
    cout << "   +-++-++-++-++-++-++-++-+ +-++-++-++-+" << endl;
    cout << "   |H||o||s||p||i||t||a||l| |W||i||n||g|" << endl;
    cout << "   +-++-++-++-++-++-++-++-+ +-++-++-++-+" << endl;
    cout << endl;
}

/*********************************************************************
 ** Function: HospitalWing::specialAction()
 ** Description: Contains special actions for the HospitalWing location
 ** Parameters: Player* player
 ** Pre-Conditions: user has to chose HospitalWing as their next location
 ** Post-Conditions: user will obtain recovery portion and strengthening 
 **                  portion, and will be taken to a different location
 *********************************************************************/
void HospitalWing::specialAction(Player* player) {
    cout << "[Madame Pomfrey] 'Hello, Mr.Potter! What brings you here?'" << endl;
    cout << endl;
    cout << "Would you like to ask Madame Pomfrey for a Recovery Portion?" << endl;
    char sick;
    cout << "=========================================================" << endl;
    cout << "=              Ask for a Recovery Portion               =" << endl;
    cout << "=========================================================" << endl;
    cout << "Enter a letter:" << endl;
    cout << " [Y] Ask Madame Pomfrey for a Recovery Portion." << endl;
    cout << " [Any other key] Don't ask and continue." << endl;
    cout << "=========================================================" << endl;
    cout << "Your selection: ";
    cin >> sick;
    if (sick == 'Y' || sick == 'y') {
        cout << endl;
        cout << "[Harry Potter] 'Can I get a Recovery Portion? I am not feeling good!'" << endl;
        srand(unsigned(time(NULL)));
        int roll = (rand() % 3) +1;
        if (roll == 1) {
            cout << "[Madame Pomfrey] 'Here you go! By the way,\n";
            cout << "I heard that you haven't been feeling too well lately.\n";
            cout << "Here is a Strengthening Solution to help you feel stronger.'" << endl;
            cout << "[Harry Potter ] 'Thank you very much!'" << endl;
            cout << endl;
            player->getInventory()->addItem(recoveryPortion);
            cout << "***< ITEM ADDED! Harry Potter obtains Recovery Portion >***" << endl;
            player->getInventory()->addItem(strengthSolution);
            cout << "***< ITEM ADDED! Harry Potter obtains Strengthening Solution >***" << endl;
        }
        
        else if (roll == 2) {
            cout << "[Madame Pomfrey] 'Sorry, we are out of all the Recovery Portions today!'" << endl;
            cout << "[Harry Potter] 'Then, I'll come back next time.'" << endl;
            cout << endl;
        }
        
        else {
            cout << "[Madame Pomfrey] 'Would you like to trade an Item for a Recovery Portion?'" << endl;
            char choice;
            cout << "=========================================================" << endl;
            cout << "=          Trade an Item for a Recovery Portion         =" << endl;
            cout << "=========================================================" << endl;
            cout << "Enter a letter:" << endl;
            cout << " [Y] Trade an Item for a Recovery Portion" << endl;
            cout << " [Any other key] Don't trade and continue " << endl;
            cout << "=========================================================" << endl;
            cin >> choice;
            if (sick == 'Y' || sick == 'y') {
                if (player->getInventory()->getNumItems()!=0) {
                    bool tryagain = true;
                    while (tryagain == true) {
                        int num;
                        string trade;
                        player->getInventory()->display();
                        cout << "=========================================================" << endl;
                        cout << "Select an Item number to trade or enter -1 to exit: " << endl;
                        cin >> num;
                        if (num == -1) {
                            break;
                        }
                        cout << endl;
                        trade = player->getInventory()->findItem(num)->getItem();
                        cout << "You trade an Item with Madame Pomfrey." << endl;
                        player->getInventory()->removeItem(num);
                        cout << "***< ITEM REMOVED! Harry Potter removes " << trade << " >***" << endl;
                        player->getInventory()->addItem(recoveryPortion);
                        cout << "***< ITEM ADDED! Harry Potter obtains Recovery Portion >***" << endl;
                        cout << endl;
                        
                        cout << "[Madame Pomfrey] 'Harry, thank you for the " << trade << ".\n";
                        cout << "                  I want to give you Strengthening Solution.\n";
                        cout << "                  This will be very useful!'\n";
                        cout << "[Harry Potter ] 'Thank you very much!'" << endl;
                        player->getInventory()->addItem(strengthSolution);
                        cout << "***< ITEM ADDED! Harry Potter obtains Strengthening Solution >***" << endl;
                        tryagain = false;
                        cout << endl;
                    }
                }
            }
        }
    }
    cin.ignore(300, '\n');
    cout << endl;
    int choice1;
    cout << "=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=" << endl;
    cout << "=              Where would you like to go now?              =" << endl;
    cout << "=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=" << endl;
    cout << "1. Gryffindor Common Room" << endl;
    cout << "2. Quidditch Pitch" << endl;
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
        cin.ignore(300, '\n');
    }
    switch (choice1) {
        case 1:
            player->setLocation(GryffindorCommons);
            break;
        case 2:
            player->setLocation(QuidditchPitch);
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
 ** Function: HospitalWing::~HospitalWing()
 ** Description: Deconstructor
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
HospitalWing::~HospitalWing(){
 /*    recoveryPortion = NULL;
    delete recoveryPortion;
     strengthSolution = NULL;
    delete strengthSolution;
  */
}
