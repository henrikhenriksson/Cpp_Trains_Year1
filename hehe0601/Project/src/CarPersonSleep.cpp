// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: CarPersonSleep.cpp
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-15
// Description: Defenition file for CarPersonSleep, OOO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX

#include "CarPersonSleep.h"

//---------------------------------------------------------------------------
// Desc: Initialized Constructor, calling TrainCar constructor:
//---------------------------------------------------------------------------
CarPersonSleep::CarPersonSleep(int p_Id, int p_Type, int p_Beds,
                               std::string history)
    : beds(p_Beds), TrainCar(p_Id, p_Type) {
  car_History.push_back(history);
}
//---------------------------------------------------------------------------
// Desc: Default Destructor:
//---------------------------------------------------------------------------
CarPersonSleep::~CarPersonSleep() {}
//---------------------------------------------------------------------------
// Name: printOn
// Desc: Print relevant information about the carriage:
//---------------------------------------------------------------------------
void CarPersonSleep::printOn(std::ostream& os) const {
  TrainCar::printOn(os);
  os << " Available Beds: " << beds;
}
//---------------------------------------------------------------------------
