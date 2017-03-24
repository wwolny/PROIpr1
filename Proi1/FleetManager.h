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
        class Unit *bestPowerUnit(Fleet* fleet);//the best in fleet
        class Unit *bestSpeedUnit(Fleet* fleet);
        class Unit *bestCapacityUnit(Fleet* fleet);
        class Unit *bestDefenseUnit(Fleet* fleet);
        class Unit *bestPowerUnit(Formation* Form);//the best in formation
        class Unit *bestSpeedUnit(Formation* Form);
        class Unit *bestCapacityUnit(Formation* Form);
        class Unit *bestDefenseUnit(Formation* Form);
        class Formation *bestDefenseForm(Fleet* fleet);//the best formation in fleet
        class Formation *bestPowerForm(Fleet* fleet);
        class Formation *bestSpeedForm(Fleet* fleet);
        class Formation *bestCapacityForm(Fleet* fleet);
        void addUnitName(Unit* unit, std::string name);
        void addUnitPower(Unit* unit, int Power);
        void addUnitDefense(Unit* unit, int Defense);
        void addUnitCapacity(Unit* unit, int Capacity);
        void addUnitSpeed(Unit* unit, int Speed);
        void setUnit(Unit* unit, std::string name, int Power, int Defense, int Capacity, int Speed);
        int pushUnitToForm(Formation* form, Unit* newunit, int Width, int Row);
        int pullUnitFromForm(Formation* form, Unit* unit);
        void setFormType(Formation* form, std::string Name);
        void setFormPower(Formation* form);
        void setFormDefense(Formation* form);
        void setFormSpeed(Formation* form);
        void setFormCapacity(Formation* form);
        void setFormation(Formation* form, std::string Name);
        void updateFormation(Formation* form);
        FleetManager();
        ~FleetManager();
        Fleet *fleet;
};

#endif // FLEETMANAGER_H
