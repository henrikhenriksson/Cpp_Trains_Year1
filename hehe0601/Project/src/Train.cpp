// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: Train.cpp
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-15
// Description: Defenition file for Train, OOO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX

#include "Train.h"

//---------------------------------------------------------------------------
// Desc: Initialized constructor
// include the std::vector somehow.
Train::Train(int p_Train_Num, std::string dep_Stat, std::string arr_Stat,
             int p_time_dep, int p_time_arr, double p_Mean,
             std::vector<int> p_req_car)
    : train_Num(p_Train_Num),
      departure_Station(dep_Stat),
      destination_Station(arr_Stat),
      time_Departure(p_time_dep),
      time_Arrival(p_time_arr),
      mean_Speed(p_Mean),
      avg_Speed(0),
      req_Carriages(p_req_car),
      t_State(NOT_ASSEMBLED),
      is_Late(false) {}
//---------------------------------------------------------------------------
// Desc: Destructor
//---------------------------------------------------------------------------
Train::~Train() {}
//---------------------------------------------------------------------------
// Name:
// Desc:
// Return:
//---------------------------------------------------------------------------
std::string Train::getStatetoStr() const {
  switch (t_State) {
    case NOT_ASSEMBLED:
      return "NOT ASSEMBLED";
      break;
    case INCOMPLETE:
      return "INCOMPLETE";
      break;
    case ASSEMBLED:
      return "ASSEMBLED";
      break;
    case READY:
      return "READY";
      break;
    case RUNNING:
      return "RUNNING";
      break;
    case ARRIVED:
      return "ARRIVED";
      break;
    case FINISHED:
      return "FINISHED";
      break;
    default:
      break;
  }
}
//---------------------------------------------------------------------------
// Name: printTrainInfo
// Desc: Read train information to std::ostream object
//---------------------------------------------------------------------------
void Train::printTrainInfo(std::ostream& os) const {
  os << " Train: "
     << "[" << train_Num << "] ";
  switch (t_State) {
    case NOT_ASSEMBLED:
      os << " (NOT ASSEMBLED)";
      break;
    case INCOMPLETE:
      os << " (INCOMPLETE)";
      break;
    case ASSEMBLED:
      os << " (ASSEMBLED)";
      break;
    case READY:
      os << " (READY)";
      break;
    case RUNNING:
      os << " (RUNNING)";
      break;
    case ARRIVED:
      os << " (ARRIVED)";
      break;
    case FINISHED:
      os << " (FINISHED)";
      break;
  }
  os << " from " << departure_Station << " "
     << cfl::intTimetoStr(time_Departure) << " to " << std::endl
     << destination_Station << " " << cfl::intTimetoStr(time_Arrival)
     << ", Speed: " << mean_Speed << "km/h";
}
//---------------------------------------------------------------------------
// Name: printMissingTrains
// Desc: Switch case printing the type of the missing carriage:
//---------------------------------------------------------------------------
std::string Train::TrainCarTypeToStr(int car_Type) {
  switch (car_Type) {
    case PERSON_SIT:
     return "[Coach Carriage]";
      break;
    case PERSON_SLEEP:
      return "[Sleeping Carriage]";
      break;
    case FREIGHT_OPEN:
      return "[Open Freight Carriage]";
      break;
    case FREIGHT_CLOSED:
      return "[Closed Freight Carriage]";
      break;
    case LOCO_ELEC:
      return "[Electric Locomotive]";
      break;
    case LOCO_DIESEL:
      return "[Diesel Locomotive]";
      break;
  }
}
//---------------------------------------------------------------------------
// Name: addTrainCarstoTrain
// Desc: Add a traincar to the train map.
//---------------------------------------------------------------------------
void Train::addTrainCarstoTrain(const trainCar_Pair& car) { train_Obj.insert(car); }
//---------------------------------------------------------------------------
// Name: removeCarfromTrain
// Desc: Remove cars from the trains ownership at the destination station
//---------------------------------------------------------------------------
void Train::removeCarfromTrain(const int& c_Id) { train_Obj.erase(c_Id); }
//---------------------------------------------------------------------------
// Name: operator<<
// Desc: Overload << operator to print train information.
// Return: std::ostream
//---------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, std::shared_ptr<Train> pTrain) {
  pTrain->printTrainInfo(os);
  return os;
}
//---------------------------------------------------------------------------
