#ifndef FLEET_H
#define FLEET_H

#include "Formation.h"
#include "Unit.h"

class Fleet : public Formation, public Unit
{
    Formation fleetFormation;
    int fleetSize;//number of units
    int fleetSpeed;
    int fleetPower;
    int fleetDefense;
    int fleetCapacity;
    int fleetMaxSize;
    int fleetAttackNumber;
    int fleetTransportNumber;
    Unit **fleetUnits;// = new Unit*[fleetMaxSize];
    public:
        Fleet();
        ~Fleet();
};

#endif // FLEET_H
