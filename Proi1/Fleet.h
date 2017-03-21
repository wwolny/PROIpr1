#ifndef FLEET_H
#define FLEET_H

#include "Formation.h"
#include "Unit.h"
#include <iostream>

class Fleet : public Formation, public Unit
{
    private:
        std::string fleetName;
        int fleetSize;//number of units
        int fleetSpeed;
        int fleetPower;
        int fleetDefense;
        int fleetCapacity;
        int fleetFormNumb;//Do Tego operator mopzna walnac
    public:
        int getFleetSpeed(){return fleetSpeed;}
        int getFleetPower(){return fleetPower;}
        int getFleetDefense(){return fleetDefense;}
        int getFleetCapacity(){return fleetCapacity;}
        int getFleetSize(){return fleetSize;}
        int getFleetFormNumb(){return fleetFormNumb;}
        std::string getFleetName(){return fleetName;}
        int setFleetSize(int Size);
        int setFleetSpeed(int Speed);
        int setFleetPower(int Power);
        int setFleetDefense(int Defense);
        int setFleetCapacity(int Capacity);
        int setFleetFormNumb(int FormNumb);
        int setFleetName(std::string Name);
        Formation* currentFormation;
        Formation* lastFormation;
        Unit* currentUnit;
        Unit* firstUnit;
        Fleet();
        ~Fleet();
};

#endif // FLEET_H
