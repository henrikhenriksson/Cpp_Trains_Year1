// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: CarPersonSleep.h
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-15
// Description: Header file for CarPersonSleep, OOO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
#ifndef CarPersonSleep_H
#define CarPersonSleep_H

#include <string>
#include "TrainCar.h"

//---------------------------------------------------------------------------
// Sleeping Carriage, has private member counting beds, subclass of: TrainCar
//---------------------------------------------------------------------------

class CarPersonSleep : public TrainCar {
 public:
  CarPersonSleep(int p_Id, int p_Type, int p_Beds, std::string history);
  virtual ~CarPersonSleep();

  // print
  virtual void printOn(std::ostream &os) const;

 private:
  int beds;
};
//---------------------------------------------------------------------------
#endif  // CarPersonSleep_H
