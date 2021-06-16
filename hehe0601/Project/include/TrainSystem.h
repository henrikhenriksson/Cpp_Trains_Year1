// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: TrainSystem.h
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-21
// Description: Header file for TrainSystem class, OO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
#ifndef TrainSystem_H
#define TrainSystem_H

#include <algorithm>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>
#include "Constants.h"
#include "Simulation.h"
#include "Station.h"
#include "Train.h"
#include "TrainMap.h"
#include "cfl.h"
//---------------------------------------------------------------------------
using cfl::intTimetoStr;
using cfl::timeStrtoMin;
//---------------------------------------------------------------------------
// Train system class. This is the class representing the train company and
// fills the role as a train and station controller. It contains member
// functions responsible for train and station containers and certain printing
// to console and file. It is not a silent class.
//---------------------------------------------------------------------------
typedef std::shared_ptr<Station> station_Ptr;
typedef std::shared_ptr<Train> train_Ptr;
typedef std::pair<std::string, station_Ptr> station_Pair;
typedef std::pair<int, train_Ptr> train_Pair;
typedef std::map<std::string, station_Ptr> station_Map;
typedef std::map<int, train_Ptr> trainPtr_Map;
//---------------------------------------------------------------------------
class TrainSystem {
 public:
  TrainSystem() = default;
  TrainSystem(std::shared_ptr<Simulation> p_Sim);
  ~TrainSystem();
  //---------------------------------------------------------------------------
  // Read and print to file functions:
  //---------------------------------------------------------------------------
  void readFromFile();
  void openFiles();
  void closeFiles();
  //---------------------------------------------------------------------------
  // Event functions:
  //---------------------------------------------------------------------------
  bool tryAssemble(int train_Id);
  void setReady(int train_Id);
  void setRunning(int train_Id);
  void setArrived(int train_Id);
  void setFinished(int train_Id);
  void printEvent(const train_Ptr &tmp_TrainPtr);
  void printTrainDetail(const train_Ptr &tmp_TrainPtr);
  //---------------------------------------------------------------------------
  // Getters:
  //---------------------------------------------------------------------------
  train_Ptr getOneTrain(int train_id);
  station_Ptr getOneStation(std::string &station_Name);

  trainPtr_Map const &getTrainLine() { return train_Table; }
  station_Map const &getStationSystem() { return train_Stations; }
  int getDistance(std::string dep_Station, std::string des_Station) const;
  int getStarTime() const { return start_Time; }
  int getEndTime() const { return end_Time; }
  LOG_LEVEL getLogLvl() const { return logLevel; }
  //---------------------------------------------------------------------------
  // setters:
  //---------------------------------------------------------------------------
  void setStarTime(int p_Time);
  void setEndTime(int p_Time);
  void setLogLvl(LOG_LEVEL pLog) { logLevel = pLog; }
  //---------------------------------------------------------------------------
  void clearTrainSystemData();
  //---------------------------------------------------------------------------
 private:
  LOG_LEVEL logLevel;
  // filestreams:
  std::ifstream train_File;
  std::ifstream station_File;
  std::ifstream map_File;
  std::ofstream train_Sim;

  // containers for shared_ptrs to train and station and map objects:
  trainPtr_Map train_Table;
  station_Map train_Stations;
  std::vector<std::shared_ptr<TrainMap>> train_Map;
  // the running simulation:
  std::shared_ptr<Simulation> the_Sim;
  int start_Time;
  int end_Time;
};

#endif  // TrainSystem_H
//---------------------------------------------------------------------------
