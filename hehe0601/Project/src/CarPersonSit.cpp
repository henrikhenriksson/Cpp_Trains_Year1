// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: CarPersonSit.cpp
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-15
// Description: Defenition file for CarPersonSit, OOO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX

#include "CarPersonSit.h"

//---------------------------------------------------------------------------
// Desc: Initialized Constructor, calling TrainCar Constructor.
//---------------------------------------------------------------------------
CarPersonSit::CarPersonSit(int p_Id, int p_Type, int p_Seats, bool p_Internet,
                           std::string history)
    : seats(p_Seats), internet_Access(p_Internet), TrainCar(p_Id, p_Type) {
  car_History.push_back(history);
}
//---------------------------------------------------------------------------
// Desc: Destructor
CarPersonSit::~CarPersonSit() {}
//---------------------------------------------------------------------------
// Name: printOn
// Desc: Print relevant information about the carriage:
//---------------------------------------------------------------------------
void CarPersonSit::printOn(std::ostream& os) const {
  TrainCar::printOn(os);
  os << " Available seats: " << seats << ","
     << " Internet Access: ";

  if (internet_Access) {
    os << "Available.";

  } else {
    os << "Not Available.";
  }
}
//---------------------------------------------------------------------------
