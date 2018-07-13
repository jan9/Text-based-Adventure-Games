/*********************************************************************
 ** Filename: Game.cpp
 ** Author: Ju Hye An
 ** Date: 11/21/16
 ** Description: Contains the implementation of the Game class.
 *********************************************************************/

#include "Game.hpp"

/*********************************************************************
 ** Function: Game::Game()
 ** Description: This function sets initial values for PlayGame member variables.
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
Game::Game() {
    team1 = &playerQteam1;
    team2 = &playerQteam2;
    loserstack = &losers;
    playerPtr = NULL;
}


/******************************************************************************************
 ** Function: Deconstructor
 ** Description: This function sets pointers to null when a PlayGame object is deleted.
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditons: N/A
 ******************************************************************************************/
Game::~Game() {
    playerPtr = NULL;
}



/******************************************************************************************
 ** Function: getters
 ** Description: These functions return private member variables.
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditons: N/A
 ******************************************************************************************/
Queue* Game::getTeam1() {
    return team1;
}

Queue* Game::getTeam2() {
    return team2;
}

Stack* Game::getLosers() {
    
    return loserstack;
}



/******************************************************************************************
 ** Function: userPromptPlayers
 ** Description: Allows user to input the number of players for each team.
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditons: Number of players integer is set
 ******************************************************************************************/
void Game::userPromptPlayers() {
    
    int players;
    cout << "\n==================================================\n";
    cout <<   "|               NUMBER OF PLAYERS                |" << endl;
    cout <<   "|  How many players will there be in each team?  |" << endl;
    cout <<   "==================================================\n";
    cout << "Players Per Team: ";
    cin >> players;
    cin.ignore();

    while (players < 1 ) {
        cout << "Each team will need at least one player." << endl;
        cout << "Players Per Team: ";
        cin >> players;
        cin.ignore();
    }
    playersPerTeam = players;
}



/******************************************************************************************
 ** Function: createTeams
 ** Description: This function creates dynamically allocated Creature pointers and passes
 **	them (and their name defined by the user) into their corresponding Queue.
 ** Parameters: Pointer to the team Queue and a string corresponding to the team name.
 ** Pre-Conditions: N/A
 ** Post-Conditons: Teams are created in their respective Queues
 ******************************************************************************************/
void Game::createTeams(Queue* ptrToTeam, string s1) {
    
    string playerName;
    char identity;
    cout << "\n==================================================\n";
    cout <<   "|                  CREATE A TEAM                 |" << endl;
    cout <<   "|       Let's choose the players for " << s1 << "      |" << endl;
    cout <<   "==================================================\n";
    
    for (int i = 0; i < playersPerTeam; i++) {
        
        Creature* playerPtr = NULL;
        cout << "\n==================================================\n";
        cout <<   " [ " << s1 << " ]  PLAYER " << i + 1 << "                        " << endl;
        cout <<   "==================================================\n";
        cout << "Please enter a name for Player " << i + 1 << ":" << endl;
        getline(cin, playerName);
        
        identity = playerMenu();
        
        if (identity == '1') {
            playerPtr = new Vampire(playerName, s1);
            ptrToTeam->push(playerPtr);
        }
        
        else if (identity == '2') {
            playerPtr = new Barbarian(playerName, s1);
            ptrToTeam->push(playerPtr);
        }
        
        else if (identity == '3') {
            playerPtr = new BlueMen(playerName, s1);
            ptrToTeam->push(playerPtr);
        }
        
        else if (identity == '4') {
            playerPtr = new Medusa(playerName, s1);
            ptrToTeam->push(playerPtr);
        }
        
        else if (identity == '5') {
            playerPtr = new HarryPotter(playerName, s1);
            ptrToTeam->push(playerPtr);
        }
        
        else {
            
        }
    }
    cout << endl;
}

/******************************************************************************************
 ** Function: playerMenu
 ** Description: This function displays a list of the different Creature that may play the
 **		game. The user must select from the list of options.
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditons: N/A
 ******************************************************************************************/
char Game::playerMenu() {
    char choice;
    cout << "\n==================================================\n";
    cout << "|              PLAYER CREATURE TYPE              |" << endl;
    cout << "|   Please select a creature type of the player  |" << endl;
    cout << "==================================================\n";
    cout << "\t1. Vampire (*special skill: Charm)" << endl;
    cout << "\t2. Barbarian" << std::endl;
    cout << "\t3. Blue Men (*special skill: Mob)" << endl;
    cout << "\t4. Medusa (*special skill: Glare)" << endl;
    cout << "\t5. Harry Potter (*special skill: Hogwarts)" << endl;
    cout << "==================================================\n";
    cin >> choice;
    cin.ignore();

    while ((choice < '1') || (choice > '5')) {
        cout << "Please enter the integer 1 through 5, only." << endl;
        cout << "Choice: " << endl;
        cin >> choice;
        cin.ignore();
    }
    return choice;
}


/******************************************************************************************
 ** Function: playGameOutput
 ** Description: This function allows the user to complete one battle from start to finish.
 **		This version of PlayGame includes additional output (including dice rolls) and
 **		displays the results of a single battle.
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditons: Losing player is moved to the loser stack and winning player regains
 **		some strength and moves to the back of their team queue.
 ******************************************************************************************/
void Game::playGameOutput() {
    int dieRoll = (rand() % 2) + 1;
    Creature * firstplayer;
    Creature * secondplayer;
    
    // both teams take turn
    if (dieRoll == 1) {
        firstplayer = team1->pop();
        secondplayer = team2->pop();
    }
    
    else {
        firstplayer = team2->pop();
        secondplayer = team1->pop();
    }
    
    int round = 0;
    

    // Both players must be alive to battle
    while ((firstplayer->getStrength() > 0) && (secondplayer->getStrength() > 0)) {
        round++;
        cout << "\n==============================================\n";
        cout <<   "+                CURRENT MATCH               +\n";
        cout <<   "             " << firstplayer->getName() << " " << firstplayer->getType() << endl;
        cout <<   "                       vs " << endl;
        cout <<   "             " << secondplayer->getName() << secondplayer->getType() << endl;
        cout <<   "+                                            +\n";
        cout <<   "==============================================\n\n";
        
        cout << endl;
        std::cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << std::endl;
        std::cout << "*               ROUND " << round << "               *" << std::endl;
        std::cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << std::endl;

        
        int attack = firstplayer->attack();
        cout << "[ " << firstplayer->getName() << " " << firstplayer->getType() << " ATTACKS ]\n";
        cout << "Attack value: " << firstplayer->getattackVal() << endl;
        secondplayer->defend(attack);
        cout << endl;
        cout << "[ " << secondplayer->getName() << " " << secondplayer->getType() << " DEFENDS ]\n";
        cout << "Defense value: " << secondplayer->getDefenseVal() << endl;
        cout << "Armor value: " << secondplayer->getArmor() << endl;
        cout << "Strength: " << secondplayer->getStrength() << endl;
        cout << endl;
        
        // battle stops if second player died
        if (secondplayer->getStrength() > 0) {
            int attack2 = secondplayer->attack();
            cout << "[ " << secondplayer->getName() << " " << secondplayer->getType() << " ATTACKS ]\n";
            cout << "Attack value: " << secondplayer->getattackVal() << endl;
            firstplayer->defend(attack2);
            cout << endl;
            cout << "[ " << firstplayer->getName() << " " << firstplayer->getType() << " DEFENDS ]\n";
            cout << "Defense value: " << firstplayer->getDefenseVal() << endl;
            cout << "Armor value: " << firstplayer->getArmor() << endl;
            cout << "Strength: " << firstplayer->getStrength() << endl;
            cout << endl;
            
        }
    }
    
    // second player wins
    if (firstplayer->getStrength() <= 0) {
        cout << "\n < Round" << round << "  Summary >" << endl;
        cout << "[ " << firstplayer->getName() << " " << firstplayer->getType() << " LOSES ]\n";
        cout << "[ " << secondplayer->getName() << " " << secondplayer->getType() << " WINS]\n";
        cout << endl;
        
        if (dieRoll == 1) {
            loserstack->push(firstplayer);
            cout << "" << secondplayer->getName() << " " << secondplayer->getType() << " ";
            cout << "recovers " << secondplayer->recovery() <<" before returning to the lineup!" << endl;
            team2->push(secondplayer);
            cout << endl;
        }
        
        else {
            loserstack->push(firstplayer);
            cout << " " << secondplayer->getName() << " " << secondplayer->getType() << " ";
            cout << "recovers " << secondplayer->recovery() <<" before returning to the lineup!" << endl;
            team1->push(secondplayer);
            cout << endl;
        }
    }
    
    // first player wins
    if (secondplayer->getStrength() <= 0) {
        cout << "\n < Round" << round << "  Summary >" << endl;
        cout << "[ " << secondplayer->getName() << " " << secondplayer->getType() << " LOSES]\n";
        cout << "[ " << firstplayer->getName() << " " << firstplayer->getType() << " WINS]\n";
        cout << endl;
        
        if (dieRoll == 1) {
            cout << " " << firstplayer->getName() << " " << firstplayer->getType() << " ";
            cout << "recovers " << firstplayer->recovery() <<" before returning to the lineup!" << endl;
            loserstack->push(secondplayer);
            team1->push(firstplayer);
            cout << endl;
        }
        
        else {
            cout << " " << firstplayer->getName() << " " << firstplayer->getType() << " ";
            cout << "recovers " << firstplayer->recovery() <<" before returning to the lineup!" << endl;
            loserstack->push(secondplayer);
            team2->push(firstplayer);
            cout << endl;
        }
    }
}



/******************************************************************************************
 ** Function: playGame
 ** Description: This function allows the user to complete one battle from start to finish.
 **		This version of PlayGame has restricted output and primarily displays the winner
 **		of the battle and if special abilities were used.
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditons: Losing player is moved to the loser stack and winning player regains
 **		some strength and moves to the back of their team queue.
 ******************************************************************************************/
void Game::playGame() {
    int dieRoll = (rand() % 2) + 1;
    Creature * firstplayer;
    Creature * secondplayer;
    
    
    // teams take turn
    if (dieRoll == 1) {
        firstplayer = team1->pop();
        secondplayer = team2->pop();
    }
    
    else {
        firstplayer = team2->pop();
        secondplayer = team1->pop();
    }
    
    cout << firstplayer->getName() << " " << firstplayer->getType() << " vs. ";
    cout << secondplayer->getName() << " " << secondplayer->getType() << endl;
    
    int round = 0;
    
    //Both players must be alive to battle
    while ((firstplayer->getStrength() > 0) && (secondplayer->getStrength() > 0)) {
        round++;
        
        int attack = firstplayer->attack();
        
        secondplayer->defend(attack);
        
        // battle stops when second player is has no strength
        if (secondplayer->getStrength() > 0) {
            
            int attack2 = secondplayer->attack();
            
            firstplayer->defend(attack2);
            
        }
    }
    
    // second player wins
    if (firstplayer->getStrength() <= 0) {
        cout << "\n < Round" << round << "  Summary >" << endl;
        cout << "[ " << firstplayer->getName() << " " << firstplayer->getType() << " LOSES ]\n";
        cout << "[ " << secondplayer->getName() << " " << secondplayer->getType() << " WINS]\n";
        cout << endl;
        
        if (dieRoll == 1) {
            loserstack->push(firstplayer);
            cout << "" << secondplayer->getName() << " " << secondplayer->getType() << " ";
            cout << "recovers " << secondplayer->recovery() <<" before returning to the lineup!" << endl;
            team2->push(secondplayer);
            cout << endl;
        }
        
        else {
            loserstack->push(firstplayer);
            cout << " " << secondplayer->getName() << " " << secondplayer->getType() << " ";
            cout << "recovers " << secondplayer->recovery() <<" before returning to the lineup!" << endl;
            team1->push(secondplayer);
            cout << endl;
        }
        
    }
    
    // first Player Wins
    if (secondplayer->getStrength() <= 0) {
        cout << "\n < Round" << round << "  Summary >" << endl;
        cout << "[ " << secondplayer->getName() << " " << secondplayer->getType() << " LOSES]\n";
        cout << "[ " << firstplayer->getName() << " " << firstplayer->getType() << " WINS]\n";
        cout << endl;
        
        if (dieRoll == 1) {
            cout << " " << firstplayer->getName() << " " << firstplayer->getType() << " ";
            cout << "recovers " << firstplayer->recovery() <<" before returning to the lineup!" << endl;
            loserstack->push(secondplayer);
            team1->push(firstplayer);
            cout << endl;
        }
        
        else {
            cout << " " << firstplayer->getName() << " " << firstplayer->getType() << " ";
            cout << "recovers " << firstplayer->recovery() <<" before returning to the lineup!" << endl;
            loserstack->push(secondplayer);
            team2->push(firstplayer);
            cout << endl;
        }
        
    }
    
}



/******************************************************************************************
 ** Function: finalResults
 ** Description: This function displays the players remaining on each team, the players that
 **		have been incapacitated, the winning team, and the 1st-3rd place winners. 
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditons: N/A
 ******************************************************************************************/
void Game::finalResults() {
    cout << "=================================================" << endl;
    cout << "==                TOURNAMENT RESULTS           ==" << endl;
    cout << "=================================================" << endl;
    cout << endl;
    
    cout << "TEAM 1 PLAYERS WHO ARE STILL ALIVE: " << endl;
    team1->print();
    
    cout << endl;
     cout << "TEAM 2 PLAYERS WHO ARE STILL ALIVE: " << endl;
    team2->print();
    
    cout << endl;
    cout << "Losers: " << endl;
    loserstack->print();
    
    cout << endl;
    cout << "=================================================" << endl;
    cout << "                  THE WINNING TEAM               " << endl;
    cout << "=================================================" << endl;
    if (team1->isEmpty() == true) {
        cout << "Team 2 won the match." << endl << endl;
    }
    else {
        cout << "Team 1 won the match." << endl << endl;
    }
    
    cout << "=================================================" << endl;
    cout << "              TOURNAMENT FIRST PLACE           " << endl;
    cout << "=================================================" << endl;
    if (team1->isEmpty() == true) {
        cout << "First place goes to the surviving players of Team 2: " << endl;
        team2->print();
    }
    else {
        cout << "First place goes to the surviving players of Team 1:" << endl;
        team1->print();
    }
    
    cout << "=================================================" << endl;
    cout << "            TOURNAMENT SECOND PLACE          " << endl;
    cout << "=================================================" << endl;
    cout << endl << "Second place goes to the longest survivor: " << endl;
    loserstack->pop();
    cout << endl;
    
    cout << "=================================================" << endl;
    cout << "            TOURNAMENT THIRD PLACE           " << endl;
    cout << "=================================================" << endl;
    cout << "Third place goes to the next survivor: " << endl;
    loserstack->pop();
    cout << endl;
    
    
    
    
}
