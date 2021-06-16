// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: Simulation.h
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-24
// Description: Header file for Simulation class, OO programming C++
// This class is largely inspired by lecture material written by Örjan Sterner.
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
#ifndef Simulation_H
#define Simulation_H

#include <memory>
#include <queue>
#include <vector>
#include "Event.h"

//---------------------------------------------------------------------------
// Simulation Class: Forward declared from Event.cpp, handles the storage of
// new events in a priority queue and the time "between" events.
//---------------------------------------------------------------------------

typedef std::shared_ptr<Event> Event_Ptr;

class Simulation {
 public:
  Simulation() : current_Time(0), interval(10), eventQ() {}

  int getTime() { return current_Time; }
  int getInterval() const { return interval; }

  void runSim();
  void runNextEvent();
  void runNextInterval();

  void schedEvent(const std::shared_ptr<Event> &newEvent);
  void setCurrentTime(int p_Time) { current_Time = p_Time; }
  void setInterval(const int &pInter) { interval = pInter; }

  void ClearSimulation();

 private:
  int current_Time;
  int interval;

  std::priority_queue<Event_Ptr, std::vector<Event_Ptr>, EventComparison>
      eventQ;
};

//---------------------------------------------------------------------------
#endif  // Simulation_H
