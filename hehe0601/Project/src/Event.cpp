// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: Event.cpp
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-23
// Description: Defenition file for Event class, OOO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX

#include "Event.h"
#include "Simulation.h"
#include "TrainSystem.h"

//---------------------------------------------------------------------------
// Name: processEvent
// Desc: Process event by invoking these functions:
//---------------------------------------------------------------------------
void AssembleEvent::processEvent() {
  // Attempt to build the train
  if (train_Brain->tryAssemble(train_Id)) {
    the_Sim->schedEvent(std::shared_ptr<Event>(new ReadyEvent(
        the_Sim, train_Brain, the_Sim->getTime() + SCHED_READY, train_Id)));
  } 
}
//---------------------------------------------------------------------------
void ReadyEvent::processEvent() {
  train_Brain->setReady(train_Id);
  the_Sim->schedEvent(std::shared_ptr<Event>(new RunningEvent(
      the_Sim, train_Brain, the_Sim->getTime() + SCHED_RUNNING, train_Id)));
}
//---------------------------------------------------------------------------
void RunningEvent::processEvent() {  
  train_Brain->setRunning(train_Id);
  int timeOf_Arr = train_Brain->getOneTrain(train_Id)->getArrTime();
  the_Sim->schedEvent(std::shared_ptr<Event>(
      new ArriveEvent(the_Sim, train_Brain, timeOf_Arr, train_Id)));
}
//---------------------------------------------------------------------------
void ArriveEvent::processEvent() {  
  train_Brain->setArrived(train_Id);
  the_Sim->schedEvent(std::shared_ptr<Event>(new FinishedEvent(
      the_Sim, train_Brain, the_Sim->getTime() + SCHED_DISASSEMBLE, train_Id)));
}
//---------------------------------------------------------------------------
void FinishedEvent::processEvent() { train_Brain->setFinished(train_Id); }
//---------------------------------------------------------------------------
