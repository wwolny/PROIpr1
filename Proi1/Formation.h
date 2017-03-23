#ifndef FORMATION_H
#define FORMATION_H

#include <iostream>
#include <vector>
#include "Unit.h"


class Formation//Attention! You have to FIRSTLY implement function startFormation(Width)
{
     public:
        int startFormation(int Width);
        Formation *next;
        Formation *prev;
        int getFormationSpeed(){return formSpeed;}
        int getFormationDefense(){return formDefense;}
        int getFormationPower(){return formPower;}
        int getFormationCapacity(){return formCapacity;}
        std::string getFormationName(){return formType;}
        bool getCheckStartForm(){return checkStartForm;}
        int getFormNowSize(){return formNowSize;}
        int getFormMaxSize(){return formMaxSize;}
        int getFormWidth(){return formWidth;}
        int getFormRows(){return Rows;}
        Unit* getUnitArr(int Width, int Rows);
        int setFormationSpeed(int Speed);
        int setFormationDefense(int Defense);
        int setFormationPower(int Power);
        int setFormationCapacity(int Capacity);
        int setFormationName(std::string Name);
        int operator++();
        int operator--();//operators return -1 if they cannot increment or decrement formNowSize
        Formation();
        Formation(int Width);
        ~Formation();
    private:
        bool checkStartForm;
        std::string formType;
        int formPower;
        int formDefense;
        int formSpeed;
        int formCapacity;
        int formNowSize;//how many units are in formation NOW
        int formMaxSize;//how many units can be in formation  Maximum
        static const int Rows=5;//how many units max can be in one row
        int formWidth;
        Unit **formArray[][Rows];
};

#endif // FORMATION_H
