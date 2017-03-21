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
        int changeFormation(Fleet *fleet, Formation* formName);
        int addFormation(Fleet *fleet, std::string formType, int formPower, int formDefense, int formSpeed, int formCapacity);
        int deleteFormation(Fleet *fleet, Formation* delFormation);
        int addUnit(Fleet *fleet, std::string unitName, int unitSpeed, int unitPower, int unitDefense, int unitCapacity);
        int deleteUnit(Fleet *fleet, Unit* delUnit);
        void setFleetSpeed(Fleet *fleet, int speed);
        void setFleetPower(Fleet *fleet, int power);
        void setFleetDefense(Fleet *fleet, int defense);
        void setFleetCapacity(Fleet *fleet, int capacity);
        void fleetUpdate(Fleet *fleet, int speed, int power, int defense, int capacity);
        Unit *bestPowerUnit(Fleet *fleet);
        Unit *bestSpeedUnit(Fleet *fleet);
        Unit *bestCapacityUnit(Fleet *fleet);
        Unit *bestDefenseUnit(Fleet *fleet);
        void addUnitName(Unit* unit, std::string name);
        void addUnitPower(Unit* unit, int Power);
        void addUnitDefense(Unit* unit, int Defense);
        void addUnitCapacity(Unit* unit, int Capacity);
        void addUnitSpeed(Unit* unit, int Speed);
        void createUnit(Unit* unit, std::string name, int Power, int Defense, int Capacity, int Speed);
        void WypiszUnit();
        void setFormType(Formation* form, std::string Name);
        void setFormPower(Formation* form, int Power);
        void setFormDefense(Formation* form, int Defense);
        void setFormSpeed(Formation* form, int Speed);
        void setFormCapacity(Formation* form, int Capacity);
        void setFormation(Formation* form, std::string Name, int Power, int Defense, int Speed, int Capacity);
        FleetManager();
        ~FleetManager();
};

#endif // FLEETMANAGER_H
