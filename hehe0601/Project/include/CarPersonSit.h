// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: CarPersonSit.h
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-15
// Description: Header file for CarPersonSit, OOO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
#ifndef CarPersonSit_H
#define CarPersonSit_H

#include <string>
#include "TrainCar.h"

//---------------------------------------------------------------------------
// "Sitting" Carriage, has seats and possible internet access
// (first class/coach?). Subclass of TrainCar.
//---------------------------------------------------------------------------

class CarPersonSit : public TrainCar {
 public:
  CarPersonSit(int p_Id, int p_Type, int p_Seats, bool p_Internet,
               std::string history);
  virtual ~CarPersonSit();

  // Print
  virtual void printOn(std::ostream &os) const;

 private:
  int seats;
  bool internet_Access;
};

//---------------------------------------------------------------------------
#endif  // CarPersonSit_H
