// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: CarFreightOpen.h
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-15
// Description: Header file for CarFreightOpen, OOO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
#ifndef CarFreightOpen_H
#define CarFreightOpen_H

#include <string>
#include "TrainCar.h"

//---------------------------------------------------------------------------
// Open Freight Carriage, has private members for load capacity in tonnes, and
// load are in m2, sublass of TrainCar
//---------------------------------------------------------------------------

class CarFreightOpen : public TrainCar {
 public:
  CarFreightOpen(int p_Id, int p_Type, int p_Load_Capacity, int p_Load_Area,
                 std::string history);
  virtual ~CarFreightOpen();

  // Print information:
  virtual void printOn(std::ostream &os) const;

 private:
  int load_Capacity;
  int load_Area;
};

//---------------------------------------------------------------------------
#endif  // CarFreightOpen_H
