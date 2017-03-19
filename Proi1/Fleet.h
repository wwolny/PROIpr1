#ifndef FLEET_H
#define FLEET_H

#include "Formation.h"
#include "Unit.h"
#include <iostream>

class Fleet : public Formation, public Unit
{
    public:
    Formation* currentFormation;
    Formation* lastFormation;
    Unit* currentUnit;
    Unit* firstUnit;
    std::string fleetName;
    int fleetSize;//number of units
    int fleetSpeed;
    int fleetPower;
    int fleetDefense;
    int fleetCapacity;
    int fleetFormationsNumber;
    Fleet();
    ~Fleet();
};

#endif // FLEET_H
