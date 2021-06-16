// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: Menu.cpp
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-16
// Description: Defenition file for Menu class, OOO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX

#include "Menu.h"
#include <iostream>
#include <string>
#include <vector>
#include "cfl.h"
using cfl::getInputInt;

Menu::Menu() {
  menuText = "";
  menuList;
}
//---------------------------------------------------------------------------
Menu::Menu(std::string aMenuText) : menuText(aMenuText) { menuList; }
//---------------------------------------------------------------------------
// Name: setMenuTitle
// Desc: Set the menuTitle
//---------------------------------------------------------------------------
void Menu::setMenuTitle(std::string  aMenuText, std::string aMenuText2) {
  menuText = aMenuText + aMenuText2;
}
//---------------------------------------------------------------------------
// Name: addItem
// Desc: Add a menuitem
//---------------------------------------------------------------------------
void Menu::addItem(std::string aMenuText, std::string aMenuText2) {
  MenuItem aMenuItem(aMenuText, aMenuText2);
  menuList.push_back(aMenuItem);
}
//---------------------------------------------------------------------------
// Name: printMenuItems
// Desc: Print the Menu
//---------------------------------------------------------------------------
void Menu::printMenuItems() const {
  for (auto e : menuList) {
    std::cout << e.getMenuText() << std::endl;
  }
}
//---------------------------------------------------------------------------'
// Name: getMenuTitle
// Desc: Print the menu title.
//---------------------------------------------------------------------------
std::string Menu::getMenuTitle() const { return menuText; }
//---------------------------------------------------------------------------
// Name: getMenuChoice
// Desc:
// Return: int
//---------------------------------------------------------------------------
int Menu::getMenuChoice() const {
  int choice = getInputInt("Select an option from the Menu: ");

  return (choice);
}