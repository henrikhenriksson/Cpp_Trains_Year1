// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: TrainSystem.cpp
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-21
// Description: Defenition file for TrainSystem class, OO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX

#include "TrainSystem.h"

//---------------------------------------------------------------------------
TrainSystem::TrainSystem(std::shared_ptr<Simulation> p_Sim)
    : the_Sim(p_Sim),
      start_Time(SIM_TIME_START),
      end_Time(SIM_TIME_END),
      logLevel(LOW_LOG) {}

TrainSystem::~TrainSystem() { train_Sim.close(); }

//---------------------------------------------------------------------------
// Name: openFiles
// Desc: Check if files can be opened, otherwise throw exeption.
//---------------------------------------------------------------------------
void TrainSystem::openFiles() {
  train_File.open(TRAINFILE);
  if (!train_File.is_open()) {
    throw std::runtime_error("Could not open TrainFile.");
  }
  station_File.open(STATFILE);
  if (!station_File.is_open()) {
    throw std::runtime_error("Could not open Station File.");
  }
  map_File.open(MAPFILE);
  if (!map_File.is_open()) {
    throw std::runtime_error("Could not open Map File.");
  }
  train_Sim.open(LOGFILE);
  if (!train_Sim.is_open()) {
    throw std::runtime_error("Could not open TrainFile.");
  }
}
//---------------------------------------------------------------------------
// Name: closeFiles
// Desc: Close open files.
//---------------------------------------------------------------------------
void TrainSystem::closeFiles() {
  train_File.close();
  station_File.close();
  map_File.close();
}
//---------------------------------------------------------------------------
// Name: readStatFromFile
// Desc: Read data from files.
//     create a std::stringstream reading line,
//     then read required data from that reading line,
//     starting with station name,
//     then assign std::strings with the contained values.
//     Assign these values to the carriages to be stabled at that
//     station.
//---------------------------------------------------------------------------
void TrainSystem::readFromFile() {
  std::string read_Line;
  while (getline(station_File, read_Line, NEWLINE)) {
    std::stringstream stationStream(read_Line);
    std::string tmp_Station_Name;

    getline(stationStream, tmp_Station_Name, DELIM);
    std::shared_ptr<Station> tmp_Station(new Station(tmp_Station_Name));

    while (stationStream) {
      std::string tmp_delim;
      getline(stationStream, tmp_delim, '(');
      std::string tmp_car;
      while (getline(stationStream, tmp_car, ')')) {
        std::stringstream carStream(tmp_car);
        std::string c_id, c_type, c_p0;
        std::string c_p1 = "-1";

        carStream >> c_id >> c_type >> c_p0 >> c_p1;
        std::string car_History = intTimetoStr(the_Sim->getTime()) +
                                  " Connected to train pool at " +
                                  tmp_Station_Name;

        tmp_Station->addCarToStaionPool(std::stoi(c_id), std::stoi(c_type),
                                        std::stoi(c_p0), std::stoi(c_p1),
                                        car_History);
        getline(stationStream, tmp_delim, '(');
      }
      train_Stations.emplace(tmp_Station_Name, tmp_Station);
    }
  }
  // reassign the read line to the trainfile data, read ints and std::strings,
  // assign to a new train object.
  while (getline(train_File, read_Line, NEWLINE)) {
    std::stringstream trainStream(read_Line);
    int tmp_Num, tmp_Speed, car1, car2, car3, car4, car5(-1);
    std::string dep_Stat, des_Stat, dep_Time, arr_Time;
    trainStream >> tmp_Num >> dep_Stat >> des_Stat >> dep_Time >> arr_Time >>
        tmp_Speed >> car1 >> car2 >> car3 >> car4 >> car5;
    if (car5 != -1) {  // if a value was read into the fifth carriage or not
      std::vector<int> tmp_req_Cars = {car1, car2, car3, car4, car5};
      train_Table.emplace(
          tmp_Num, train_Ptr(new Train(
                       tmp_Num, dep_Stat, des_Stat, timeStrtoMin(dep_Time),
                       timeStrtoMin(arr_Time), tmp_Speed, tmp_req_Cars)));
    } else {
      std::vector<int> tmp_req_Cars = {car1, car2, car3, car4};
      train_Table.emplace(
          tmp_Num, train_Ptr(new Train(
                       tmp_Num, dep_Stat, des_Stat, timeStrtoMin(dep_Time),
                       timeStrtoMin(arr_Time), tmp_Speed, tmp_req_Cars)));
    }
  }

  // Read in the map distances file.
  while (getline(map_File, read_Line, NEWLINE)) {
    std::stringstream mapStream(read_Line);
    std::string dep_Stat, des_Stat;
    int tmp_dist;
    mapStream >> dep_Stat >> des_Stat >> tmp_dist;
    train_Map.push_back(
        std::shared_ptr<TrainMap>(new TrainMap(dep_Stat, des_Stat, tmp_dist)));
  }
}
//---------------------------------------------------------------------------
// Name: tryAssemble
// Desc: Attempt to assemble a train, call functions to add carriages and remove
// the same carriages from the departure station train car map.
// Return: bool
//---------------------------------------------------------------------------
bool TrainSystem::tryAssemble(int train_Id) {
  // Find the train
  train_Ptr tmp_TrainPtr = getOneTrain(train_Id);
  // find the departure station:
  station_Ptr tmp_StationPtr = getOneStation(tmp_TrainPtr->getDepStat());

  // Iterate through the required cars of the parameter train, then search for
  // it in the departure station car pool. Create an iterator to that traincar
  // object.
  for (auto car_type : tmp_TrainPtr->getReqCarriages()) {
    auto TrainCar_It = std::find_if(
        tmp_StationPtr->GetStationPool().begin(),
        tmp_StationPtr->GetStationPool().end(), [&](trainCar_Pair pCar) {
          return pCar.second->getcType() == car_type;
        });

    // If a traincar was found, attach it to the train and remove it from the
    // station pool. Otherwise, add the car type to parameter trains missing
    // train cars.
    if (TrainCar_It != tmp_StationPtr->GetStationPool().end()) {
      std::string car_History = intTimetoStr(the_Sim->getTime()) +
                                " Disconnected from train pool at " +
                                tmp_StationPtr->getStationName() + " station";

      TrainCar_It->second->addCarHistory(car_History);

      tmp_TrainPtr->addTrainCarstoTrain(
          trainCar_Pair(TrainCar_It->first, TrainCar_It->second));
      car_History = intTimetoStr(the_Sim->getTime()) + " Connected to train " +
                    std::to_string(tmp_TrainPtr->getTrainNum());
      TrainCar_It->second->addCarHistory(car_History);

      tmp_StationPtr->removeCarFromStation(TrainCar_It->first);
    } else {
      tmp_TrainPtr->addMissingCar(car_type);
    }
  }

  // set the train object to assembled if all train cars has been attached.
  // Otherwise set it to incomplete. The train does not return ownership of any
  // attached cars back to station pool.
  if (tmp_TrainPtr->getMissingCars().empty()) {
    tmp_TrainPtr->setTrainState(ASSEMBLED);

    if (the_Sim->getTime() >= start_Time && the_Sim->getTime() <= end_Time) {
      printEvent(tmp_TrainPtr);
    }
    return true;

  } else {
    tmp_TrainPtr->setIsLate(true);
    tmp_TrainPtr->setTrainState(INCOMPLETE);

    if (the_Sim->getTime() >= start_Time && the_Sim->getTime() <= end_Time) {
      printEvent(tmp_TrainPtr);
    }

    return false;
  }
}
//---------------------------------------------------------------------------
// Name: setReady
// Desc: set trainstate to ready.
//---------------------------------------------------------------------------
void TrainSystem::setReady(int train_Id) {
  train_Ptr tmp_TrainPtr = getOneTrain(train_Id);

  tmp_TrainPtr->setTrainState(READY);
  if (the_Sim->getTime() >= start_Time && the_Sim->getTime() <= end_Time) {
    printEvent(tmp_TrainPtr);
  }
}
//---------------------------------------------------------------------------
// Name: setRunning
// Desc: Set train state to running, calculate average speed based on the
// distance between origin and destination
//---------------------------------------------------------------------------
void TrainSystem::setRunning(int train_Id) {
  train_Ptr tmp_TrainPtr = getOneTrain(train_Id);
  int travel_distance =
      getDistance(tmp_TrainPtr->getDepStat(), tmp_TrainPtr->getDesStat());
  int travel_Time = tmp_TrainPtr->getArrTime() - tmp_TrainPtr->getDepTime();

  int Average_Speed = (travel_distance * 60) / travel_Time;

  tmp_TrainPtr->setAvgSpeed(Average_Speed);
  tmp_TrainPtr->setTrainState(RUNNING);

  if (the_Sim->getTime() >= start_Time && the_Sim->getTime() <= end_Time) {
    printEvent(tmp_TrainPtr);
  }
}
//---------------------------------------------------------------------------
// Name: getDistance
// Desc: Calculate distance from dep station to des station.
//---------------------------------------------------------------------------
int TrainSystem::getDistance(std::string dep_Station,
                             std::string des_Station) const {
  for (auto &e : train_Map) {
    if (dep_Station == e->getDepStat() && des_Station == e->getDesStat()) {
      return e->getDistance();
    } else if (des_Station == e->getDepStat() &&
               dep_Station == e->getDesStat()) {
      return e->getDistance();
    }
  }
}
//---------------------------------------------------------------------------
// Name: setArrived
// Desc: set train to arrived state
//---------------------------------------------------------------------------
void TrainSystem::setArrived(int train_Id) {
  train_Ptr tmp_TrainPtr = getOneTrain(train_Id);

  tmp_TrainPtr->setTrainState(ARRIVED);
  if (the_Sim->getTime() >= start_Time && the_Sim->getTime() <= end_Time) {
    printEvent(tmp_TrainPtr);
  }
}
//---------------------------------------------------------------------------
// Name: setFinished
// Desc: Remove cars from the train and add them to destination station carpool
//---------------------------------------------------------------------------
void TrainSystem::setFinished(int train_Id) {
  train_Ptr tmp_TrainPtr = getOneTrain(train_Id);
  station_Ptr tmp_StationPtr = getOneStation(tmp_TrainPtr->getDesStat());

  // loop through the train car map, add history to each train car, remove it
  // from the train object and add it to the destination station
  while (!(tmp_TrainPtr->GetTrainCar().empty())) {
    TrainCar_Ptr car_ptr = tmp_TrainPtr->GetTrainCar().begin()->second;
    std::string car_History = intTimetoStr(the_Sim->getTime()) +
                              " Disconnected from train " +
                              std::to_string(tmp_TrainPtr->getTrainNum());

    tmp_StationPtr->addCartoStationFromTrain(
        trainCar_Pair(car_ptr->getcID(), car_ptr));
    car_ptr->addCarHistory(car_History);
    car_History = intTimetoStr(the_Sim->getTime()) +
                  " Stabled in train pool at " +
                  tmp_StationPtr->getStationName() + " station";
    car_ptr->addCarHistory(car_History);
    tmp_TrainPtr->removeCarfromTrain(
        tmp_TrainPtr->GetTrainCar().begin()->first);
  }
  tmp_TrainPtr->setTrainState(FINISHED);

  // Add 25 minutes extra to allow trains dissassembled after 24:00 to print:
  if (the_Sim->getTime() >= start_Time && the_Sim->getTime() <= (end_Time + 25)) {
    printEvent(tmp_TrainPtr);
  }
}
//---------------------------------------------------------------------------
// Name: printEvent
// Desc: switch on parameter trainPtr state, print relevant information to
// console and file.
//---------------------------------------------------------------------------
void TrainSystem::printEvent(const train_Ptr &tmp_TrainPtr) {
  switch (logLevel) {
    case LOW_LOG:
      switch (tmp_TrainPtr->getStateEnum()) {
        case INCOMPLETE:
          std::cout << cfl::intTimetoStr(the_Sim->getTime()) << tmp_TrainPtr
                    << ", is incomplete and will not leave the station. "
                    << std::endl
                    << std::endl;
          train_Sim << cfl::intTimetoStr(the_Sim->getTime()) << tmp_TrainPtr
                    << ", is incomplete and will not leave the station. "
                    << std::endl
                    << std::endl;
          break;
        case ASSEMBLED:
          std::cout << cfl::intTimetoStr(the_Sim->getTime()) << tmp_TrainPtr
                    << ", is now Assembled," << std::endl
                    << " Arriving at the platform at: "
                    << cfl::intTimetoStr(the_Sim->getTime() + SCHED_READY)
                    << std::endl
                    << std::endl;
          train_Sim << cfl::intTimetoStr(the_Sim->getTime()) << tmp_TrainPtr
                    << ", is now Assembled," << std::endl
                    << "Arriving at the platform at: "
                    << cfl::intTimetoStr(the_Sim->getTime() + SCHED_READY)
                    << std::endl
                    << std::endl;
          break;
        case READY:
          std::cout << cfl::intTimetoStr(the_Sim->getTime()) << tmp_TrainPtr
                    << ", is now at the platform," << std::endl
                    << "departing at "
                    << cfl::intTimetoStr(the_Sim->getTime() + SCHED_RUNNING)
                    << std::endl
                    << std::endl;
          train_Sim << cfl::intTimetoStr(the_Sim->getTime()) << tmp_TrainPtr
                    << ", is now at the platform," << std::endl
                    << "departing at "
                    << cfl::intTimetoStr(the_Sim->getTime() + SCHED_RUNNING)
                    << std::endl
                    << std::endl;
          break;
        case RUNNING:
          std::cout << cfl::intTimetoStr(the_Sim->getTime()) << tmp_TrainPtr
                    << ", has left the platform, " << std::endl
                    << " traveling at speed: " << tmp_TrainPtr->getAvgSpeed()
                    << " km/h" << std::endl
                    << std::endl;
          train_Sim << cfl::intTimetoStr(the_Sim->getTime()) << tmp_TrainPtr
                    << ", has left the platform, " << std::endl
                    << " traveling at speed: " << tmp_TrainPtr->getAvgSpeed()
                    << " km/h" << std::endl
                    << std::endl;
          break;
        case ARRIVED:
          std::cout << cfl::intTimetoStr(the_Sim->getTime()) << tmp_TrainPtr
                    << ", has Arrived on the platform, " << std::endl
                    << "disassembly at "
                    << cfl::intTimetoStr(the_Sim->getTime() + SCHED_DISASSEMBLE)
                    << std::endl
                    << std::endl;
          train_Sim << cfl::intTimetoStr(the_Sim->getTime()) << tmp_TrainPtr
                    << ", has Arrived on the platform, " << std::endl
                    << "disassembly at "
                    << cfl::intTimetoStr(the_Sim->getTime() + SCHED_DISASSEMBLE)
                    << std::endl
                    << std::endl;
          break;
        case FINISHED:
          std::cout << cfl::intTimetoStr(the_Sim->getTime()) << tmp_TrainPtr
                    << ", is now disassembled." << std::endl
                    << std::endl;
          train_Sim << cfl::intTimetoStr(the_Sim->getTime()) << tmp_TrainPtr
                    << ", is now disassembled." << std::endl
                    << std::endl;
          break;
        default:
          break;
      }
      break;
    case HIGH_LOG:
      switch (tmp_TrainPtr->getStateEnum()) {
        case INCOMPLETE:
          std::cout << cfl::intTimetoStr(the_Sim->getTime()) << tmp_TrainPtr
                    << ", is incomplete and will not leave the station. "
                    << std::endl
                    << std::endl;

          train_Sim << cfl::intTimetoStr(the_Sim->getTime()) << tmp_TrainPtr
                    << ", is incomplete and will not leave the station. "
                    << std::endl
                    << std::endl;
          printTrainDetail(tmp_TrainPtr);
          break;
        case ASSEMBLED:
          std::cout << cfl::intTimetoStr(the_Sim->getTime()) << tmp_TrainPtr
                    << ", is now Assembled," << std::endl
                    << " Arriving at the platform at: "
                    << cfl::intTimetoStr(the_Sim->getTime() + SCHED_READY)
                    << std::endl
                    << std::endl;
          train_Sim << cfl::intTimetoStr(the_Sim->getTime()) << tmp_TrainPtr
                    << ", is now Assembled," << std::endl
                    << "Arriving at the platform at: "
                    << cfl::intTimetoStr(the_Sim->getTime() + SCHED_READY)
                    << std::endl
                    << std::endl;
          printTrainDetail(tmp_TrainPtr);
          break;
        case READY:
          std::cout << cfl::intTimetoStr(the_Sim->getTime()) << tmp_TrainPtr
                    << ", is now at the platform," << std::endl
                    << "departing at "
                    << cfl::intTimetoStr(the_Sim->getTime() + SCHED_RUNNING)
                    << std::endl
                    << std::endl;
          train_Sim << cfl::intTimetoStr(the_Sim->getTime()) << tmp_TrainPtr
                    << ", is now at the platform," << std::endl
                    << "departing at "
                    << cfl::intTimetoStr(the_Sim->getTime() + SCHED_RUNNING)
                    << std::endl
                    << std::endl;
          printTrainDetail(tmp_TrainPtr);
          break;
        case RUNNING:
          std::cout << cfl::intTimetoStr(the_Sim->getTime()) << tmp_TrainPtr
                    << ", has left the platform, " << std::endl
                    << " traveling at speed: " << tmp_TrainPtr->getAvgSpeed()
                    << " km/h" << std::endl
                    << std::endl;
          train_Sim << cfl::intTimetoStr(the_Sim->getTime()) << tmp_TrainPtr
                    << ", has left the platform, " << std::endl
                    << " traveling at speed: " << tmp_TrainPtr->getAvgSpeed()
                    << " km/h" << std::endl
                    << std::endl;
          printTrainDetail(tmp_TrainPtr);
          break;
        case ARRIVED:
          std::cout << cfl::intTimetoStr(the_Sim->getTime()) << tmp_TrainPtr
                    << ", has Arrived on the platform, " << std::endl
                    << "disassembly at "
                    << cfl::intTimetoStr(the_Sim->getTime() + SCHED_DISASSEMBLE)
                    << std::endl
                    << std::endl;
          train_Sim << cfl::intTimetoStr(the_Sim->getTime()) << tmp_TrainPtr
                    << ", has Arrived on the platform, " << std::endl
                    << "disassembly at "
                    << cfl::intTimetoStr(the_Sim->getTime() + SCHED_DISASSEMBLE)
                    << std::endl
                    << std::endl;
          printTrainDetail(tmp_TrainPtr);
          break;
        case FINISHED:
          std::cout << cfl::intTimetoStr(the_Sim->getTime()) << tmp_TrainPtr
                    << ", is now disassembled." << std::endl
                    << std::endl;
          train_Sim << cfl::intTimetoStr(the_Sim->getTime()) << tmp_TrainPtr
                    << ", is now disassembled." << std::endl
                    << std::endl;
          printTrainDetail(tmp_TrainPtr);
          break;
        default:
          break;
      }

      break;
    default:
      break;
  }
}
//---------------------------------------------------------------------------
// Name: printTrainDetail
// Desc: Get more detailed information about cars present in a train object.
// Print to console and file.
//---------------------------------------------------------------------------
void TrainSystem::printTrainDetail(const train_Ptr &tmp_TrainPtr) {
  if (!(tmp_TrainPtr->GetTrainCar().empty())) {
    std::cout << "Attached Train Carriages: " << std::endl;
    for (auto car_It : tmp_TrainPtr->GetTrainCar()) {
      std::cout << car_It.second << std::endl;
      train_Sim << car_It.second << std::endl;
    }
  } else {
    std::cout << "No Attached Train Carriages." << std::endl << std::endl;
    train_Sim << "No Attached Train Carriages." << std::endl << std::endl;
  }

  if (!(tmp_TrainPtr->getMissingCars().empty())) {
    std::cout << std::endl << "Missing Train Carriages: " << std::endl;
    for (auto car_Type : tmp_TrainPtr->getMissingCars()) {
      std::cout << tmp_TrainPtr->TrainCarTypeToStr(car_Type) << std::endl
                << std::endl;
      train_Sim << tmp_TrainPtr->TrainCarTypeToStr(car_Type) << std::endl
                << std::endl;
    }
  }
}
//---------------------------------------------------------------------------
// Name: getOneTrain
// Desc: Find a specific train based on trainID, return pointer to that train.
// Return: train_Ptr
//---------------------------------------------------------------------------
train_Ptr TrainSystem::getOneTrain(int train_id) {
  trainPtr_Map::iterator train_It;

  train_It = train_Table.find(train_id);
  if (train_It != train_Table.end()) {
    return train_It->second;
  } else {
    return nullptr;
  }
}
//---------------------------------------------------------------------------
// Name: getStations
// Desc: Find a specific station based on station name, return pointer to that
// train.
// Return: Station_Ptr
//---------------------------------------------------------------------------
station_Ptr TrainSystem::getOneStation(std::string &station_Name) {
  station_Map::iterator station_It;
  station_It = train_Stations.find(station_Name);
  if (station_It != train_Stations.end()) {
    return station_It->second;
  } else
    return nullptr;
}
//---------------------------------------------------------------------------
// Name: clearTrainSystemData
// Desc: clear data currently in the containers for a fresh run.
//---------------------------------------------------------------------------
void TrainSystem::clearTrainSystemData() {
  train_Stations.clear();
  train_Table.clear();
  train_Map.clear();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// Name: setStarTime
// Desc: set a new starttime for the simulation:
//---------------------------------------------------------------------------
void TrainSystem::setStarTime(int p_Time) { start_Time = p_Time; }
//---------------------------------------------------------------------------
// Name: setEndTime
// Desc: Set a new End time for the simulation
//---------------------------------------------------------------------------
void TrainSystem::setEndTime(int p_Time) { end_Time = p_Time; }
//---------------------------------------------------------------------------
