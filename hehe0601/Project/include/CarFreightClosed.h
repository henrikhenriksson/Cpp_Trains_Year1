// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: CarFreightClosed.h
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-15
// Description: Header file for CarFreightClosed, OOO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
#ifndef CarFreightClosed_H
#define CarFreightClosed_H

#include <string>
#include "TrainCar.h"

//---------------------------------------------------------------------------
// Closed Freight Carriage, has class member for loading volume, subclass of
// TrainCar.
//---------------------------------------------------------------------------

class CarFreightClosed : public TrainCar {
 public:
  CarFreightClosed(int p_Id, int p_Type, int p_Load_Vol, std::string history);
  virtual ~CarFreightClosed();

  // print info:
  virtual void printOn(std::ostream &os) const;

 private:
  int load_Vol;
};

//---------------------------------------------------------------------------
#endif  // CarFreightClosed_H
