#ifndef FORMATION_H
#define FORMATION_H

#include <iostream>
#include <vector>
#include "Unit.h"


class Formation
{
    private:
        std::string formType;
        int formPower;
        int formDefense;
        int formSpeed;
        int formCapacity;
        int formNowSize;//how many units are in formation NOW
        static const int FORMATIONMAXSIZE=12;//how many units max can be in formation
        Unit* formLook[][FORMATIONMAXSIZE];
    public:
        Formation *next;
        Formation *prev;
        int getFormationSpeed(){return formSpeed;}
        int getFormationDefense(){return formDefense;}
        int getFormationPower(){return formPower;}
        int getFormationCapacity(){return formCapacity;}
        std::string getFormationName(){return formType;}
        int setFormationSpeed(int Speed);
        int setFormationDefense(int Defense);
        int setFormationPower(int Power);
        int setFormationCapacity(int Capacity);
        int setFormationName(std::string Name);
        Formation();
        ~Formation();

};

#endif // FORMATION_H
