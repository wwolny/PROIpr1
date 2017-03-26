#ifndef FLEET_H
#define FLEET_H

#include "Formation.h"
#include "Unit.h"
#include <iostream>

class Fleet //:Formation :Unit
{
    public:
        int getFleetSize(){return fleetSize;}
        int getFleetFormNumb(){return fleetFormNumb;}
        std::string getFleetName(){return fleetName;}
        int setFleetSize(int Size);
        int setFleetFormNumb(int FormNumb);
        int setFleetName(std::string Name);
        void nullFormList();
        int operator++();
        int operator--();
        Formation* lastFormation;
        Unit* firstUnit;
        Fleet();
        ~Fleet();
    private:
        std::string fleetName;
        int fleetSize;//number of units
        int fleetFormNumb;
};

#endif // FLEET_H
