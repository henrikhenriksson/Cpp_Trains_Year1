// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: UserInterface.h
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-13
// Description: Header file for UserInterface, OOO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
#ifndef TestSim_H
#define TestSim_H

#include <algorithm>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Constants.h"
#include "Menu.h"
#include "Simulation.h"
#include "TrainSystem.h"
#include "cfl.h"
//---------------------------------------------------------------------------
using cfl::clearScreen;
using cfl::getInputInt;
using cfl::getInputStr;
using cfl::waitForKey;
//---------------------------------------------------------------------------
// User Interface class. Contains smart pointers to other class objects, and
// main functions for printing information to console.
//---------------------------------------------------------------------------
typedef std::shared_ptr<Menu> menu_Ptr;

class UserInterface {
 public:
  UserInterface();
  ~UserInterface();
  void run();

 private:
  std::shared_ptr<Simulation> running_Sim;
  std::shared_ptr<TrainSystem> trainSystem_Ptr;

  //---------------------------------------------------------------------------
  // Bools used in the menu loops:
  bool run_Program, run_Sim, run_Sub, sim_Done;
  //---------------------------------------------------------------------------
  // Menu objects
  //---------------------------------------------------------------------------
  menu_Ptr start_Menu;
  menu_Ptr train_Menu;
  menu_Ptr station_Menu;
  menu_Ptr simulation_Menu;
  menu_Ptr trainCar_Menu;
  menu_Ptr statistics_Menu;
  menu_Ptr logLevel_Menu;
  //---------------------------------------------------------------------------
  // Print menu functions
  //---------------------------------------------------------------------------
  void runStartMenu();
  void runTrainMenu();
  void runStationMenu();
  void runSimulationMenu();
  void runTrainCarMenu();
  void runStatisticsMenu();
  void runLogLevelMenu();
  void buildMenuSystem();
  void clearAllMenues();
  void newStartTime();
  void newEndTime();
  //---------------------------------------------------------------------------
  // Train Sub Menu Functions:
  //---------------------------------------------------------------------------
  void showTrainByTrainID();
  void printOneTrain(const train_Ptr& pTrain);
  void showTrainByTrainCarID();
  void showAllTrains();
  void printMissingCars(int car_Type);
  //---------------------------------------------------------------------------
  // Station Sub Menu Functions:
  //---------------------------------------------------------------------------
  void showStationNames();
  void showStationByName();
  void showAllStations();
  void printOneStation(const station_Ptr& tmp_StationPtr);
  //---------------------------------------------------------------------------
  // Simulation Sub Menu Functions:
  //---------------------------------------------------------------------------
  void schedEvents();
  void changeInterval();
  void runNextInterval();
  void runNextEvent();
  void finishSimulation();
  //---------------------------------------------------------------------------
  // Train Car Menu Sub Functions:
  //---------------------------------------------------------------------------
  void showTrainCarByID();
  void showAllTrainCars();
  void printTrainCar(const TrainCar_Ptr& car);
  //---------------------------------------------------------------------------
  // Statistics menu sub function:
  void printStatistics();
  //---------------------------------------------------------------------------
  // Log level menu sub functions:
  //---------------------------------------------------------------------------
  void setLogToLow();
  void setLogToHigh();
  std::string getLoglvl();
  //---------------------------------------------------------------------------
  void asciiTrain();
};
//---------------------------------------------------------------------------
#endif  // TestSim_H
