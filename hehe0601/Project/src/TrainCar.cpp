// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: TrainCar.cpp
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-14
// Description: Defenition file for TrainCar, OOO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX

#include "TrainCar.h"
//---------------------------------------------------------------------------
// Desc: Initialized constructor:
//---------------------------------------------------------------------------
TrainCar::TrainCar(int p_Id, int p_Type) : tc_id(p_Id), tc_Type(p_Type) {}
//---------------------------------------------------------------------------
// Desc: Default destructor
TrainCar::~TrainCar() {}
//---------------------------------------------------------------------------
// Name: printOn
// Desc: first instance of printOn - abstract classes can have a function
// defenition to be called by derived classes
//---------------------------------------------------------------------------
void TrainCar::printOn(std::ostream &os) const {
  switch (tc_Type) {
    case PERSON_SIT:
      os << "[Coach Carriage]";
      break;
    case PERSON_SLEEP:
      os << "[Sleeping Carriage]";
      break;
    case FREIGHT_OPEN:
      os << "[Open Freight Carriage]";
      break;
    case FREIGHT_CLOSED:
      os << "[Closed Freight Carriage]";
      break;
    case LOCO_ELEC:
      os << "[Electric Locomotive]";
      break;
    case LOCO_DIESEL:
      os << "[Diesel Locomotive]";
      break;
    default:
      break;
  }
  os << " ID: " << tc_id << ",";
}
//---------------------------------------------------------------------------
// Name: &operator<<
// Desc: overload the << operator to print information about a traincar
// Return: std::ostream
//---------------------------------------------------------------------------
std::ostream &operator<<(std::ostream &os, std::shared_ptr<TrainCar> traincar) {
  traincar->printOn(os);
  return os;
}
//---------------------------------------------------------------------------
