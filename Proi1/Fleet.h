#ifndef FLEET_H
#define FLEET_H

#include "Formation.h"
#include "Unit.h"
#include <iostream>

class Fleet : public Formation, public Unit
{
    public:
    Formation *currentFormation;
    int fleetSize;//number of units
    int fleetSpeed;
    int fleetPower;
    int fleetDefense;
    int fleetCapacity;
    int fleetMaxSize;
    int fleetMaxFormations;
    int fleetFormationsNumber;
    int fleetAttackNumber;
    int fleetTransportNumber;
    Unit **fleetUnits;
    Formation **fleetFormations;
    Fleet();
    ~Fleet();
};

#endif // FLEET_H
