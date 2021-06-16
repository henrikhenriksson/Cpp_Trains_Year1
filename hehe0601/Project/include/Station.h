// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: Station.h
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-16
// Description: Header file for Station class, OO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
#ifndef Station_H
#define Station_H

#include <map>
#include <memory>
#include <string>
#include "Constants.h"
#include "TrainCar.h"

//---------------------------------------------------------------------------
// Station class, Stations have names and a pool of Train Carriages at the
// beginning the simulation, station objects release and accept train carriages
// from train class objects
//---------------------------------------------------------------------------

typedef std::pair<int, std::shared_ptr<TrainCar>> trainCar_Pair;
typedef std::map<int, std::shared_ptr<TrainCar>> TrainCar_Map;
typedef std::shared_ptr<TrainCar> TrainCar_Ptr;

class Station {
 public:
  Station() = default;
  Station(std::string p_Station_Name);
  ~Station();
  //---------------------------------------------------------------------------
  // Get functions:
  //---------------------------------------------------------------------------
  std::string getStationName() const { return station_Name; }
  int getCarPoolAtStart() const { return CarPool_Atstart; }
  TrainCar_Map const& GetStationPool() { return station_Pool; }
  size_t getTrainPoolSize() const { return station_Pool.size(); }
  //---------------------------------------------------------------------------
  // Set functions:
  //---------------------------------------------------------------------------
  void removeCarFromStation(int c_Id);
  void addCartoStationFromTrain(const trainCar_Pair& car);
  void addCarToStaionPool(int p_Id, int p_Type, int param0, int param1,
                          std::string const& his_Str);
  void clearStation();

 private:
  std::string station_Name;
  TrainCar_Map station_Pool;
  int CarPool_Atstart;
};
//---------------------------------------------------------------------------
#endif  // Station_H
