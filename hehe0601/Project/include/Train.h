// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: Train.h
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-15
// Description: Header file for Train, OOO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
#ifndef Train_H
#define Train_H

#include <map>
#include <memory>
#include <string>
#include <vector>
#include "Constants.h"
#include "TrainCar.h"
#include "cfl.h"

//---------------------------------------------------------------------------
// Train Class - Trains consists of Train Carriages. Train objects have required
// train carriages they need to take ownership of from their departure station.
// They release their carriages when they reach the destination station.
//---------------------------------------------------------------------------

typedef std::pair<int, std::shared_ptr<TrainCar>> trainCar_Pair;
typedef std::map<int, std::shared_ptr<TrainCar>> TrainCar_Map;
typedef std::shared_ptr<TrainCar> TrainCar_Ptr;

class Train {
 public:
  Train();
  Train(int p_Train_Num, std::string dep_Stat, std::string arr_Stat,
        int p_time_dep, int p_time_arr, double p_Mean,
        std::vector<int> p_req_car);
  ~Train();

  //---------------------------------------------------------------------------
  // Getters:
  //---------------------------------------------------------------------------
  int getTrainNum() const { return train_Num; };
  std::string getDepStat() const { return departure_Station; }
  std::string getDesStat() const { return destination_Station; }
  std::string getStatetoStr() const;

  double getMeanSpeed() const { return mean_Speed; }
  int getDepTime() const { return time_Departure; }
  int getArrTime() const { return time_Arrival; }
  bool getLate() const { return is_Late; }

  TrainCar_Map const &GetTrainCar() { return train_Obj; }
  std::vector<int> const &getReqCarriages() { return req_Carriages; }
  std::vector<int> const &getMissingCars() { return missing_Carriages; }
   double getAvgSpeed() const { return avg_Speed; }
  TRAIN_STATE getStateEnum() const { return t_State; }
  //---------------------------------------------------------------------------
  // Setters:
  //---------------------------------------------------------------------------
  void setIsLate(bool p_Late) { is_Late = p_Late; }
  void setTrainState(TRAIN_STATE p_State) { t_State = p_State; }
  void setAvgSpeed(int const &p_Speed) { avg_Speed = p_Speed; }
  void addTrainCarstoTrain(const trainCar_Pair &car);
  void removeCarfromTrain(const int &c_Id);
  void addMissingCar(const int &missing_Car) {
    missing_Carriages.push_back(missing_Car);
  }
  //---------------------------------------------------------------------------
  // print
  //---------------------------------------------------------------------------
  void printTrainInfo(std::ostream &os = std::cout) const;
  std::string TrainCarTypeToStr(int car_Type);
  //---------------------------------------------------------------------------
 private:
  int train_Num;
  int time_Departure;
  int time_Arrival;
  int delay_time;
  bool is_Late;
  double mean_Speed;
  double avg_Speed;
  std::string departure_Station;
  std::string destination_Station;
  TRAIN_STATE t_State;

  // Container holding required train carriages:
  std::vector<int> req_Carriages;
  std::vector<int> missing_Carriages;
  TrainCar_Map train_Obj;
};
//---------------------------------------------------------------------------
std::ostream &operator<<(std::ostream &os, std::shared_ptr<Train> pTrain);

//---------------------------------------------------------------------------
#endif  // Train_H
