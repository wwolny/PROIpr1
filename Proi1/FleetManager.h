#ifndef FLEETMANAGER_H
#define FLEETMANAGER_H

#include "Unit.h"
#include "Formation.h"
#include "Fleet.h"
#include <iostream>

class FleetManager
{
    public:
        int createFormation(Fleet *fleet, int Width, std::string formType);
        int deleteFormation(Fleet *fleet, Formation* delFormation);
        int createUnit(Fleet *fleet, std::string unitName, int unitSpeed, int unitPower, int unitDefense, int unitCapacity);
        int deleteUnit(Fleet *fleet, Unit* delUnit);
        int bestPowerUnit(Fleet* fleet, Formation* best);//the best in fleet
        int bestSpeedUnit(Fleet* fleet, Formation* best);// (* best) pointer to formtation/fleet with best units/formations
        int bestCapacityUnit(Fleet* fleet, Formation* best);
        int bestDefenseUnit(Fleet* fleet, Formation* best);
        int bestPowerUnit(Formation* Form, Formation* best);//the best in formation
        int bestSpeedUnit(Formation* Form, Formation* best);
        int bestCapacityUnit(Formation* Form, Formation* best);
        int bestDefenseUnit(Formation* Form, Formation* best);
        int bestDefenseForm(Fleet* fleet, Fleet* best);//the best formation in fleet
        int bestPowerForm(Fleet* fleet, Fleet* best);
        int bestSpeedForm(Fleet* fleet, Fleet* best);
        int bestCapacityForm(Fleet* fleet, Fleet* best);
        void addUnitName(Unit* unit, std::string name);
        void addUnitPower(Unit* unit, int Power);
        void addUnitDefense(Unit* unit, int Defense);
        void addUnitCapacity(Unit* unit, int Capacity);
        void addUnitSpeed(Unit* unit, int Speed);
        void setUnit(Unit* unit, std::string name, int Power, int Defense, int Capacity, int Speed);
        int pushUnitToForm(Formation* form, Unit* newunit);
        int pullUnitFromForm(Formation* form, Unit* unit);
        void setFormType(Formation* form, std::string Name);
        void setFormPower(Formation* form);
        void setFormDefense(Formation* form);
        void setFormSpeed(Formation* form);
        void setFormCapacity(Formation* form);
        void setFormation(Formation* form, std::string Name);
        void updateFormation(Formation* form);
        int isUnitName(std::string name);
        int isFormName(std::string name);
        Formation* giveForm(std::string name);
        Unit* giveUnit(std::string name);
        Formation bestUnit(Fleet* fleet);
        FleetManager();
        ~FleetManager();
        Fleet *fleet;
};

#endif // FLEETMANAGER_H
