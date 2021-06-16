// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: CarFreightClosed.cpp
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-15
// Description: Defenition file for CarFreightClosed, OOO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX

#include "CarFreightClosed.h"

//---------------------------------------------------------------------------
// Desc: Initialized constructor, calling TrainCar constructor:
//---------------------------------------------------------------------------
CarFreightClosed::CarFreightClosed(int p_Id, int p_Type, int p_Load_Vol,
                                   std::string history)
    : load_Vol(p_Load_Vol), TrainCar(p_Id, p_Type) {
  car_History.push_back(history);
}
//---------------------------------------------------------------------------
// Desc: Destructor:
//---------------------------------------------------------------------------
CarFreightClosed::~CarFreightClosed() {}
//---------------------------------------------------------------------------
// Name: printOn
// Desc: Print relevant information about the carriage:
//---------------------------------------------------------------------------
void CarFreightClosed::printOn(std::ostream& os) const {
  TrainCar::printOn(os);
  os << " Load Volume: " << load_Vol << " m^3";
}
//---------------------------------------------------------------------------
