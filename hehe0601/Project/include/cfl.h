// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: cfl.h
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-13
// Description: Header file file for  proj.h, OO programming C++
// Containing some often used functions.
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
#ifndef cfl_h
#define cfl_h

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

//---------------------------------------------------------------------------
// This file contains the common functions library stored in a custom namespace.
// The functions described below are called from within several functions and
// classes.
//---------------------------------------------------------------------------

namespace cfl {
void waitForKey();
void clearScreen();
std::string getInputStr(std::string str);
int getInputInt(std::string str);
int getInputTime(std::string str);
std::string intTimetoStr(int p_Time);
int timeStrtoMin(std::string str);
}  // namespace cfl
//---------------------------------------------------------------------------
#endif  // cfl_h
