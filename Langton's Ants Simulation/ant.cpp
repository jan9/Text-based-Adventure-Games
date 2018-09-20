/*********************************************************************
 ** Program Filename: ant.cpp
 ** Author: Ju Hye An
 ** Date: 10/9/16
 ** Description: This file defines the class funtion ant().
 *********************************************************************/

/*********************************************************************
 ** Function: ant()
 ** Description: This class calculates determinant of the user-defined
 square matrix and cout the result
 ** Parameters: pointer to a 2D array and integer values
 ** Pre-Conditions: The "ant.hpp" file must be included.
 ** Post-Conditions: N/A
 *********************************************************************/

#include "ant.hpp"

// constructor, with default direction being North
Ant::Ant() {
    current_direction = North;
}

// destructor
Ant::~Ant(){
    
}

// setters & getters
void Ant::setX(int x) {
    current_x = x;
}
void Ant::setY(int y) {
    current_y = y;
}
int Ant::getX() {
    return current_x;
}
int Ant::getY() {
    return current_y;
}

// ant's moves
void Ant::turnLeft() {
    switch (current_direction) {
        case North: current_direction = West;
                    current_x += 1;
                    break;
        case West: current_direction = South;
                   current_y += 1;
                   break;
        case South: current_direction = East;
                    current_x -= 1;
                    break;
        case East: current_direction = North;
                   current_y -= 1;
                   break;
        default: current_direction = North;
                 break;
    }
}

void Ant::turnRight() {
    switch (current_direction) {
        case North: current_direction = East;
                    current_x -= 1;
                    break; // move right
        case East: current_direction = South;
                   current_y += 1;
                   break; // move down
        case South: current_direction = West;
                    current_x += 1;
                    break; // move left
        case West: current_direction = North;
                   current_y -= 1;
                   break; // move up
        default: current_direction = North;
                 break;
    }
}
