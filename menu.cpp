/*********************************************************************
 ** Program name: menu.cpp
 ** Author: Alex Rueb
 ** Date: 4/16/2017
 ** Description: This is the implementation file for the menu class. 
    This class has been designed to be reusable for various projects
    with functionality that includes adding menu items, displaying a
    title for the menu, setting a message following the menu optinos, 
    printing the menu, and getting an input from the user.  This 
    class requires iVal.hpp and iVal.cpp for input validation.
 *********************************************************************/

#include "menu.hpp"

/*********************************************************************
                            Menu::addItem
 
 Description: This void function accepts a string parameter and adds
 it to the menuItems vector.
 *********************************************************************/
void Menu::addItem(string itemInput)
{
    menuItems.push_back(itemInput);
}


/*********************************************************************
                            Menu::setTitle
 
 Description: This void function accepts a string parameter and sets
 the title data member.
 *********************************************************************/
void Menu::setTitle(string titleInput)
{
    title = titleInput;
}


/*********************************************************************
                            Menu::setTitle
 
 Description: This void function accepts a string parameter and sets
 the bottomMsg data member.
 *********************************************************************/
void Menu::setBottomMsg(string msg)
{
    bottomMsg = msg;
}


/*********************************************************************
                              Menu::print
 
 Description: This void function displays the menu items held in the 
 menuItems vecotr along with a title and bottom message.
 *********************************************************************/
void Menu::print()
{
    if (title.length()>0)
    {
    std::cout << title << std::endl << std::endl;
    }
    
    for (int i=0; i < menuItems.size(); i++)
    {
        std::cout << (i+1) << ") " << menuItems[i] << std::endl;
    }
    
    if (bottomMsg.length()>0)
    {
        std::cout << std::endl << bottomMsg << std::endl;
    }
    
    std::cout << std::endl << std::endl;
    
    
}

/*********************************************************************
                        Menu::getSelection
 
 Description: This function gets a selection from the user within the 
 bounds of the menu items conained wihtin in the menuItems vector and 
 returns an integer value.
 *********************************************************************/
int Menu::getSelection()
{
    print();
    return getValidInt(1,menuItems.size());
}


