/*********************************************************************
 ** Program name: board.hpp
 ** Author: Alex Rueb
 ** Date: 4/16/2017
 ** Description: This is the interface file for the Board class that 
    represents the board for the Langton's Ant simulation and acts as 
    the primary controller.  A constructor is provided that accepts
    the number of rows, number of columns, number of steps to move the
    ant, the ant's initial x position, andthe ant's initial y position.
    This constructor dynamically creates an array to generate the board,
    which is deleted via the provided destructor. There are member 
    functions to move the ant, print the board, and start the 
    simulation, as well as some supporting helper functions.  The only 
    function needed to run the simulation is the start() member 
    function, provided all necessary parameters are passed to the 
    constructor.
 *********************************************************************/

#ifndef board_hpp
#define board_hpp

#include "ant.hpp"
class Board
{
private:
    int rowCount; // board number of rows
    int colCount; // board number of columns
    int steps; // steps for ant to move
    char **boardArray; // pointer to 2d array
    int xCoord; // ant x position
    int yCoord; // ant y position
    Ant myAnt; // Ant object
    
public:
    Board(int rows, int cols, int steps, int antXCoord, int antYCoord); // constructor
    void moveAnt();
    void start();
    void printBoard();
    void setAntCellColor();
    void flipBoardCellColor(Color cellColor);
    ~Board(); // destructor
};

#endif /* board_hpp */
