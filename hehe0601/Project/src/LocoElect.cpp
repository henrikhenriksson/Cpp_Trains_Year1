// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: LocoElect.cpp
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-14
// Description: Defenition file for LocoElect, OOO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX

#include "LocoElect.h"

//---------------------------------------------------------------------------
// Desc: Initialized Constructor, Calling TrainCar Constructor.
//---------------------------------------------------------------------------
LocoElect::LocoElect(int p_Id, int p_Type, int p_Max_Speed, int p_Kwh_Effect,
                     std::string history)
    : max_Speed(p_Max_Speed), kwh_Effect(p_Kwh_Effect), TrainCar(p_Id, p_Type) {
  car_History.push_back(history);
}
//---------------------------------------------------------------------------
// Desc: Default Destructor
//---------------------------------------------------------------------------
LocoElect::~LocoElect() {}
//---------------------------------------------------------------------------
void LocoElect::printOn(std::ostream& os) const {
  TrainCar::printOn(os);
  os << " Max Speed: " << max_Speed << ", "
     << "Power effect: " << kwh_Effect << " KW";
}
//---------------------------------------------------------------------------