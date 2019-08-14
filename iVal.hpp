/*********************************************************************
 ** Program name: iVal.hpp
 ** Author: Alex Rueb
 ** Date: 4/16/2017
 ** Description: This is the interface file for a collection of
    input validation functions.  Functionality includes testing whether
    an input is a valid integer, getting a valid integer from the user
    with an optional minimum and/or maximum values.
 *********************************************************************/
#ifndef iVal_hpp
#define iVal_hpp

#include <string>
#include <iostream>
int getValidInt(int min, int max);
int getValidIntMin(int min);
int getValidInt();
bool isInt(std::string input);
#endif /* iVal_hpp */
