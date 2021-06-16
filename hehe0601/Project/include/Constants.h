// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: Constants.h
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-16
// Description: Header file for Constants, OO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
#ifndef Constants_H
#define Constants_H

#include <string>

//---------------------------------------------------------------------------
// Constants header.
//---------------------------------------------------------------------------

const std::string TRAINFILE = "Trains.txt";
const std::string STATFILE = "TrainStations.txt";
const std::string MAPFILE = "TrainMap.txt";
const std::string LOGFILE = "TrainSim.log";
//---------------------------------------------------------------------------
const char DELIM = ' ';
const char NEWLINE = '\n';
//---------------------------------------------------------------------------
const int SIM_TIME_START = 0;
const int SIM_TIME_END = 1439; // total minutes between 00:00 - 23:59
const int SCHED_BUILD = 30;
const int SCHED_READY = 20;
const int SCHED_RUNNING = 10;
const int SCHED_DISASSEMBLE = 20;
//---------------------------------------------------------------------------
enum TRAIN_STATE {
  NOT_ASSEMBLED,
  INCOMPLETE,
  ASSEMBLED,
  READY,
  RUNNING,
  ARRIVED,
  FINISHED,
};
//---------------------------------------------------------------------------
enum TRAINCAR_TYPE {
  PERSON_SIT,
  PERSON_SLEEP,
  FREIGHT_OPEN,
  FREIGHT_CLOSED,
  LOCO_ELEC,
  LOCO_DIESEL,
};
//---------------------------------------------------------------------------
enum LOG_LEVEL {
  LOW_LOG,
  HIGH_LOG,
};
//---------------------------------------------------------------------------
#endif  // Constants_H
