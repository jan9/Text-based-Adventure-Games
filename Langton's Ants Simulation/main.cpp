/*********************************************************************
 ** Filename: main.cpp
 ** Author: Ju Hye An
 ** Date: 10/9/16
 ** Description: This program implements a simulation of Langton's Ant
 ** using a 2D dynamic array and a class.
 ** Input: # of row, # of columns (for an array), and # of ant's steps
 ** Output: a simulation of Langton's Ant
 *********************************************************************/

#include "ant.hpp"

#include <unistd.h> // necessary in order to use usleep();
#include <stdlib.h> // necessary in order to user srand();
#include <time.h>   // necessary in order to user srand();

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// dynamic array is an array of int
typedef char* IntArrayPtr;

// function prototypes
void displayProgramDescription();
void startingLocationMenu(int, int, Ant*);

void fillMatrix (char**, int, int );
void printMatrix (char**, int, int);
void checkWrap(Ant*, int, int);

int inputValidation_integers(int);
int inputValidation_steps(int);
int inputValidation_menu(int);

// the main function that will build an array and run the simulation
int main() {
    displayProgramDescription();
    std::cout << "***** Let's first create a matrix! *****\n";
    
// BUILDING AN 2D DYNAMIC ARRAY
    // prompt the user to enter row (width) and column (length) with input validation checks
    int row, col;
    std::cout << "Please enter a positive integer for the row of the array:\n";
    std::cin >> row;
    row = inputValidation_integers(row);
    std::cout << "Please enter a positive integer for the column of the array:\n";
    std::cin >> col;
    col = inputValidation_integers(col);
    std::cout << std::endl;
    
    // builds the array
    IntArrayPtr *m = new IntArrayPtr[row];
    int i;
    for (i = 0; i < row; i++) {
        m[i] = new char [col];
    }
    
    // initialize the array with white spaces
    fillMatrix (m, row, col);
    printMatrix(m, row, col);

// SIMULATION PREPARATION
    // prompt the user to provide how many steps or runs will be done (suggest value)
    int steps;
    std::cout << "************ The Ant's Steps ***********\n";
    std::cout << "Please enter an integer betweeen 1 and 15000 for the number of steps:\n";
    std::cin >> steps;
    steps = inputValidation_steps(steps);
    std::cout << "The ant will move " << steps << " steps." << std::endl << std::endl;
    
// RUN SIMULATION
    // Ant object declared
    Ant ant;
    Ant* ant_ptr = &ant;
    
    // Leads to menu function that asks the user to either put in a set of coordinates or get coordinates.
    startingLocationMenu(row, col, ant_ptr);
    
    char white = 32, black = 35;
    for (int count = 0; count < steps; count++) {
        // total step counter
        std::cout << "Step #" << count+1;
        
        // change the color of the cell the ant is on, move the ant according to the color, and print the grid
        if(m[ant.getX()][ant.getY()] == white) {
            m[ant.getX()][ant.getY()] = black;
            ant.turnRight();
            printMatrix(m, row, col);
            std::cout << std::endl;
        } else if (m[ant.getX()][ant.getY()] == black) {
           m[ant.getX()][ant.getY()] = white;
            ant.turnLeft();
            printMatrix(m, row, col);
            std::cout << std::endl;
        }
        
        // check wrapping
        checkWrap(&ant, row, col);
        std::cout << std::endl;
        usleep(15000);
    }

// DELETE THE ARRAY
    // free the memory allocated
    for (i=0; i< row; i++) {
        delete[] m[i];
    }
    delete[] m;
    
    return 0;
}







// FUNCTIONAL DECOMPOSITIONS
/*********************************************************************
 ** Function: displayProgramDescription()
 ** Description: This function welcomes the user
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 *********************************************************************/
void displayProgramDescription(){
    std::cout << "===================================================\n";
    std::cout << "==      WELCOME TO LANGTON'S ANT SIMULATOR       ==\n";
    std::cout << "===================================================\n";
    std::cout << std::endl;
}

/*********************************************************************
 ** Function: inputValidation_integers()
 ** Description: This function checks the validity of a user provided
 ** input
 ** Parameters: int checkNum
 ** Pre-Conditions: Input from the user
 ** Post-Conditions: N/A
 *********************************************************************/
int inputValidation_integers(int checkNum) {
    while(!cin || (checkNum < 1)){
        if (!cin) {
            std::cout << "Invalid Error! Please enter an integer greater than 0:\n";
            std::cin.clear();
            std::cin.ignore();
            std::cin >> checkNum;
        }
        else if (checkNum < 1) {
            std::cout << "Invalid Error! Please enter a new integer greater than 0:\n";
            std::cin.clear();
            std::cin.ignore();
            std::cin >> checkNum;
        }
    }
    return checkNum;
}

/*********************************************************************
 ** Function: inputValidation_steps()
 ** Description: This function checks to see if the user has provided 
 ** an integer value that fits the suggested range
 ** Parameters: int validSteps
 ** Pre-Conditions: Input from the user
 ** Post-Conditions: N/A
 *********************************************************************/
int inputValidation_steps(int validSteps) {
    while ((validSteps < 1) || (validSteps > 15000)) {
        std::cout << "Invalid Error! Please enter an integer between 1 and 15000:\n";
        std::cin.clear();
        std::cin.ignore();
        std::cin >> validSteps;
    }
    return validSteps;
}

/*********************************************************************
 ** Function: inputValidation_menu()
 ** Description: This function checks to see if the user has provided
 ** a correct integer value
 ** Parameters: int choice
 ** Pre-Conditions: Input from the user
 ** Post-Conditions: N/A
 *********************************************************************/
int inputValidation_menu(int choice) {
    while ((choice != 1) && (choice != 2)) {
        std::cout << "Invalid Error! Please enter either 1 or 2:\n";
        std::cin.clear();
        std::cin.ignore();
        std::cin >> choice;
        std::cout << std::endl;
    }
    return choice;
}

/*********************************************************************
 ** Function: fillMatrix()
 ** Description: This function fills the user-defined 2D array with 
 ** 'white' spaces
 ** Parameters: char** m, int d1, int d2
 ** Pre-Conditions: Needs user-defined array dimension(e.g. rows and columns)
 ** Post-Conditions: N/A
 *********************************************************************/
void fillMatrix (char** m, int d1, int d2) {
    // fills the array with white spaces
    for (int i = 0; i < d1; i++) {
        for (int j = 0; j < d2; j++) {
            m[i][j] = ' ';
        }
    }
}


/*********************************************************************
 ** Function: printMatrix()
 ** Description: This function prints the user-defined matrix using
 the provided integers.
 ** Parameters: char** m, int d1, int d2
 ** Pre-Conditions: Needs user-defined array dimension(e.g. rows and columns)
 ** Post-Conditions: Matrix shown
 *********************************************************************/
void printMatrix (char** m, int d1, int d2) {
    // displays the user created array
    std::cout << "\nHere is your " << d1 << "x" << d2 << " matrix:\n";
    for (int i = 0; i < d1; i++) {
        for (int j = 0; j < d2; j++) {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/*********************************************************************
 ** Function: startingLocationMenu()
 ** Description: This function prompts the user to provide the starting
 ** location of the ant by giving two options. User can either choose
 ** to provide the starting location or have the program provide the 
 ** random starting location.
 ** Parameters: int row, int col, Ant *ant
 ** Pre-Conditions: Needs user-defined array dimension(e.g. rows and columns)
 ** Post-Conditions: According to the user's choice, this function sets
 ** the starting coordinate of the ant
 *********************************************************************/
void startingLocationMenu(int row, int col, Ant *ant){
    int choice; // menu choice
    
    // Display the menu and get the user's choice with validation check
    std::cout << "***** The Ant's Starting Location ******\n";
    std::cout << "1. User-defined starting location\n";
    std::cout << "2. Random starting location\n";
    std::cout << "Enter your choice:\n";
    std::cin >> choice;
    choice = inputValidation_menu(choice);
    
    // Use the menu selection to execute the correct set of actions
    if (choice == 1) {
        std::cout << "You have selected: 1.User-defined starting location\n";
        
        std::cout << "Please enter a x-coordinate(choose an integer between 1 ~ " << col << "): ";
        int userInputX;
        std::cin >> userInputX;
        while ((userInputX < 0) || (userInputX > col)) {
            std::cout << "Invalid Error! Please enter an integer between 1 ~ " << col << ":\n";
            std::cin.clear();
            std::cin.ignore();
            std::cin >> userInputX;
        }
        ant->setX(userInputX);
        std::cout << std::endl;
        
        std::cout << "Please enter a y-coordinate(choose an integer between 1 ~ " << row << "): ";
        int userInputY;
        std::cin >> userInputY;
        while ((userInputY < 0) || (userInputY > row)) {
            std::cout << "Invalid Error! Please enter an integer between 1 ~ " << row << ":\n";
            std::cin.clear();
            std::cin.ignore();
            std::cin >> userInputY;
        }
        ant->setY(userInputY);
        std::cout << std::endl;
        
        std::cout << "The ant's initial location is set to (" << userInputX << "," << userInputY << ").\n";
        std::cout << std::endl;
    }
    
    else if (choice == 2) {
        std::cout << "You have selected 2.Random starting location.\n\n";
        
        int randomX, randomY;
        srand(time(NULL));
        
        randomX = rand() % col + 0; // generate random number between 0 and # of rows (the user defined earlier)
        ant->setX(randomX);
        
        randomY = rand() % row + 0;
        ant->setY(randomY);
        
        std::cout << "The ant's initial location is set to (" << randomX << "," << randomY << ").\n";
    }
    else {
        std::cout << "Pleaase enter either 1 or 2.\n";
    }
}

/*********************************************************************
 ** Function: checkWrap
 ** Description: This function wraps around the function if the ant goes
 ** over the boundary of user-defined matrix.
 ** Parameters: Ant *ant, int row, int col
 ** Pre-Conditions: Needs user-defined array dimension(e.g. rows and columns)
 ** Post-Conditions: N/A
 *********************************************************************/
void checkWrap(Ant *ant, int row, int col) {
    // make sure we wrap around the thing:
    if(ant->getX() < 0) {   ant->setX(row - 1); }
    else if(ant->getY() < 0) {  ant->setY(col - 1); }
    else if(ant->getX() > row - 1) {    ant->setX(0);   }
    else if(ant->getY() > col - 1) {    ant->setY(0);   }
}
