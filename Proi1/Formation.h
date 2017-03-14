#ifndef FORMATION_H
#define FORMATION_H

#include <iostream>


class Formation
{
    private:
    std::string formType;
    int formPower;
    int formDefense;
    int formSpeed;
    int formCapacity;

    public:
    void setFormType();
    void setFormPower();
    void setFormDefense();
    void setFormSpeed();
    void setFormCapacity();
    Formation();
    ~Formation();
};

#endif // FORMATION_H
