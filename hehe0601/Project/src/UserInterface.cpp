// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: UserInterface.cpp
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-13
// Description: Defenition file for UserInterface, OOO programming C
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX

#include "UserInterface.h"
#include "Constants.h"
#include "Station.h"
#include "Train.h"
#include "cfl.h"

//---------------------------------------------------------------------------
// Name: Constructor
// Desc: Used to initialize member variables.
//---------------------------------------------------------------------------
UserInterface::UserInterface()
    : trainSystem_Ptr(new TrainSystem(running_Sim)),
      running_Sim(new Simulation()),
      start_Menu(new Menu()),
      train_Menu(new Menu()),
      station_Menu(new Menu()),
      simulation_Menu(new Menu()),
      trainCar_Menu(new Menu()),
      statistics_Menu(new Menu()),
      logLevel_Menu(new Menu()),
      run_Program(true),
      run_Sim(true),
      run_Sub(true),
      sim_Done(false) {
  buildMenuSystem();
}
//---------------------------------------------------------------------------
// Desc: Default destructor
//---------------------------------------------------------------------------
UserInterface::~UserInterface() {}
//---------------------------------------------------------------------------
// Name: run()
// Desc: open files, read data from files and run the starmenu..
//---------------------------------------------------------------------------
void UserInterface::run() {
  do {
    try {
      trainSystem_Ptr->openFiles();
      trainSystem_Ptr->readFromFile();
      trainSystem_Ptr->closeFiles();
      clearScreen();
      asciiTrain();
      runStartMenu();
    } catch (const std::runtime_error& e) {
      std::cout << e.what() << std::endl;
    }
  } while (run_Program);
}
//---------------------------------------------------------------------------
// Name: runStartMenu
// Desc: print startmenu, run switch case for start menu functions
//---------------------------------------------------------------------------
void UserInterface::runStartMenu() {
  run_Program = true;
  sim_Done = false;
  while (run_Program) {
    clearScreen();
    std::cout << "-------------------- " << std::endl
              << start_Menu->getMenuTitle() << std::endl
              << "--------------------" << std::endl
              << std::endl;

    start_Menu->printMenuItems();
    switch (start_Menu->getMenuChoice()) {
      case 1:
        newStartTime();
        break;
      case 2:
        newEndTime();
        break;
      case 3:
        runSimulationMenu();
        break;
      case 0:
        run_Program = false;
        break;
      default:
        std::cout << "Invalid Selection!" << std::endl;
        break;
    }
  }
}
//---------------------------------------------------------------------------
// Name: runTrainMenu
// Desc: print the train menu and run user selected functions.
//---------------------------------------------------------------------------
void UserInterface::runTrainMenu() {
  run_Sub = true;
  while (run_Sub) {
    clearScreen();
    std::cout << "--------------------" << std::endl
              << train_Menu->getMenuTitle() << "current time : ["
              << cfl::intTimetoStr(running_Sim->getTime()) << "]" << std::endl
              << "--------------------" << std::endl
              << std::endl;

    train_Menu->printMenuItems();
    switch (train_Menu->getMenuChoice()) {
      case 1:
        showTrainByTrainID();
        break;
      case 2:
        showTrainByTrainCarID();
        break;
      case 3:
        showAllTrains();
        break;
      case 4:
        runLogLevelMenu();
        break;
      case 0:
        run_Sub = false;
        break;
      default:
        std::cout << "Invalid Selection!" << std::endl;
        break;
    }
  }
}
//---------------------------------------------------------------------------
// Name: runStationMenu
// Desc: print station menu and run selected option.
//---------------------------------------------------------------------------
void UserInterface::runStationMenu() {
  run_Sub = true;
  while (run_Sub) {
    clearScreen();
    std::cout << "--------------------" << std::endl
              << station_Menu->getMenuTitle() << "current time : ["
              << cfl::intTimetoStr(running_Sim->getTime()) << "]" << std::endl
              << "--------------------" << std::endl
              << std::endl;

    station_Menu->printMenuItems();
    switch (station_Menu->getMenuChoice()) {
      case 1:
        showStationNames();
        break;
      case 2:
        showStationByName();
        break;
      case 3:
        showAllStations();
        break;
      case 4:
        runLogLevelMenu();
        break;
      case 0:
        run_Sub = false;
        break;
      default:
        std::cout << "Invalid Selection!" << std::endl;
        break;
    }
  }
}
//---------------------------------------------------------------------------
// Name: runSimulationMenu
// Desc: print simulationmenu and selected option:
//---------------------------------------------------------------------------
void UserInterface::runSimulationMenu() {
  run_Sim = true;
  schedEvents();
  while (run_Sim) {
    clearScreen();
    std::cout << "--------------------" << std::endl
              << simulation_Menu->getMenuTitle() << "current time : ["
              << cfl::intTimetoStr(running_Sim->getTime()) << "]" << std::endl
              << "--------------------" << std::endl
              << std::endl;

    simulation_Menu->printMenuItems();
    switch (simulation_Menu->getMenuChoice()) {
      case 1:
        changeInterval();
        break;
      case 2:
        runNextInterval();
        break;
      case 3:
        runNextEvent();
        break;
      case 4:
        finishSimulation();
        runStatisticsMenu();
        break;
      case 5:
        runLogLevelMenu();
        break;
      case 6:
        runTrainMenu();
        break;
      case 7:
        runStationMenu();
        break;
      case 8:
        runTrainCarMenu();
        break;
      case 0:
        run_Sim = false;
        trainSystem_Ptr->clearTrainSystemData();
        running_Sim->ClearSimulation();
        break;
      default:
        std::cout << "Invalid Selection!" << std::endl;
        break;
    }
  }
}
//---------------------------------------------------------------------------
// Name: runTrainCarMenu
// Desc: print traincarmenu and selected option
//---------------------------------------------------------------------------
void UserInterface::runTrainCarMenu() {
  run_Sub = true;
  while (run_Sub) {
    clearScreen();
    std::cout << "--------------------" << std::endl
              << trainCar_Menu->getMenuTitle() << "current time : ["
              << cfl::intTimetoStr(running_Sim->getTime()) << "]" << std::endl
              << "--------------------" << std::endl
              << std::endl;

    trainCar_Menu->printMenuItems();
    switch (trainCar_Menu->getMenuChoice()) {
      case 1:
        showTrainCarByID();
        break;
      case 2:
        showAllTrainCars();
        break;
      case 3:
        runLogLevelMenu();
        break;
      case 0:
        run_Sub = false;
        break;
      default:
        std::cout << "Invalid Selection!" << std::endl;
        break;
    }
  }
}
//---------------------------------------------------------------------------
// Name: runStatisticsMenu
// Desc: print statistics menu to console.
//---------------------------------------------------------------------------
void UserInterface::runStatisticsMenu() {
  run_Sim = false;
  sim_Done = true;
  while (sim_Done) {
    clearScreen();
    std::cout << "--------------------" << std::endl
              << statistics_Menu->getMenuTitle() << "current time : ["
              << cfl::intTimetoStr(running_Sim->getTime()) << "]" << std::endl
              << "--------------------" << std::endl
              << std::endl;

    statistics_Menu->printMenuItems();
    switch (statistics_Menu->getMenuChoice()) {
      case 1:
        runLogLevelMenu();
        break;
      case 2:
        printStatistics();
        break;
      case 3:
        runTrainMenu();
        break;
      case 4:
        runStationMenu();
        break;
      case 5:
        runTrainCarMenu();
        break;
      case 0:
        sim_Done = false;
        trainSystem_Ptr->clearTrainSystemData();
        running_Sim->ClearSimulation();
        break;
      default:
        std::cout << "Invalid Selection!" << std::endl;
        break;
    }
  }
}
//---------------------------------------------------------------------------
// Name: runLogLevelMenu
// Desc: Print the log menu, also used to set log level based on user input.
//---------------------------------------------------------------------------
void UserInterface::runLogLevelMenu() {
  run_Sub = true;
  while (run_Sub) {
    clearScreen();
    std::cout << "--------------------" << std::endl
              << logLevel_Menu->getMenuTitle() << "current time : ["
              << cfl::intTimetoStr(running_Sim->getTime()) << "]" << std::endl
              << "--------------------" << std::endl
              << std::endl
              << std::endl
              << "Current Log Level is: " << std::endl;

    logLevel_Menu->printMenuItems();
    switch (logLevel_Menu->getMenuChoice()) {
      case 1:
        setLogToLow();
        break;
      case 2:
        setLogToHigh();
        break;
      case 0:
        run_Sub = false;
        break;
      default:
        std::cout << "Invalid Selection!" << std::endl;
        break;
    }
  }
}
//---------------------------------------------------------------------------
// Name: setLogToLow
// Desc: Set loglevel to low
//---------------------------------------------------------------------------
void UserInterface::setLogToLow() {
  std::cout << "Log Level has ben set to Low" << std::endl;
  trainSystem_Ptr->setLogLvl(LOW_LOG);
  buildMenuSystem();
  waitForKey();
}
//---------------------------------------------------------------------------
// Name: setLogToHigh
// Desc: set loglevel to high.
//---------------------------------------------------------------------------
void UserInterface::setLogToHigh() {
  std::cout << "Log Level has ben set to High" << std::endl;
  trainSystem_Ptr->setLogLvl(HIGH_LOG);
  buildMenuSystem();
  waitForKey();
}
//---------------------------------------------------------------------------
// Name: getLoglvl
// Desc: Returns current log level as a std::string.
// Return: std::string
//---------------------------------------------------------------------------
std::string UserInterface::getLoglvl() {
  switch (trainSystem_Ptr->getLogLvl()) {
    case LOW_LOG:
      return "Low";
      break;
    case HIGH_LOG:
      return "High";
      break;
  }
}
//---------------------------------------------------------------------------
// Name: showTrainByTrainID
// Desc: Search any train by its unique train Number.
//---------------------------------------------------------------------------
void UserInterface::showTrainByTrainID() {
  std::cout << std::endl
            << "Find a train By its Unique id number:" << std::endl;
  int tmp_ID = getInputInt("Enter an ID number to search for: ");

  if (train_Ptr tmp_t = trainSystem_Ptr->getOneTrain(tmp_ID)) {
    printOneTrain(tmp_t);
    std::cout << std::endl;

  } else {
    std::cout << "No Train with that ID was found..." << std::endl;
  }

  waitForKey();
}
//---------------------------------------------------------------------------
// Name: showAllTrains
// Desc: Print information about a certain train object.
//---------------------------------------------------------------------------
void UserInterface::showAllTrains() {
  std::for_each(trainSystem_Ptr->getTrainLine().begin(),
                trainSystem_Ptr->getTrainLine().end(),
                [&](const train_Pair& tmp_t) {
                  printOneTrain(tmp_t.second);
                  std::cout << std::endl;
                });

  waitForKey();
}
//---------------------------------------------------------------------------
// Name: printOneTrain
// Desc: Print Train Information based on current log level.
//---------------------------------------------------------------------------
void UserInterface::printOneTrain(const train_Ptr& tmp) {
  switch (trainSystem_Ptr->getLogLvl()) {
    case LOW_LOG:
      std::cout << "--------------------------------------------------------"
                << std::endl
                << tmp << std::endl
                << "--------------------------------------------------------"
                << std::endl;
      break;
    case HIGH_LOG:
      std::cout << "--------------------------------------------------------"
                << std::endl
                << tmp << std::endl
                << std::endl;

      if (!(tmp->GetTrainCar().empty())) {
        std::cout << "Attached Train Carriages: " << std::endl;
        for (auto car_It : tmp->GetTrainCar()) {
          std::cout << car_It.second << std::endl;
        }
      } else {
        std::cout << "No Attached Train Carriages." << std::endl;
      }

      if (!(tmp->getMissingCars().empty())) {
        std::cout << std::endl << "Missing Train Carriages: " << std::endl;
        for (auto car_Type : tmp->getMissingCars()) {
          printMissingCars(car_Type);
        }
        std::cout << std::endl
                  << "--------------------------------------------------------"
                  << std::endl;
      }
      break;
    default:
      break;
  }
}
//---------------------------------------------------------------------------
// Name: printMissingTrains
// Desc: Switch case printing the type of the missing carriage:
//---------------------------------------------------------------------------
void UserInterface::printMissingCars(int car_Type) {
  switch (car_Type) {
    case PERSON_SIT:
      std::cout << "[Coach Carriage]";
      break;
    case PERSON_SLEEP:
      std::cout << "[Sleeping Carriage]";
      break;
    case FREIGHT_OPEN:
      std::cout << "[Open Freight Carriage]";
      break;
    case FREIGHT_CLOSED:
      std::cout << "[Closed Freight Carriage]";
      break;
    case LOCO_ELEC:
      std::cout << "[Electric Locomotive]";
      break;
    case LOCO_DIESEL:
      std::cout << "[Diesel Locomotive]";
      break;
  }
}
//---------------------------------------------------------------------------
// Name: showTrainByTrainCarID
// Desc: Show a particular train in transit based on a train Car id.
//---------------------------------------------------------------------------
void UserInterface::showTrainByTrainCarID() {
  int search_Car = getInputInt("Enter a Train Carriage ID to search for: ");
  bool found = false;

  for (train_Pair train_It : trainSystem_Ptr->getTrainLine()) {
    for (trainCar_Pair trainCar_It : train_It.second->GetTrainCar()) {
      if (trainCar_It.first == search_Car) {
        printOneTrain(train_It.second);
        found = true;
      }
    }
  }
  if (!found) {
    std::cout << "No train was found with that train car attached."
              << std::endl;
  }

  waitForKey();
}
//---------------------------------------------------------------------------
// Name: showStationNames
// Desc: Show all station names.
//---------------------------------------------------------------------------
void UserInterface::showStationNames() {
  std::for_each(trainSystem_Ptr->getStationSystem().begin(),
                trainSystem_Ptr->getStationSystem().end(),
                [&](const station_Pair& s) {
                  std::cout << s.second->getStationName() << std::endl;
                });

  waitForKey();
}
//---------------------------------------------------------------------------
// Name: showStationByName
// Desc: Show current train carriages present at a selected station.
// TODO: Add case insensitive search?
//---------------------------------------------------------------------------
void UserInterface::showStationByName() {
  std::string tmp_Name = getInputStr("Enter a station name to show: ");

  if (station_Ptr tmp_StationPtr = trainSystem_Ptr->getOneStation(tmp_Name)) {
    printOneStation(tmp_StationPtr);
    std::cout << std::endl;

  } else {
    std::cout << "No station with that name was found(check spelling)"
              << std::endl;
  }

  waitForKey();
}
//---------------------------------------------------------------------------
// Name: showAllStations
// Desc: Print all stations:
//---------------------------------------------------------------------------
void UserInterface::showAllStations() {
  std::for_each(trainSystem_Ptr->getStationSystem().begin(),
                trainSystem_Ptr->getStationSystem().end(),
                [&](const station_Pair& tmp_StationPtr) {
                  printOneStation(tmp_StationPtr.second);
                  std::cout << std::endl;
                });

  waitForKey();
}
//---------------------------------------------------------------------------
// Name: printOneStation
// Desc: Print relevant information about a station.
//---------------------------------------------------------------------------
void UserInterface::printOneStation(const station_Ptr& tmp_StationPtr) {
  switch (trainSystem_Ptr->getLogLvl()) {
    case LOW_LOG:
      std::cout << "------------------------" << std::endl
                << "Station:" << tmp_StationPtr->getStationName() << std::endl
                << "------------------------" << std::endl
                << "Total TrainCars Present: "
                << tmp_StationPtr->getTrainPoolSize() << std::endl
                << "------------------------" << std::endl;
      break;
    case HIGH_LOG:
      std::cout << "------------------------" << std::endl
                << "Station:" << tmp_StationPtr->getStationName() << std::endl
                << "------------------------" << std::endl
                << "TrainCars present: " << std::endl
                << "------------------------" << std::endl;
      for_each(tmp_StationPtr->GetStationPool().begin(),
               tmp_StationPtr->GetStationPool().end(),
               [&](const trainCar_Pair& tmp_tc) {
                 printTrainCar(tmp_tc.second);
                 std::cout << std::endl;
               });
      break;
    default:
      break;
  }
}
//---------------------------------------------------------------------------
// Name: showTrainCarByID
// Desc: Print information about user selected train Carriage
//---------------------------------------------------------------------------
void UserInterface::showTrainCarByID() {
  int search_Car = getInputInt("Enter a Train Carriage ID to search for: ");

  bool found_InTrain = false;

  // First iterate through the cars currently attached to trains:
  for (train_Pair train_It : trainSystem_Ptr->getTrainLine()) {
    for (trainCar_Pair TrainCar_It : train_It.second->GetTrainCar()) {
      if (TrainCar_It.first == search_Car) {
        printTrainCar(TrainCar_It.second);
        found_InTrain = true;
      }
    }
  }
  // If the car was not found on any train, iterate through the stations:
  if (!found_InTrain) {
    for (station_Pair station_It : trainSystem_Ptr->getStationSystem()) {
      for (trainCar_Pair TrainCar_It : station_It.second->GetStationPool()) {
        if (TrainCar_It.first == search_Car) {
          printTrainCar(TrainCar_It.second);
        }
      }
    }
  } else {
    std::cout << "No train Carriage was found with that id." << std::endl;
  }
  waitForKey();
}
//---------------------------------------------------------------------------
// Name: showAllTrainCars
// Desc: Show all trainCars present in the train & station system.
//---------------------------------------------------------------------------
void UserInterface::showAllTrainCars() {
  for (auto& e : trainSystem_Ptr->getTrainLine()) {
    std::for_each(e.second->GetTrainCar().begin(),
                  e.second->GetTrainCar().end(),
                  [&](const trainCar_Pair& car) { printTrainCar(car.second); });
  }

  for (auto& e : trainSystem_Ptr->getStationSystem()) {
    std::for_each(e.second->GetStationPool().begin(),
                  e.second->GetStationPool().end(),
                  [&](const trainCar_Pair& car) { printTrainCar(car.second); });
  }
  waitForKey();
}
//---------------------------------------------------------------------------
// Name: printTrainCar
// Desc: Print information about a trainCar
//---------------------------------------------------------------------------
void UserInterface::printTrainCar(const TrainCar_Ptr& car) {
  switch (trainSystem_Ptr->getLogLvl()) {
    case LOW_LOG:
      std::cout << car << std::endl;
      break;
    case HIGH_LOG:
      std::cout << car << std::endl;
      for (auto e : car->getCarHistory()) {
        std::cout << e << std::endl;
      }
      break;
    default:
      break;
  }
}
//---------------------------------------------------------------------------
// Name: printStatistics
// Desc: Print statistics about the simulation.
//---------------------------------------------------------------------------
void UserInterface::printStatistics() {
  std::cout << "-----------------------" << std::endl
            << "Simulation Statistics" << std::endl
            << "-----------------------" << std::endl
            << std::endl;

  std::cout << "--------------------------------------------------------"
            << std::endl
            << "Number of Train Carriages at the start of the simulation"
            << std::endl
            << "--------------------------------------------------------"
            << std::endl;
  std::for_each(trainSystem_Ptr->getStationSystem().begin(),
                trainSystem_Ptr->getStationSystem().end(),
                [](const station_Pair& tmp_StationPtr) {
                  std::cout << tmp_StationPtr.first << " = "
                            << tmp_StationPtr.second->getCarPoolAtStart()
                            << std::endl;
                });
  std::cout << "--------------------------------------------------------"
            << std::endl
            << "Number of Trains That never left the Station:" << std::endl
            << "--------------------------------------------------------"
            << std::endl;
  int never_Left = std::count_if(
      trainSystem_Ptr->getTrainLine().begin(),
      trainSystem_Ptr->getTrainLine().end(), [&](const train_Pair& tmp_t) {
        return tmp_t.second->getStateEnum() == INCOMPLETE;
      });

  std::cout << "--------------------------------------------------------"
            << std::endl
            << "Total: " << never_Left << std::endl
            << "--------------------------------------------------------"
            << std::endl;

  std::for_each(trainSystem_Ptr->getTrainLine().begin(),
                trainSystem_Ptr->getTrainLine().end(),
                [&](const train_Pair& tmp_t) {
                  if (tmp_t.second->getStateEnum() == INCOMPLETE) {
                    printOneTrain(tmp_t.second);
                    std::cout << std::endl;
                  }
                });

  waitForKey();
}
//---------------------------------------------------------------------------
// Name: schedEvents
// Desc: Schedule initial events to the simulator.
//---------------------------------------------------------------------------
void UserInterface::schedEvents() {
  for (auto e : trainSystem_Ptr->getTrainLine()) {
    running_Sim->schedEvent(std::shared_ptr<Event>(
        new AssembleEvent(running_Sim, trainSystem_Ptr,
                          (e.second->getDepTime() - SCHED_BUILD), e.first)));
  }
}
//---------------------------------------------------------------------------
// Name: changeInterval
// Desc: change the interval
//---------------------------------------------------------------------------
void UserInterface::changeInterval() {
  int new_Interval = cfl::getInputInt("Set a new time interval [minutes]: ");

  if (new_Interval >= 10) {
    running_Sim->setInterval(new_Interval);
    std::cout << "New interval has been set. " << std::endl;
    buildMenuSystem();
  } else {
    std::cout << "Cannot set time interval shorter than 10 minutes."
              << std::endl;
  }
  waitForKey();
}
//---------------------------------------------------------------------------
// Name: runNextInterval
// Desc: Run any events in the set interval period:
//---------------------------------------------------------------------------
void UserInterface::runNextInterval() {
  std::cout << "Running next Interval:" << std::endl << std::endl;
  running_Sim->runNextInterval();

  waitForKey();
}
//---------------------------------------------------------------------------
// Name: runNextEvent
// Desc: Run only the next schedueled event:
//---------------------------------------------------------------------------
void UserInterface::runNextEvent() {
  std::cout << "Running next Event:" << std::endl << std::endl;
  running_Sim->runNextEvent();
  waitForKey();
}
//---------------------------------------------------------------------------
// Name: finishSimulation
// Desc: run all schedueled events:
//---------------------------------------------------------------------------
void UserInterface::finishSimulation() {
  running_Sim->runSim();
  waitForKey();
}
//---------------------------------------------------------------------------
// Name: newStartTime
// Desc: Change start time of the simulation and rebuild the menusystem.
//---------------------------------------------------------------------------
void UserInterface::newStartTime() {
  int tmp_Time = cfl::getInputTime(
      "Enter a new Start time for the simulation: [eg. 12:00] ");
  trainSystem_Ptr->setStarTime(tmp_Time);
  buildMenuSystem();
}
//---------------------------------------------------------------------------
// Name: newEndTime
// Desc: Change end time of the simulation and rebuild the menusystem.
//---------------------------------------------------------------------------
void UserInterface::newEndTime() {
  int tmp_Time = cfl::getInputTime(
      "Enter a new Start time for the simulation: [eg. 12:00] ");

  trainSystem_Ptr->setEndTime(tmp_Time);
  buildMenuSystem();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// Name: buildMenuSystem
// Desc: add menuitems to each menu. Initially called from constructor.
//---------------------------------------------------------------------------
void UserInterface::buildMenuSystem() {
  clearAllMenues();

  // Assign new/updated strings
  std::string startTimeString =
      " [" + cfl::intTimetoStr(trainSystem_Ptr->getStarTime()) + "]";
  std::string endTimeString =
      " [" + cfl::intTimetoStr(trainSystem_Ptr->getEndTime()) + "]";

  std::string loglvlString = " [" + getLoglvl() + "]";

  std::string intervalString =
      "[" + std::to_string(running_Sim->getInterval()) + "]";

  start_Menu->setMenuTitle(" START MENU ");
  train_Menu->setMenuTitle(" TRAIN MENU :");
  station_Menu->setMenuTitle(" STATION MENU :");
  simulation_Menu->setMenuTitle(" SIMULATION MENU :");
  trainCar_Menu->setMenuTitle(" TRAIN CARRIAGE MENU : ");
  statistics_Menu->setMenuTitle(" STATISTICS MENU : ");
  logLevel_Menu->setMenuTitle(" CHANGE LOG LEVEL : ");

  start_Menu->addItem(" 1. Change start time:", startTimeString);
  start_Menu->addItem(" 2. Change end time:", endTimeString);
  start_Menu->addItem(" 3. Start Simulation:");
  start_Menu->addItem(" 0. Exit");

  train_Menu->addItem(" 1. Search Train By Number:");
  train_Menu->addItem(" 2. Search by TrainCar ID");
  train_Menu->addItem(" 3. Show All Trains");
  train_Menu->addItem(" 4. Change Log Level", loglvlString);
  train_Menu->addItem(" 0. Return");

  station_Menu->addItem(" 1. Show Station Names:");
  station_Menu->addItem(" 2. Show Station By Name:");
  station_Menu->addItem(" 3. Show All Stations: ");
  station_Menu->addItem(" 4. Change Log Level:", loglvlString);
  station_Menu->addItem(" 0. Return:");

  simulation_Menu->addItem(" 1. Change interval:", intervalString);
  simulation_Menu->addItem(" 2. Run Next Interval:");
  simulation_Menu->addItem(" 3. Next Event:");
  simulation_Menu->addItem(" 4. Finish Simulation:");
  simulation_Menu->addItem(" 5. Change Log Level", loglvlString);
  simulation_Menu->addItem(" 6. Train Menu:");
  simulation_Menu->addItem(" 7. Station Menu:");
  simulation_Menu->addItem(" 8. TrainCar menu:");
  simulation_Menu->addItem(" 0. Return ");

  trainCar_Menu->addItem(" 1. Show TrainCar by ID: ");
  trainCar_Menu->addItem(" 2. Show All Train Carriages: ");
  trainCar_Menu->addItem(" 3. Change Log Level:", loglvlString);
  trainCar_Menu->addItem(" 0. Return:  ");

  statistics_Menu->addItem(" 1. Change Log Level:", loglvlString);
  statistics_Menu->addItem(" 2. Print Statistics: ");
  statistics_Menu->addItem(" 3. Train Menu: ");
  statistics_Menu->addItem(" 4. Station Menu: ");
  statistics_Menu->addItem(" 5. Train Car Menu: ");
  statistics_Menu->addItem(" 0. Return: ");

  logLevel_Menu->addItem(" 1. Low Log Level:  ");
  logLevel_Menu->addItem(" 2. High Log Level: ");
  logLevel_Menu->addItem(" 0. Return: ");
}
//---------------------------------------------------------------------------'
// Name: clearAllMenues
// Desc: Clear all items previously added to the menues.
//---------------------------------------------------------------------------
void UserInterface::clearAllMenues() {
  start_Menu->clearMenuList();
  train_Menu->clearMenuList();
  station_Menu->clearMenuList();
  simulation_Menu->clearMenuList();
  trainCar_Menu->clearMenuList();
  statistics_Menu->clearMenuList();
  logLevel_Menu->clearMenuList();
}
//---------------------------------------------------------------------------
// Name: asciiTrain
// Desc: Works as a welcome splash.
//---------------------------------------------------------------------------
void UserInterface::asciiTrain() {
  std::cout << std::endl
            << std::endl
            << " \t IronBend Train And Brain Train Simulator, version 1.0"
            << std::endl
            << std::endl;

  std::cout << std::endl
            << "   o o o o o o o . . .   ______________________________ "
               "_____=======_||____		"
            << std::endl
            << "   o      _____           ||                            | |    "
               "             |	"
            << std::endl
            << " .][__n_n_|DD[  ====_____  |   IronBend Train & Brain   | | "
               "hehe0601        |	"
            << std::endl
            << ">(________|__|_[_________]_|____________________________|_|____"
               "_____________|	"
            << std::endl
            << "_'/'oo OOOOO oo`  ooo   ooo  'o!o!o                  o!o!o` "
               "'o!o         o!o`	"
            << std::endl
            << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
               "+-+-+-+-+-+-+-+-	"
            << std::endl
            << std::endl;
  waitForKey();
}
//---------------------------------------------------------------------------