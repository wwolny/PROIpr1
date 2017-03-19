#ifndef FLEETMANAGER_H
#define FLEETMANAGER_H

#include "Unit.h"
#include "Formation.h"
#include "Fleet.h"
#include <iostream>

class FleetManager
{
    public:
        Fleet *fleet;
        void changeFormation(Fleet *fleet, Formation* formName);
        void addFormation(Fleet *fleet, std::string formType, int formPower, int formDefense, int formSpeed, int formCapacity);
        void deleteFormation(Fleet *fleet, Formation* delFormation);
        void addUnit(Fleet *fleet, std::string unitName, int unitSpeed, int unitPower, int unitDefense, int unitCapacity);
        void deleteUnit(Fleet *fleet, Unit* delUnit);
        void setFleetSpeed(Fleet *fleet);
        void setFleetPower(Fleet *fleet);
        void setFleetDefense(Fleet *fleet);
        void setFleetCapacity(Fleet *fleet);
        void fleetUpdate(Fleet *fleet);
        Unit *bestPowerUnit(Fleet *fleet);
        Unit *bestSpeedUnit(Fleet *fleet);
        Unit *bestCapacityUnit(Fleet *fleet);
        Unit *bestDefenseUnit(Fleet *fleet);
        void addUnitName(Unit unit, std::string name);
        void addUnitPower(Unit unit, int Power);
        void addUnitDefense(Unit unit, int Defense);
        void addUnitCapacity(Unit unit, int Capacity);
        void addUnitSpeed(Unit unit, int Speed);
        void createUnit(Unit unit, std::string name, int Power, int Defense, int Capacity, int Speed);
        void WypiszUnit();
        void setFormType(Formation form, std::string Name);
        void setFormPower(Formation form, int Power);
        void setFormDefense(Formation form, int Defense);
        void setFormSpeed(Formation form, int Speed);
        void setFormCapacity(Formation form, int Capacity);
        void setFormation(Formation form, std::string Name, int Power, int Defense, int Speed, int Capacity);
        FleetManager();
        ~FleetManager();
};

#endif // FLEETMANAGER_H
