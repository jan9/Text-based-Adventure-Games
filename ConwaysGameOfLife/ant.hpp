/*********************************************************************
 ** Filename: ant.hpp
 ** Author: Ju Hye An
 ** Date: 10/9/16
 ** Description: This file declares the class function ant().
 ** Input: integer values for setters
 ** Output: N/A
 *********************************************************************/

#ifndef ant_hpp
#define ant_hpp
enum Direction {North, South, West, East};

class Ant
{
private:
    int current_x;
    int current_y;
    Direction current_direction;

    
public:
    // constructor
    Ant();
    
    // destructor
    ~Ant();
    
    // getters and setters
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    
    // ant's moves
    void turnLeft();
    void turnRight();

};

#endif /* ant_hpp */
