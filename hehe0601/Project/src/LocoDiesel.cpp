// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: LocoDiesel.cpp
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-14
// Description: Defenition file for LocoDIesel, OOO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX

#include "LocoDiesel.h"

//---------------------------------------------------------------------------
// Desc: Initialized Constructor, Calling TrainCar Constructor.
//---------------------------------------------------------------------------
LocoDiesel::LocoDiesel(int p_Id, int p_Type, int p_Max_Speed,
                       int p_fuel_Consume, std::string history)
    : max_Speed(p_Max_Speed),
      fuel_Consume(p_fuel_Consume),
      TrainCar(p_Id, p_Type) {
  car_History.push_back(history);
}
//---------------------------------------------------------------------------
// Desc: Default Destructor
//---------------------------------------------------------------------------
LocoDiesel::~LocoDiesel() {}
//---------------------------------------------------------------------------
// Name: printOn
// Desc: Print relevant information about the carriage:
//---------------------------------------------------------------------------
void LocoDiesel::printOn(std::ostream &os) const {
  TrainCar::printOn(os);
  os << " Max Speed: " << max_Speed << " km/h, "
     << "Fuel Consumation: " << fuel_Consume << " l/h";
}
//---------------------------------------------------------------------------