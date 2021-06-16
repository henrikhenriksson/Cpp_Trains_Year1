// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: CarFreightOpen.cpp
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-15
// Description: Defenition file for CarFreightOpen, OOO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX

#include "CarFreightOpen.h"

//---------------------------------------------------------------------------
// Desc: Initialized constructor, calling TrainCar Constructor.
//---------------------------------------------------------------------------
CarFreightOpen::CarFreightOpen(int p_Id, int p_Type, int p_Load_Capacity,
                               int p_Load_Area, std::string history)
    : load_Capacity(p_Load_Capacity),
      load_Area(p_Load_Area),
      TrainCar(p_Id, p_Type) {
  car_History.push_back(history);
}
//---------------------------------------------------------------------------
// Desc: Default Destructor:
//---------------------------------------------------------------------------
CarFreightOpen::~CarFreightOpen() {}
//---------------------------------------------------------------------------
// Name: printOn
// Desc: Print relevant information about the carriage:
//---------------------------------------------------------------------------
void CarFreightOpen::printOn(std::ostream& os) const {
  TrainCar::printOn(os);
  os << " Load Capacity: " << load_Capacity << " tonnes, "
     << "Load Area: " << load_Area << " m^2";
}
//---------------------------------------------------------------------------
