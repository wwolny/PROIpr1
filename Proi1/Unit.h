#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <string>
#include "Formation.h"
#include "Fleet.h"

class Unit
{
    public:
        Unit *next;
        Unit *prev;
        int getUnitSpeed(){return unitSpeed;}
        int getUnitPower(){return unitPower;}
        int getUnitDefense(){return unitDefense;}
        int getUnitCapacity(){return unitCapacity;}
        class Formation* getInFormation(){return inFormation;}
        std::string getUnitName(){return unitName;}
        int setUnitSpeed(int Speed);
        int setUnitDefense(int Defense);
        int setUnitPower(int Power);
        int setUnitCapacity(int Capacity);
        int setUnitName(std::string Name);
        void setInFormation(Formation* form);
        Unit();
        ~Unit();
    private:
        class Formation* inFormation;
        std::string unitName;
        int unitSpeed;
        int unitPower;
        int unitDefense;
        int unitCapacity;
};

#endif // UNIT_H
