/*********************************************************************
 ** Filename: DefenseAgainsttheDarkArts.cpp
 ** Author: Ju Hye An
 ** Date: 12/6/16
 ** Description: Contains the implementation of the DefenseAgainsttheDarkArts
 ** class member functions.
 *********************************************************************/
#include "DefenseAgainsttheDarkArts.hpp"

/*********************************************************************
 ** Function: DefenseAgainsttheDarkArts::displaySpace()
 ** Description: Displays the location name using ASCII art
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
void DefenseAgainsttheDarkArts::displaySpace() {
    cout << endl;
    cout << "   +-++-++-++-++-++-++-+ +-++-++-++-++-++-++-+" << endl;
    cout << "   |D||e||f||e||n||s||e| |A||g||a||i||n||s||t|" << endl;
    cout << "   +-++-++-++-++-++-++-+ +-++-++-++-++-++-++-+" << endl;
    cout << "       +-++-++-+ +-++-++-++-+ +-++-++-++-+ +-++-++-++-+" << endl;
    cout << "       |t||h||e| |D||a||r||k| |A||r||t||s| |R||o||o||m|" << endl;
    cout << "       +-++-++-+ +-++-++-++-+ +-++-++-++-+ +-++-++-++-+" << endl;
    cout << endl;

}

/*********************************************************************
 ** Function: DefenseAgainsttheDarkArts::specialAction()
 ** Description: Contains special actions for the DefenseAgainsttheDarkArts
 **              location
 ** Parameters: Player* player
 ** Pre-Conditions: user has to chose DefenseAgainsttheDarkArts as 
 **                 their next location
 ** Post-Conditions: user can use recovery portion, if portion not found 
 **                  in the backpack inventory, Harry taken to the HospitalWing 
 **                  If Harry has it, he can choose a different location
 *********************************************************************/
void DefenseAgainsttheDarkArts::specialAction(Player* player) {
    if (examNotTaken) {
        cout << "Ordinary Wizarding Level examinations are today." << endl;
        cout << "=========================================================" << endl;
        cout << "=              What would you like to do?               =" << endl;
        cout << "=========================================================" << endl;
        cout << "Enter a letter:" << endl;
        cout << " [Y] Stay and take the O.W.L. exams." << endl;
        cout << " [Any other key] Skip the exams and continue." << endl;
        cout << "=========================================================" << endl;
        cout << "Your selection: ";
        char choice;
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            cout << "Harry Potter takes the O.W.L. exams..." << endl;
            cout << "Taking the exams made Harry Potter feel extremely tired" << endl;
            cout << endl;
            if (player->getInventory()->getNumItems()!=0) {
                int recoverItem;
                string recover;
                cout << "Use a Recover Portion to feel better!" << endl;
                cout << "Select Item number of Recovery Portion to use or -1 if you don't have Recover Portion: " << endl;
                player->getInventory()->display();
                cout << "-------------------------------------------------------" << endl;
                cout << "Your selection: " << endl;
                cin >> recoverItem;
                if (recoverItem == -1) {
                    cout << "You don't have any Recovery Portion" << endl;
                    cout << "Harry Potter has collapsed and is taken to the Hospital Wing" << endl;
                    cout << endl;
                    player->setLocation(HospitalWing);
                    return;
                }
                else {
                recover = player->getInventory()->findItem(recoverItem)->getItem();
                    if (recover != "Recovery Portion") {
                        cout << "Harry Potter has collapsed and is taken to the Hospital Wing" << endl;
                        cout << endl;
                        player->setLocation(HospitalWing);
                        return;
                    }
                    else if (recover == "Recovery Portion") {
                        cout << "You have recovered your energy! You feel awesome!" << endl;
                        player->getInventory()->removeItem(recoverItem);
                        examNotTaken = false;
                        cout << endl;
                    }
                }
                cout << endl;
            }
            else {
                cout << "Harry Potter has collapsed and is taken to the Hospital Wing" << endl;
                cout << endl;
                player->setLocation(HospitalWing);
                return;
            }
        }
        else {
            cout << endl;
            cout << "The Defense Against the Dark Arts classroom is empty." << endl;
            cout << endl;
        }
        cout << endl;
        int choice1;
        cout << "=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=" << endl;
        cout << "=              Where would you like to go now?              =" << endl;
        cout << "=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=o=" << endl;
        cout << "1. Forbidden Forrest" << endl;
        cout << "2. Hospital Wing" << endl;
        cout << "3. The Great Hall" << endl;
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
                player->setLocation(ForbiddenForrest);
                break;
            case 2:
                player->setLocation(HospitalWing);
                break;
            case 3:
                player->setLocation(GreatHall);
                break;
            case 4:
                player->setLocation(HeadmastersOffice);
                break;
            case 5:
                player->getInventory()->display();
                break;
        }
    }
}

/*********************************************************************
 ** Function: DefenseAgainsttheDarkArts::~DefenseAgainsttheDarkArts()
 ** Description: Deconstructor
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
DefenseAgainsttheDarkArts::~DefenseAgainsttheDarkArts() {
    // LEFT BLANK
}
