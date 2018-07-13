/*********************************************************************
 ** Filename: Game.hpp
 ** Author: Ju Hye An
 ** Date: 11/21/16
 ** Description: Contains the Game class definition and member declarations.
 ** The Game class allows repeated simulations of the fantasy combat game.
 ** Tournament version makes use of Queue and Stack from Lab 6. 
 *********************************************************************/

#include "Creature.hpp"
#include "Barbarian.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Stack.hpp"
#include "Queue.hpp"

class Game {
private:
    int playersPerTeam;
    Creature * playerPtr;
    Stack losers;
    Queue playerQteam1;
    Queue playerQteam2;
    Queue * team1;
    Queue * team2;
    Stack * loserstack;
    
    
public:
    Game();
    ~Game();
    Queue * getTeam1();
    Queue * getTeam2();
    Stack * getLosers();
    void userPromptPlayers();
    void createTeams(Queue* teamID, string teamName);
    char playerMenu();
    void playGame();
    void playGameOutput();
    void finalResults();
    
    
};
