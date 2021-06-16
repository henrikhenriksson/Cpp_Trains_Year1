// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: MenuItem.cpp
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-16
// Description: Defenition file for MenuItem class, OO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX

#include "MenuItem.h"
#include <string>

//---------------------------------------------------------------------------
// Name: MenuItem
// Desc: constructor. aMenuText2 is optional.
//---------------------------------------------------------------------------
MenuItem::MenuItem(std::string aMenuText, std::string aMenuText2)
    : menuText(aMenuText + aMenuText2) {}
//---------------------------------------------------------------------------
std::string MenuItem::getMenuText() const { return menuText; }
//---------------------------------------------------------------------------
