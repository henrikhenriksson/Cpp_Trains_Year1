// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: Station.cpp
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-16
// Description: Defenition file for Station class, OO programming
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX

#include "Station.h"
#include "TrainCar.h"

#include "CarFreightClosed.h"
#include "CarFreightOpen.h"
#include "CarPersonSit.h"
#include "CarPersonSleep.h"
#include "LocoDiesel.h"
#include "LocoElect.h"

//---------------------------------------------------------------------------
Station::Station(std::string p_Station_Name)
    : station_Name(p_Station_Name), CarPool_Atstart(0) {}
//---------------------------------------------------------------------------
Station::~Station() {}
//---------------------------------------------------------------------------
// Name: addCarToStaionPool
// Desc: Add a new Train Carriage to the pool of Cars present at the station.
//---------------------------------------------------------------------------
void Station::addCarToStaionPool(int p_Id, int p_Type, int param0, int param1,
                        std::string const& his_Str) {
  CarPool_Atstart++;

  switch (p_Type) {
    case PERSON_SIT:
      station_Pool.insert(std::pair<int, std::shared_ptr<TrainCar>>(
          p_Id, new CarPersonSit(p_Id, p_Type, param0, param1, his_Str)));
      break;
    case PERSON_SLEEP:
      station_Pool.insert(trainCar_Pair(
          p_Id, new CarPersonSleep(p_Id, p_Type, param0, his_Str)));
      break;
    case FREIGHT_OPEN:
      station_Pool.insert(trainCar_Pair(
          p_Id, new CarFreightOpen(p_Id, p_Type, param0, param1, his_Str)));
      break;
    case FREIGHT_CLOSED:
      station_Pool.insert(trainCar_Pair(
          p_Id, new CarFreightClosed(p_Id, p_Type, param0, his_Str)));
      break;
    case LOCO_ELEC:
      station_Pool.insert(trainCar_Pair(
          p_Id, new LocoElect(p_Id, p_Type, param0, param1, his_Str)));
      break;
    case LOCO_DIESEL:
      station_Pool.insert(trainCar_Pair(
          p_Id, new LocoDiesel(p_Id, p_Type, param0, param1, his_Str)));
      break;
    default:
      break;
  }
}
//---------------------------------------------------------------------------
// Name: clearStation
// Desc: Clear train Cars present in the station.
//---------------------------------------------------------------------------
void Station::clearStation() {
  station_Name = "";
  station_Pool.clear();
}
//---------------------------------------------------------------------------
// Name: removeCarFromStation
// Desc: Called fron function "Tryasseble", Removes selected trainCar from the
// trainstation pool.
//---------------------------------------------------------------------------
void Station::removeCarFromStation(int c_Id) {
  station_Pool.erase(c_Id);
}
//---------------------------------------------------------------------------
// Name: addCartoStationFromTrain
// Desc: Called from function setFinished. It adds a traincar pair to the
// selected station.
//---------------------------------------------------------------------------
void Station::addCartoStationFromTrain(const trainCar_Pair& car) {
  station_Pool.insert(car);
}
//---------------------------------------------------------------------------
