#ifndef FLEETMANAGER_H
#define FLEETMANAGER_H

#include "Fleet.h"
#include <iostream>

class FleetManager : public Fleet
{
    public:
        void changeFormation(Fleet *fleet);
        void addFormation(Fleet *fleet);
        void deleteFormation(Fleet *fleet);
        void addUnit(Fleet *fleet);
        void deleteUnit(Fleet *fleet);
        void setFleetSpeed(Fleet *fleet);
        void setFleetPower(Fleet *fleet);
        void setFleetDefense(Fleet *fleet);
        void setFleetCapacity(Fleet *fleet);
        void fleetUpdate(Fleet *fleet);
        Unit bestPowerUnit(Fleet *fleet);
        Unit bestSpeedUnit(Fleet *fleet);
        Unit bestCapacityUnit(Fleet *fleet);
        Unit bestDefenseUnit(Fleet *fleet);
        FleetManager();
        ~FleetManager();
};

#endif // FLEETMANAGER_H
