/*********************************************************************
 ** Program name: board.cpp
 ** Author: Alex Rueb
 ** Date: 4/16/2017
 ** Description: This is the implementation file for the Board class
 that represents the board for the Langton's Ant simulation and
 acts as the primary controller.  A constructor is provided that
 accepts the number of rows, number of columns, number of steps to
 move the ant, the ant's initial x position, andthe ant's initial
 y position. This constructor dynamically creates an array to
 generate the board, which is deleted via the provided destructor.
 There are member functions to move the ant, print the board, and
 start the simulation, as well as some supporting helper functions.
 The only function needed to run the simulation is the start()
 member function, provided all necessary parameters are passed to
 the constructor.
 *********************************************************************/

#include "board.hpp"
#include <iostream>
using std::cout;
using std::endl;


/*********************************************************************
                            Board::Board
 
 Description: This constructor accepts five arcguments and assigns
 initial values to the rowCount, colCount, steps, xCoord, and
 yCoord data members.  It also dynamically creates the 2d array that
 represents the board.
 *********************************************************************/
Board::Board(int rows, int cols, int s, int antXCoord, int antYCoord)
{
    
    rowCount = rows;
    colCount = cols;
    steps = s;
    xCoord = antXCoord;
    yCoord = antYCoord;

    // dynamically creat the 2d array
    boardArray = new char*[rowCount]; // create 1st dimension
    for(int i = 0; i < rowCount; ++i)
    {
        boardArray[i] = new char[colCount]; // create 2nd dimension
    }
    
    // loop through array and assign starting white space character '_'
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            boardArray[i][j]='_';
        }
    }
    
    // mark initial ant position (ant is facing up)
    boardArray[antYCoord][antXCoord]='^';
    
    // store ants direction in Ant object
    myAnt.setDir(UP);

}

/*********************************************************************
                            Board::~Board
 
 Description: This destructor frees dynamically allocated memory used
 in creating the 2d board array.
 *********************************************************************/
Board::~Board()
{
    for(int i = 0; i < rowCount; ++i)
    {
        delete [] boardArray[i];
    }
    delete [] boardArray;
    
    
}

/*********************************************************************
                          Board::printBoard
 
 Description: This void function displays the board state to the user.
 *********************************************************************/
void Board::printBoard()
{

    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            cout << boardArray[i][j] << " ";
        }
        cout << endl;
    }
    
}


/*********************************************************************
                            Board::start
 
 Description: This void function starts and runs the Langton Ant 
 through to its completion using the moveAnt() and printBoard() 
 member functions in a loop for the desired number of steps.
 *********************************************************************/
void Board::start()
{
    cout << endl;
    printBoard();
    for (int i = 0; i < steps; i++)
    {
        std::cout << "Step: " << (i+1) << ": " << endl;
        moveAnt();
        printBoard();
        cout << endl;
    }

}

/*********************************************************************
                            Board::moveAnt
 
 Description: This void function advances the ant a single step and
 incorporates the logic to determine which direction the ant should 
 turn, flipping cell colors, and  how to handle the behavior when the 
 ant encounters a boundary of the board.
 *********************************************************************/
void Board::moveAnt()
{
    // retrieve the cell color and direction from the ant object
    Color antCellColor = myAnt.getCellColor();
    Direction facing = myAnt.getDir();
    
    /* change the current cell color on the board
     based on the original color held by the ant object &*/
    flipBoardCellColor(antCellColor);
    

    if ((antCellColor == WHITE && facing==DOWN) || (antCellColor==BLACK && facing==UP))
    {
     
        // The ant is pointing south and turning right   -OR-
        // The ant is pointing north and turning left
        
        if (xCoord==0)  // ant will encounter left boundary
        {
            // reverse course
            xCoord++;
            myAnt.setDir(RIGHT);
            setAntCellColor();
            boardArray[yCoord][xCoord]='>';
        }
        else
        {
            // follow standard ant behavior
            xCoord--;
            myAnt.setDir(LEFT);
            setAntCellColor();
            boardArray[yCoord][xCoord]='<';
        }
    }

    if ((antCellColor == WHITE && facing==UP) || (antCellColor==BLACK && facing==DOWN))
    {
        // The ant is pointing north and turning right   -OR-
        // The ant is pointing south and turning left
        
        if (xCoord == (colCount-1)) // ant will encounter right boundary
        {
            // reverse course
            xCoord--;
            myAnt.setDir(LEFT);
            setAntCellColor();
            boardArray[yCoord][xCoord]='<';
        }
        else
        {
            // follow standard ant behavior
            xCoord++;
            myAnt.setDir(RIGHT);
            setAntCellColor();
            boardArray[yCoord][xCoord]='>';
        }
    }
    
    if ((antCellColor == WHITE && facing==LEFT) || (antCellColor==BLACK && facing==RIGHT))
    {
        // The ant is pointing west and turning right   -OR-
        // The ant is pointing east up and turning left
 
        if (yCoord == 0) // ant will encounter top boundary
        {
            // reverse course
            yCoord++;
            myAnt.setDir(DOWN);
            setAntCellColor();
            boardArray[yCoord][xCoord]='v';
            
        }
        else
        {
            // follow standard ant behavior
            yCoord--;
            myAnt.setDir(UP);
            setAntCellColor();
            boardArray[yCoord][xCoord]='^';
        }
    }
    
    if ((antCellColor == WHITE && facing==RIGHT) || (antCellColor==BLACK && facing==LEFT))
    {
        // The ant is pointing east and turning right   -OR-
        // The ant is pointing west up and turning left
        
        if (yCoord==(rowCount-1)) // ant will encounter bottom boundary
        {
            // reverse course
            yCoord--;
            myAnt.setDir(UP);
            setAntCellColor();
            boardArray[yCoord][xCoord]='^';
            
        }
        else
        {
            // follow standard ant behavior
            yCoord++;
            myAnt.setDir(DOWN);
            setAntCellColor();
            boardArray[yCoord][xCoord]='v';
        }
    }
}

/*********************************************************************
                        Board::setAntCellColor
 
 Description: This void function sets the enum cellColor property of 
 the ant object based on the board cell color of the current XY 
 coordinates.
 *********************************************************************/
void Board::setAntCellColor()
{
    if (boardArray[yCoord][xCoord]=='_')
    {
        myAnt.setCellColor(WHITE);
    }
    else
    {
        myAnt.setCellColor(BLACK);
    }
}

/*********************************************************************
                        Board::flipBoardCellColor
 
 Description: This void function changes the board cell color of the 
 current XY coordinates based on the a enum Color parameter.
 *********************************************************************/
void Board::flipBoardCellColor(Color cellColor)
{
    if (cellColor == WHITE)
    {
        boardArray[yCoord][xCoord]='#';
    } else {
        boardArray[yCoord][xCoord]='_';
    }
}
