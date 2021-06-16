// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: Event.h
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-23
// Description: Header file for Event class, OO programming C++
// This class is largely inspired by lecture material written by Örjan Sterner.
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
#ifndef Event_H
#define Event_H

#include <memory>

//---------------------------------------------------------------------------
// Event class - has forward declarations to simulation and trainsystem classes.
// Contains memberfunctions responsible for processing events.
//---------------------------------------------------------------------------
class Simulation;  // Forward Declaration:
class TrainSystem;

// Typedef:
typedef std::shared_ptr<Simulation> sim_Ptr;
typedef std::shared_ptr<TrainSystem> TrainSystem_Ptr;
//---------------------------------------------------------------------------
class Event {
 public:
  // Constructor requires time of event:
  Event(unsigned int t) : time(t) {}
  virtual ~Event() {}

  // Process event by invoking function:
  virtual void processEvent() = 0;

  // get event time:
  unsigned int getTime() const { return time; }

 protected:
  int time;
};
//---------------------------------------------------------------------------
// Class EventComparison. Used to compare to Events with respect to time
//---------------------------------------------------------------------------
class EventComparison {
 public:
  bool operator()(std::shared_ptr<Event> left, std::shared_ptr<Event> right) {
    return left->getTime() > right->getTime();
  }
};
//---------------------------------------------------------------------------
// Derived Classes:
//---------------------------------------------------------------------------
class AssembleEvent : public Event {
 public:
  AssembleEvent(sim_Ptr sim, TrainSystem_Ptr ts, int p_time, int p_train_Id)
      : Event(p_time), the_Sim(sim), train_Brain(ts), train_Id(p_train_Id) {}

  virtual void processEvent();

 protected:
  sim_Ptr the_Sim;
  TrainSystem_Ptr train_Brain;
  int train_Id;
};
//---------------------------------------------------------------------------
class ReadyEvent : public Event {
 public:
  ReadyEvent(sim_Ptr sim, TrainSystem_Ptr ts, int p_time, int p_train_Id)
      : Event(p_time), the_Sim(sim), train_Brain(ts), train_Id(p_train_Id) {}

  virtual void processEvent();

 protected:
  sim_Ptr the_Sim;
  TrainSystem_Ptr train_Brain;
  int train_Id;
};
//---------------------------------------------------------------------------
class RunningEvent : public Event {
 public:
  RunningEvent(sim_Ptr sim, TrainSystem_Ptr ts, int p_time, int p_train_Id)
      : Event(p_time), the_Sim(sim), train_Brain(ts), train_Id(p_train_Id) {}

  virtual void processEvent();

 protected:
  sim_Ptr the_Sim;
  TrainSystem_Ptr train_Brain;
  int train_Id;
};
//---------------------------------------------------------------------------
class ArriveEvent : public Event {
 public:
  ArriveEvent(sim_Ptr sim, TrainSystem_Ptr ts, int p_time, int p_train_Id)
      : Event(p_time), the_Sim(sim), train_Brain(ts), train_Id(p_train_Id) {}

  virtual void processEvent();

 protected:
  sim_Ptr the_Sim;
  TrainSystem_Ptr train_Brain;
  int train_Id;
};
//---------------------------------------------------------------------------
class FinishedEvent : public Event {
 public:
  FinishedEvent(sim_Ptr sim, TrainSystem_Ptr ts, int p_time, int p_train_Id)
      : Event(p_time), the_Sim(sim), train_Brain(ts), train_Id(p_train_Id) {}

  virtual void processEvent();

 protected:
  sim_Ptr the_Sim;
  TrainSystem_Ptr train_Brain;
  int train_Id;
};
//---------------------------------------------------------------------------
#endif  // Event_H
