#ifndef FORMATION_H
#define FORMATION_H

#include <iostream>
#include "Unit.h"


class Formation //Attention! You have to FIRSTLY implement function startFormation(Width)
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
        int getR(){return r;}
        int getW(){return w;}
        int updateRW();
        Unit* getUnitArr(int Width, int Rows);
        int getUnitWidth(Unit* unit);
        int getUnitRow(Unit* unit);
        void nullArr();
        int setFormNowSize(int Size);
        void setFormSpeed();
        void setFormDefense();
        void setFormPower();
        void setFormCapacity();
        void setFormType(std::string Name);
        void updateFormation();
        void setFormation(std::string Name);
        Unit*** formArray;
        Formation operator++();
        Formation operator--();//operators return -1 if they cannot increment or decrement formNowSize
        Formation();
        Formation(int Width);
        ~Formation();
    private:
        int r;//i-Row, j-column(width)
        int w;
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
};

#endif // FORMATION_H
