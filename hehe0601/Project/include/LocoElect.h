// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: LocoElect.h
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-14
// Description: Header file for LocoElect, OOO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
#ifndef LocoElect_H
#define LocoElect_H

#include <string>
#include "TrainCar.h"

//---------------------------------------------------------------------------
// Electric Locomotive, holds variables for max speed and power effect. Subclass
// of TrainCar
//---------------------------------------------------------------------------

class LocoElect : public TrainCar {
 public:
  LocoElect(int p_Id, int p_Type, int p_Max_Speed, int p_Kwh_Effect,
            std::string history);
  virtual ~LocoElect();

  // print
  virtual void printOn(std::ostream &os) const;

 private:
  int max_Speed;
  int kwh_Effect;
};

//---------------------------------------------------------------------------
#endif  // LocoElect_H
