#ifndef FLEETMANAGER_H
#define FLEETMANAGER_H

#include "Unit.h"
#include "Formation.h"
#include "Fleet.h"
#include <iostream>

class FleetManager
{
    public:
        int createFormation(Fleet *fleet, int Width, std::string formType, int formPower, int formDefense, int formSpeed, int formCapacity);
        int deleteFormation(Fleet *fleet, Formation* delFormation);
        int createUnit(Fleet *fleet, std::string unitName, int unitSpeed, int unitPower, int unitDefense, int unitCapacity);
        int deleteUnit(Fleet *fleet, Unit* delUnit);
        /*void addFleetSpeed(Fleet *fleet, int speed);
        void addFleetPower(Fleet *fleet, int power);
        void addFleetDefense(Fleet *fleet, int defense);
        void addFleetCapacity(Fleet *fleet, int capacity);
        void fleetUpdate(Fleet *fleet, int speed, int power, int defense, int capacity);*/
        Unit *bestPowerUnit(Fleet* fleet);//the best in fleet
        Unit *bestSpeedUnit(Fleet* fleet);
        Unit *bestCapacityUnit(Fleet* fleet);
        Unit *bestDefenseUnit(Fleet* fleet);
        Unit *bestPowerUnit(Formation* Form);//the best in formation
        Unit *bestSpeedUnit(Formation* Form);
        Unit *bestCapacityUnit(Formation* Form);
        Unit *bestDefenseUnit(Formation* Form);
        Formation *bestDefenseForm(Fleet* fleet);//the best formation in fleet
        Formation *bestPowerForm(Fleet* fleet);
        Formation *bestSpeedForm(Fleet* fleet);
        Formation *bestCapacityForm(Fleet* fleet);
        void addUnitName(Unit* unit, std::string name);
        void addUnitPower(Unit* unit, int Power);
        void addUnitDefense(Unit* unit, int Defense);
        void addUnitCapacity(Unit* unit, int Capacity);
        void addUnitSpeed(Unit* unit, int Speed);
        void setUnit(Unit* unit, std::string name, int Power, int Defense, int Capacity, int Speed);
        void setFormType(Formation* form, std::string Name);
        void setFormPower(Formation* form, int Power);
        void setFormDefense(Formation* form, int Defense);
        void setFormSpeed(Formation* form, int Speed);
        void setFormCapacity(Formation* form, int Capacity);
        void setFormation(Formation* form, std::string Name, int Power, int Defense, int Speed, int Capacity);
        FleetManager();
        ~FleetManager();
        Fleet *fleet;
};

#endif // FLEETMANAGER_H
