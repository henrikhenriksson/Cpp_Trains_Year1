// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: cfl.cpp
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-13
// Description: Defenition file for cfl namespace, OOO programming C++
// Containing some often used functions.
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX

#include "cfl.h"
#include <iostream>
#include <sstream>
#include <string>

//---------------------------------------------------------------------------
namespace cfl {

//---------------------------------------------------------------------------
// Name: waitForKey
// Desc: Define user system and pause the program
//---------------------------------------------------------------------------
void cfl::waitForKey() {
#if defined _WIN32
  system("pause");
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
  cout << "press ENTER to continue";
  cin.get();
#elif defined(__APPLE__)
  cout << "Press ENTER to continue";
  cin.get();

#endif
}

//---------------------------------------------------------------------------
// Name: clearScreen
// Desc: Define user system and Clear the console.
//---------------------------------------------------------------------------
void cfl::clearScreen() {
// Windows
#if defined _WIN32
  system("cls");

// Linux
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
  system("clear");

// Mac
#elif defined(__APPLE__)
  system("clear");
#endif
}
//---------------------------------------------------------------------------
// Name: getInputStr
// Desc: Print input parameter string, getline std::string to return and
// check for blank std::strings.
// Return: std::string
//---------------------------------------------------------------------------
std::string cfl::getInputStr(std::string str) {
  std::cout << str;
  std::string tmpString;
  std::getline(std::cin, tmpString);
  while (tmpString.empty()) {
    std::cout << "Invalid input! Try again: ";
    std::getline(std::cin, tmpString);
  }
  return tmpString;
}
//---------------------------------------------------------------------------
// Name: getInputTime
// Desc: Print input parameter string, getline new str with format check
// Return: std::string
//---------------------------------------------------------------------------
int getInputTime(std::string str) {
  int hours;
  int minutes;
  char colon;

  // Check time loop:
  do {
    std::cout << str;
    std::string tmpTime;
    getline(std::cin, tmpTime);

    std::istringstream iss(tmpTime);
    iss >> hours >> colon >> minutes;

  } while (!((hours >= 0) && (minutes >= 0 && minutes < 60) && (colon == ':')));
  return (hours * 60) + minutes;
}
//---------------------------------------------------------------------------
// Name: getInputInt
// Desc: print std::string, std::cin int, errorcheck to make sure its an int.
// Return: int.
//---------------------------------------------------------------------------
int cfl::getInputInt(std::string str) {
  std::cout << std::endl << str;
  int tmpInt;
  std::cin >> tmpInt;

  while (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input! Try again: ";
    std::cin >> tmpInt;
  }
  std::cin.get();
  return tmpInt;
}
//---------------------------------------------------------------------------
// Name: intTimetoStr
// Desc:
// Return: std::string
//---------------------------------------------------------------------------
std::string cfl::intTimetoStr(int p_Time) {
  int hour = p_Time / 60;
  int minute = p_Time % 60;
  if (hour >= 24) {
    hour = 0;
  }
  std::string time_str;
  std::stringstream ss;
  ss << std::setprecision(2) << std::setw(2) << std::setfill('0') << hour << ":"
     << std::setprecision(2) << std::setw(2) << std::setfill('0') << minute;

  ss >> time_str;

  return time_str;
}
//---------------------------------------------------------------------------
// Name: timeStrtoMin
// Desc: convert time from std::string to ints for storage.
// Return: Int
//---------------------------------------------------------------------------
int cfl::timeStrtoMin(std::string str) {
  int int_Time;
  std::stringstream ss(str);
  std::string hour, minute;
  getline(ss, hour, ':');
  getline(ss, minute);

  int_Time = std::stoi(minute) + (std::stoi(hour) * 60);

  return int_Time;
}
}  // namespace cfl
//---------------------------------------------------------------------------
