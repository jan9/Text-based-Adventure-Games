/*********************************************************************
 ** Filename: main.cpp
 ** Author: Ju Hye An
 ** Date: 12/6/16
 ** Description: CS 162 Final Project! 
 ** This program is called "The Wizarding World of Harry Potter."
 ** In this game, the player is asked to find 3 hidden objects.
 ** The user can either select play the game or view the solution.
 *********************************************************************/
#include <ctime>
#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "Game.hpp"
#include "Space.hpp"

int main()
{
   // srand((unsigned)time(NULL));
    int run = true;
    bool firstDone = true;
    do {
        if (firstDone) {
            cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << endl;
            cout << "*           < CS 162 Final Project >            *" << endl;
            cout << "*     THE WIZARDING WORLD OF HARRY POTTER       *" << endl;
            cout << "*             (Find 3 Hidden Objects)           *" << endl;
            cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << endl;
            cout << "Background:\n";
            cout << "You are Harry Potter! A new school year at\n";
            cout << "Hogwarts begins tomorrow, and today is move-in day.\n";
            cout << "Once you arrive at Hogwarts, Professor Dumbledore\n";
            cout << "will want to see you and give you a mission.\n";
            cout << endl;
            cout << "Goal:\n";
            cout << "Find 3 items before your moves run out!\n";
            cout << "You only have 30 moves to complete the mission.\n";
            cout << "Move counter will start once you get off the train.\n";
            cout << endl;
            cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << endl;
            cout << "*=                  Main Menu                  =*" << endl;
            cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << endl;
            cout << "Please choose a number to enter:" << endl;
            cout << " [1] Play the game." << endl;
            cout << " [2] View the solution of the game." << endl;
            cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << endl;
            int choice;
            cout << "Your selection: ";
            cin >> choice;
            while (choice < 1 || choice > 2 || !cin) {
                cout << "INVALID INPUT! Please enter a number from 1 to 2." << endl;
                cout << "Your selection: ";
                cin >> choice;
                cout << endl;
                cin.clear();
                cin.ignore(300, '\n');
            }
            
            if (choice == 1) {
                Game game;
                game.play();
                cout << "=================================================" << endl;
                cout << "        Thanks for playing the game! Bye." << endl;
                cout << "=================================================" << endl;
                cout << endl;
            }
            
            if (choice == 2) {
                cout << endl;
                cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << endl;
                cout << "*=                  Game Solution              =*" << endl;
                cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << endl;
                cout << "1. Tri-Wizard Cup Trophy" << endl;
                cout << "   [1] Go to the Gryffindor Common Room.\n";
                cout << "   [2] Show Ron and Hermione the items you found.\n";
                cout << "   [3] Then, you will obtain the Tri-Wizard Cup Trophy!\n";
                cout << endl;
                cout << "2. Firebolt" << endl;
                cout << "   [1] Go to the Quidditch Pitch.\n";
                cout << "   [2] Practice Quidditch with Oliver Wood.\n";
                cout << "   [3] Then, you will find Firebolt!\n";
                cout << endl;
                cout << "3. Unicorn's Blood" << endl;
                cout << "   [1] Go to the Hospital Wing.\n";
                cout << "       and ask Madame Pomfrey for a Recovery Portion.\n";
                cout << "   [2] If you are lucky, Madame Pomfrey will\n";
                cout << "       give you Recovery Portion and\n";
                cout << "       Strengthening Solution. If not, try again.\n";
                cout << "   [3] Go to the Forbidden Forrest.\n";
                cout << "   [4] Trade the Solution for a Unicorn's Blood!\n";
                cout << endl;
            }
            firstDone = false;
        }
        int askAgain;
        cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << endl;
        cout << "*=                  PLAY AGAIN?                =*" << endl;
        cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << endl;
        cout << "Would you like to start a new game?" << endl;
        cout << " [1] Yes, I would like to start a new game." << endl;
        cout << " [2] No,  I am done playing." << endl;
        cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << endl;
        cout << "Your selection: ";
        cin >> askAgain;
        while(askAgain < 1 || askAgain > 2 || !cin) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "INVALID INPUT! Please enter a number from 1 to 2.\n";
            cout << "Your selection: ";
            cin >> askAgain;
        }
        if (askAgain == 1) {
            firstDone = true;
            run = true;
        }
        
        else if (askAgain == 2) {
            run = false;
        }
        
        else {
            cout << "INVALID INPUT! Please enter a number from 1 to 2.\n";
        }

    } while (run);
    return 0;
}
