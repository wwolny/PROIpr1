#ifndef UNIT_H
#define UNIT_H
#include <iostream>
#include <string>

class Unit
{
    public:
        Unit *next;
        Unit *prev;
        int getUnitSpeed(){return unitSpeed;}
        int getUnitPower(){return unitPower;}
        int getUnitDefense(){return unitDefense;}
        int getUnitCapacity(){return unitCapacity;}
        bool getInFormation(){return inFormation;}
        std::string getUnitName(){return unitName;}
        int setUnitSpeed(int Speed);
        int setUnitDefense(int Defense);
        int setUnitPower(int Power);
        int setUnitCapacity(int Capacity);
        int setUnitName(std::string Name);
        void setInFormation(bool i);
        Unit();
        ~Unit();
    private:
        bool inFormation;
        std::string unitName;
        int unitSpeed;
        int unitPower;
        int unitDefense;
        int unitCapacity;
};

#endif // UNIT_H
