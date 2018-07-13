/*********************************************************************
 ** Filename: main.cpp
 ** Author: Ju Hye An
 ** Date: 11/21/16
 ** Description: This is a the test driver for fantasy combat tournament
 ** game program. User will create two teams of Creatures that will 
 ** battle each other.
 ** Input: User will select the number of players in each team and then 
 ** the user will select from a menu to determine which Creatures will 
 ** fight and name each creature.
 ** Output: runs each round of the combat fight until there is a last player
 ** standing.
 *********************************************************************/

#include <limits>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Game.hpp"
#include "Barbarian.hpp"
#include "Creature.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Stack.hpp"
#include "Queue.hpp"


int main() {
    srand((unsigned)time(NULL));
    int run = true;
    int askAgain;
    
    do {
        std::cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << std::endl;
        std::cout << "*                 Assignment 4                  *" << std::endl;
        std::cout << "*          WELCOME TO FANTASY COMBAT GAME       *" << std::endl;
        std::cout << "*              Tournament Edition               *" << std::endl;
        std::cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << std::endl;
 
    Game* game1 = new Game;
    game1->userPromptPlayers();
    
    // create teams
    game1->createTeams((game1->getTeam1()), "Team 1");
    game1->createTeams((game1->getTeam2()), "Team 2");
    
    // print teams
    cout << "\n==================================================\n";
    cout <<   "                   TEAM 1 LINE UP                 " << endl;
    cout <<   "==================================================\n";
    (game1->getTeam1())->print();
    
    cout << endl;
    cout << "\n==================================================\n";
    cout <<   "                   TEAM 2 LINE UP                 " << endl;
    cout <<   "==================================================\n";
    (game1->getTeam2())->print();
    
    // view options
    cout << endl;
    string ch;
    cout << "\n==================================================\n";
    cout <<   "|          TOURNAMENT VIEWING OPTIONS            |" << endl;
    cout <<   "|   Please choose either option 1 or option 2    |" << endl;
    cout <<   "==================================================\n";
    cout << "\t1. View detailed battles, winners and results" << endl;
    cout << "\t2. View quick battles, winners and results" << endl;
    cout << "==================================================\n";
    cout << "Choice: ";
    getline(cin, ch);
    
   // input validation check
    while ((ch != "1") && (ch != "2")) {
        cout << "Please choose \"1\" or \"2\" ";
        cout << "Note: Only special powers used in a round are displayed during the condensed battle." << endl;
        cout << "Choice: ";
        getline(cin, ch);
    }
    
    //playGame until one team is defeated
    bool teamOneEmpty = false;
    bool teamTwoEmpty = false;
    while ((teamOneEmpty == false) && (teamTwoEmpty == false)) {
        if (ch == "1") {
            cout << "****************************************" << endl;
            cout << endl;
            game1->playGameOutput();
            cout << endl;
        }
        if (ch == "2") {
            cout << "****************************************" << endl;
            cout << endl;
            game1->playGame();
            cout << endl;
        }
        teamOneEmpty = (game1->getTeam1())->isEmpty();
        teamTwoEmpty = (game1->getTeam2())->isEmpty();
    }
    game1->finalResults();
    delete game1;
    game1 = NULL;
        
        std::cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << std::endl;
        std::cout << "*=                  PLAY AGAIN?                =*" << std::endl;
        std::cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << std::endl;
        std::cout << "Start a new game with different creatures?" << std::endl;
        std::cout << "If YES, enter [1]. If NO, enter [2]" << std::endl;
        std::cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << std::endl;
        std::cout << "Your selection: ";
        std::cin >> askAgain;
        while(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "INVALID INPUT! Please enter a number from 1 to 2.\n";
            std::cout << "Your selection: ";
            std::cin >> askAgain;
        }
        if (askAgain == 1) {
            run = true;
        }
        
        else if (askAgain == 2) {
            run = false;
        }
        
        else {
            std::cout << "INVALID INPUT! Please enter a number from 1 to 2.\n";
        }
    } while (run);

    return 0;
}
