// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: TrainCar.h
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-14
// Description: Header file for TrainCar class, OOO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
#ifndef TrainCar_H
#define TrainCar_H

#include <iostream>
#include <string>
#include <vector>
#include "Constants.h"

//---------------------------------------------------------------------------
// Abstract Class for all train car types. All trains concist of several of train
// carriage, Parent class of Locomotive and Carriage types. Has members for
// Carriage ID and Type.
//---------------------------------------------------------------------------

class TrainCar {
 public:
  TrainCar(int p_id, int p_type);
  virtual ~TrainCar();
  virtual int getcType() const { return tc_Type; }
  virtual int getcID() const { return tc_id; }

  // Getter
  std::vector<std::string> getCarHistory() const { return car_History; }

  // Print - pure virtual with a return used in sub-classes
  virtual void printOn(std::ostream &os = std::cout) const = 0;

  void addCarHistory(const std::string &his) { car_History.push_back(his); }

 protected:
  int tc_id;
  int tc_Type;
  std::string type_str;
  std::vector<std::string> car_History;
};
std::ostream &operator<<(std::ostream &os, std::shared_ptr<TrainCar> traincar);
//---------------------------------------------------------------------------
#endif  // TrainCar_H
