#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <string>
//#include "Formation.h"

class Formation;

class Unit
{
    public:
        Unit *next;
        Unit *prev;
        int getUnitSpeed(){return unitSpeed;}
        int getUnitPower(){return unitPower;}
        int getUnitDefense(){return unitDefense;}
        int getUnitCapacity(){return unitCapacity;}
        Formation* getInFormation(){return inFormation;}
        std::string getUnitName(){return unitName;}
        int setUnitSpeed(int Speed);
        int setUnitDefense(int Defense);
        int setUnitPower(int Power);
        int setUnitCapacity(int Capacity);
        int setUnitName(std::string Name);
        void setInFormation(Formation* form);
        Unit();
        ~Unit();
        Unit (const Unit &unit);
        Unit & operator=(const Unit *unit);
    private:
        class Formation* inFormation;
        std::string unitName;
        int unitSpeed;
        int unitPower;
        int unitDefense;
        int unitCapacity;
};

#endif // UNIT_H
