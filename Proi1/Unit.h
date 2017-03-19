#ifndef UNIT_H
#define UNIT_H
#include <iostream>

class Unit
{
    private://private getset
    std::string unitName;
    int unitSpeed;
    int unitPower;
    int unitDefense;
    int unitCapacity;
    Unit *next;
    Unit *prev;
    public:
        Unit();
        ~Unit();
};

#endif // UNIT_H
