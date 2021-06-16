// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: LocoDiesel.h
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-14
// Description: Header file for LocoDiesel, OOO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
#ifndef LocoDiesel_H
#define LocoDiesel_H

#include <string>
#include "TrainCar.h"

//---------------------------------------------------------------------------
// Diesel Locomotive, holds member variables for max speed and fuel consumation.
// Subclass of TrainCar.
//---------------------------------------------------------------------------
class LocoDiesel : public TrainCar {
 public:
  LocoDiesel(int p_Id, int p_Type, int p_Max_Speed, int p_fuel_Consume,
             std::string history);
  virtual ~LocoDiesel();

  // print
  virtual void printOn(std::ostream &os) const;

 private:
  int max_Speed;
  int fuel_Consume;
};

//---------------------------------------------------------------------------
#endif  // LocoDiesel_H
