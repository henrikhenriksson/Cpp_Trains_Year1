// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX
// Filename: TrainMap.cpp
// Author: Henrik Henriksson (hehe0601)
// Created: 2019-05-21
// Description: Defenition file for TrainMap class, OO programming C++
// Miun Spring 2019
// XxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX

#include "TrainMap.h"

//---------------------------------------------------------------------------
// Name: Constructor
// Desc: Initialized
//---------------------------------------------------------------------------
TrainMap::TrainMap(std::string const &p_Dep, std::string const &p_des,
                   int const &dist)
    : dep_Station(p_Dep), des_Station(p_des), distance(dist) {}
//---------------------------------------------------------------------------
