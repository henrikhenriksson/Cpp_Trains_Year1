// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: MenuItem.h
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-16
// Description: Header file for MenuItem class, OO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
#ifndef MenuItem_H
#define MenuItem_H

#include <string>

//---------------------------------------------------------------------------
// MenuItem class - holds menutext strings.
//---------------------------------------------------------------------------

class MenuItem {
 public:
  MenuItem() = default;
  MenuItem(std::string aMenuText, std::string aMenuText2 = "");

  std::string getMenuText() const;

 private:
  std::string menuText;
};

#endif  // MenuItem_H
