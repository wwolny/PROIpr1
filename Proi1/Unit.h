#ifndef UNIT_H
#define UNIT_H
#include <iostream>

class Unit
{
    public:
    char unitType;
    std::string unitName;
    int unitSpeed;
    int unitPower;
    int unitDefense;
    int unitCapacity;
    //Unit *next;
    //Unit *prev;
    public:
        Unit();
        ~Unit();
        void addUnitType();
        void addUnitName();
        void addUnitPower();
        void addUnitDefense();
        void addUnitCapacity();
        void addUnitSpeed();
        void createUnit();
        void Wypisz();
    protected:
};

#endif // UNIT_H
