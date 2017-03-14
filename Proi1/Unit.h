#ifndef UNIT_H
#define UNIT_H
#include <string>

class Unit
{
    public:
    char unitType;
    std::string unitName;
    int unitSpeed;
    int unitPower;
    int unitDefense;
    int unitCapacity;

    public:
        Unit();
        ~Unit();
        void addUnitType();
        void addUnitName();
        void addUnitPower();
        void addUnitDefense();
        void addUnitCapacity();
        void addUnitSpeed();
        void Wypisz();
    protected:
};

#endif // UNIT_H
