// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: Menu.h
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-16
// Description: Header file for Menu class, OO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
#ifndef Menu_H
#define Menu_H

#include <string>
#include <vector>
#include "cfl.h"
#include "menuItem.h"

//---------------------------------------------------------------------------
// Menu class - holds menutexts and adds and prints these menuitems.
//---------------------------------------------------------------------------

using cfl::getInputInt;

class Menu {
 public:
  Menu();
  Menu(std::string aMenuText);
  
  void printMenuItems() const;
  std::string getMenuTitle() const;
  int getMenuChoice() const;

  void setMenuTitle(std::string aMenuText, std::string aMenuText2 = "");
  void addItem(std::string aMenuText, std::string aMenuText2 = "");
  void clearMenuList() { menuList.clear(); }

 private:
  std::vector<MenuItem> menuList;
  std::string menuText;
};

#endif  // Menu_H
