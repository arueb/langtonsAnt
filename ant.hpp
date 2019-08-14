/*********************************************************************
 ** Program name: ant.hpp
 ** Author: Alex Rueb
 ** Date: 4/16/2017
 ** Description: This is the interface file for the Ant class that
    represents the ant in the Langton's Ant simulation.  Data members
    include dir and cellColor to represent the direction the ant is 
    facing as well as the color of the cell the ant is occupying.  
    Corresponding set and get functions are provided for each data 
    member. This class requires the included enum variables Direction 
    and Color.
 *********************************************************************/

#ifndef ant_hpp
#define ant_hpp

// required enumerated values
enum Direction {UP, DOWN, LEFT, RIGHT};
enum Color {BLACK, WHITE};

class Ant
{
private:
    Direction dir;
    Color cellColor;
    
public:
    Ant(); // constructor
    Direction getDir();
    void setDir(Direction);
    Color getCellColor();
    void setCellColor(Color);
};

#endif /* ant_hpp */
