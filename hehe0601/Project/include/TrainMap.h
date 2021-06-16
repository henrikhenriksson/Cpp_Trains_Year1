// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: TrainMap.h
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-21
// Description: Header file for TrainMap class, OO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
#ifndef TrainMap_H
#define TrainMap_H

#include <string>

//---------------------------------------------------------------------------
// TrainMap class holding distances between two stations.
//---------------------------------------------------------------------------

class TrainMap {
 public:
  TrainMap(std::string const &p_Dep, std::string const &p_des, int const &dist);

  std::string getDepStat() const { return dep_Station; }
  std::string getDesStat() const { return des_Station; }
  int getDistance() const { return distance; }

 private:
  std::string dep_Station;
  std::string des_Station;
  int distance;
};
//---------------------------------------------------------------------------
#endif  // TrainMap_H
