/*********************************************************************
 ** Program name: menu.hpp
 ** Author: Alex Rueb
 ** Date: 4/16/2017
 ** Description: This is the interface file for the menu class.
 This class has been designed to be reusable for various projects
 with functionality that includes adding menu items, displaying a
 title for the menu, setting a message following the menu optinos,
 printing the menu, and getting an input from the user.  This
 class requires iVal.hpp and iVal.cpp for input validation.
 *********************************************************************/

#ifndef menu_hpp
#define menu_hpp

#include <iostream>
#include <vector>
#include <string>
#include "iVal.hpp"
using std::vector;
using std::string;

class Menu
{
private:
    vector <string> menuItems;
    string title;
    string bottomMsg;
public:
    void addItem(string);
    void print();
    void setTitle(string);
    void setBottomMsg(string);
    int  getSelection();
};

#endif /* menu_hpp */
