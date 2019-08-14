/*********************************************************************
 ** Program name: iVal.cpp
 ** Author: Alex Rueb
 ** Date: 4/16/2017
 ** Description: This is the implementation file for a collection of 
    input validation functions.  Functionality includes testing whether
    an input is a valid integer, getting a valid integer from the user
    with an optional minimum and/or maximum values.
 *********************************************************************/


#include <string>
#include "iVal.hpp"

// gets and returns a valid integer within the minimum and maximum values provided as parameters
int getValidInt(int minInput,  int maxInput){
    
    int validInt;
    std::string input;
    bool isValid = false;
    
    do // loop until input is valid
    {
        getline(std::cin, input);
        if(isInt(input))
        {
            validInt = stoi(input);
            if (validInt < minInput || validInt > maxInput)
            {
                std::cout << "Invalid input:  Please enter an integer value between " << minInput << " and " << maxInput << "." << std::endl;
            }
            else
            {
                isValid = true;
            }
            
        }
        else
        {
            std::cout << "Invalid input: please enter an integer value." << std::endl;
        }
    } while (isValid ==false);
    return validInt;
    
}

// gets and returns a valid integer that is greater than or equal to the minimum value provided as a parameter.
int getValidIntMin(int minInput){
    
    int validInt;
    std::string input;
    bool isValid = false;
    
    do // loop until input is valid
    {
        getline(std::cin, input);
        if(isInt(input))
        {
            validInt = stoi(input);
            if (validInt < minInput)
            {
                std::cout << "Invalid input: please enter an integer value greater than or equal to " << minInput << "." << std::endl;
            }
            else
            {
                isValid = true;
            }
            
        }
        else
        {
            std::cout << "Invalid input: please enter an integer value." << std::endl;
        }
    } while (isValid ==false);
    return validInt;
    
}

// gets and returns a valid integer
int getValidInt(){
    std::string input;
    bool isValid = false;
    
    do // loop until input is valid
    {
        getline(std::cin, input);
        if(isInt(input))
        {
            isValid = true;
        }
        else
        {
            std::cout << "Invalid input: please enter an integer value." << std::endl;
        }
    } while (isValid ==false);
    return stoi(input);
    
}

// tests if an integer is valid and returns a Boolean value true or false.
bool isInt(std::string input){
    bool isValid = true;
    
    // loop through input string to test for non-numerical characters
    for (int i = 0; i < input.length(); i++)      {
        if( !isdigit(input[i]) && input[i]!='-')
        {
            return false;
        }
    }
    return isValid;
}
