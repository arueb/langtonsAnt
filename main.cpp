/*********************************************************************
 ** Program name: main.cpp
 ** Author: Alex Rueb
 ** Date: 4/16/2017
 ** Description: This program runs a simulation of Langton's Ant,
    where an ant is placed on a board matrix and must follows a simple 
    set of instrucdtions.  In a white square, the ant must turn right 
    90 degrees and change the square to black. In a black square, the 
    ant must turn left 90 degrees and change the square to white.  The 
    user has the option to specify the size of the board, the starting 
    ant position, and the number of steps to perform.  There are also
    options to use a random start position for the ant or to use the
    defaul settings.
 *********************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "board.hpp"
#include "menu.hpp"
#include "iVal.hpp"

using namespace std;

int main()
{

    // create start menu using the Menu class
    Menu startMenu;
    startMenu.setTitle("Welcome to the Langton's Ant Simulator");
    startMenu.addItem("Run with Default Settings");
    startMenu.addItem("Run with Custom Settings");
    startMenu.addItem("Run with Random Ant Starting Position");
    startMenu.addItem("Exit");
    startMenu.setBottomMsg("Please enter a number to make your selection.");
    
    int selection = startMenu.getSelection();

    int steps, rows, cols, antX, antY; // required values to create Board object
    
    if (selection == 1) // run simulation with default settings
    {
        steps = 200;
        rows = 15;
        cols = 15;
        antX = 7;
        antY = 7;
        
        Board antBoard(rows,cols,steps,antX,antY);
        antBoard.start();
    }
    
    if (selection == 2) // run simulation with custom settings
    {
        std::cout << "Enter number of steps (maximum 10,000): \n";
        steps = getValidInt(1,10000);
        
        std::cout << "Enter number of rows (maximum 80): \n";
        rows = getValidInt(2,80);
        
        std::cout << "Enter number of columns (maximum 80): \n";
        cols = getValidInt(2,80);
        
        std::cout << "Enter ant X Position: \n";
        antX = getValidInt(1,cols)-1;
        
        std::cout << "Enter ant Y Position: \n";
        antY = getValidInt(1,rows)-1;
    
        Board antBoard(rows,cols,steps,antX,antY);
        antBoard.start();
    }
    
    if (selection == 3) // run simulation with random ant position
    {
        std::cout << "Enter number of steps (maximum 10,000): \n";
        steps = getValidInt(1,10000);
        
        std::cout << "Enter number of rows (maximum 80): \n";
        rows = getValidInt(2,80);
        
        std::cout << "Enter number of columns (maximum 80): \n";
        cols = getValidInt(2,80);
        
        srand(time(0)); //seed random number generator
        antX = rand() % cols; // generate random x position
        antY = rand() % rows; // generate random y position

        Board antBoard(rows,cols,steps,antX,antY);
        antBoard.start();
    }

    if (selection == 4) // exit program
    {
        std::cout << "Goodbye!" << std::endl;
    }
    
    
    return 0;
}
