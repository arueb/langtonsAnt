/*********************************************************************
 ** Program name: ant.cpp
 ** Author: Alex Rueb
 ** Date: 4/16/2017
 ** Description: This is the implementation file for the Ant class 
    that represents the ant in the Langton's Ant simulation.  Data 
    members include dir and cellColor to represent the direction the 
    ant is facing as well as the color of the cell the ant is occupying.
    Corresponding set and get functions are provided for each data
    member. This class requires the included enum variables Direction
    and Color.
 *********************************************************************/

#include "ant.hpp"


/*********************************************************************
                            Ant::setDir
 
 Description: This void function sets the direction of the ant with 
 a enumerated Direction parameter.
 *********************************************************************/
void Ant::setDir(Direction d){
    dir = d;
}


/*********************************************************************
                            Ant::getDir
 
 Description: This function returns the direction of the ant as an 
 enumerated Direction value.
 *********************************************************************/
Direction Ant::getDir(){
    return dir;
}


/*********************************************************************
                            Ant::setCellColor
 
 Description: This void function sets the cell color of the ant with
 a enumerated Color parameter.
 *********************************************************************/
void Ant::setCellColor(Color cColor)
{
    cellColor = cColor;
}


/*********************************************************************
                            Ant::getCellColor
 
 Description: This function returns the color of the cell the
 ant is occupying as an enumerated Color value.
 *********************************************************************/
Color Ant::getCellColor()
{
    return cellColor;
}


/*********************************************************************
                                Ant::Ant
 
 Description: This default constructor sets the initial cell color
 that the ant is occupying to the inital enumberated Color value WHITE.
 *********************************************************************/
Ant::Ant()
{
    cellColor = WHITE; // sets initial cell color
}
