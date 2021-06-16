// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: Simulation.cpp
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-24
// Description: Defenition file for Simulation class, OO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX

#include "Simulation.h"
#include <iostream>

//---------------------------------------------------------------------------
// Name: runSim
// Desc: Execute events unitl event queue is emtpy.
//---------------------------------------------------------------------------
void Simulation::runSim() {
  while (!eventQ.empty()) {
    Event_Ptr next_Event = eventQ.top();
    eventQ.pop();
    current_Time = next_Event->getTime();
    next_Event->processEvent();
  }
}
//---------------------------------------------------------------------------
// Name: runNextEvent
// Desc: Run the next event in the queue.
//---------------------------------------------------------------------------
void Simulation::runNextEvent() {
  if (!eventQ.empty()) {
    Event_Ptr next_Event = eventQ.top();
    eventQ.pop();
    current_Time = next_Event->getTime();
    next_Event->processEvent();
  }
}
//---------------------------------------------------------------------------
// Name: runNextInterval
// Desc: Run the next interval, 
//---------------------------------------------------------------------------
void Simulation::runNextInterval() {
  if (!eventQ.empty()) {
    int new_Interval = current_Time + interval;
    // double check to make sure the eventQ is not empty
    while (!eventQ.empty() && (eventQ.top()->getTime() <= new_Interval)) {
      Event_Ptr next_Event = eventQ.top();
      eventQ.pop();
      current_Time = next_Event->getTime();
      next_Event->processEvent();
    }
    current_Time = new_Interval;
  }
}
//---------------------------------------------------------------------------
// Name: shedEvent
// Desc: Add a new event to the event queue.
//---------------------------------------------------------------------------
void Simulation::schedEvent(const std::shared_ptr<Event>& newEvent) {
  eventQ.push(newEvent);
}
//---------------------------------------------------------------------------
// Name: ClearSimulation
// Desc: clear any events still in the eventQ.
//---------------------------------------------------------------------------
void Simulation::ClearSimulation() {
  while (!eventQ.empty()) {
    eventQ.pop();
  }
}
//---------------------------------------------------------------------------
