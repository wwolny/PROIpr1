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
        Unit* bPowU(Fleet *fleet);//the best in fleet
        Unit* bSpeU(Fleet *fleet);
        Unit* bDefU(Fleet *fleet);
        Unit* bCapaU(Fleet *fleet);
        Unit* bPowU(Formation* Form);//the best in formation
        Unit* bSpeU(Formation* Form);
        Unit* bDefU(Formation* Form);
        Unit* bCapaU(Formation* Form);
        Formation* bPowF(Fleet* fleet);//the best formation in fleet
        Formation* bSpeF(Fleet* fleet);
        Formation* bDefF(Fleet* fleet);
        Formation* bCapaF(Fleet* fleet);
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
        int isUnitInForm(Formation* form, Unit* unit);
        Formation* giveForm(std::string name);
        Unit* giveUnit(std::string name);
        FleetManager();
        ~FleetManager();
        Fleet *fleet;
};

#endif // FLEETMANAGER_H
