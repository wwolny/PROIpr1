#ifndef FORMATION_H
#define FORMATION_H

#include <iostream>


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
    void setFormType();
    void setFormPower();
    void setFormDefense();
    void setFormSpeed();
    void setFormCapacity();
    void setFormation();
};

#endif // FORMATION_H
