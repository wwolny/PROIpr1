#ifndef FORMATION_H
#define FORMATION_H

#include <iostream>
#include "Unit.h"


class Formation
{
    public:
    std::string formType;
    int formPower;
    int formDefense;
    int formSpeed;
    int formCapacity;
    Formation *next;
    Formation *prev;
    public:
    Formation();
    ~Formation();

};

#endif // FORMATION_H
