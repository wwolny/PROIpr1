#include "Unit.h"

/*
    std::cout<<"Type unit defense: ";
    while(!(std::cin >>unitDefense))
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout<<"Invalid input. Try again: ";
    }*/

Unit::Unit()
{
    next=NULL;
    prev=NULL;
    unitName="";
    unitSpeed=0;
    unitPower=0;
    unitDefense=0;
    unitCapacity=0;
}

int Unit::setUnitSpeed(int Speed)
{
    if(Speed<0) return 0;
    unitSpeed=Speed;
    return 1;
}
int Unit::setUnitDefense(int Defense)
{
    if(Defense<0) return 0;
    unitDefense=Defense;
    return 1;
}
int Unit::setUnitPower(int Power)
{
    if(Power<0) return 0;
    unitPower=Power;
    return 1;
}
int Unit::setUnitCapacity(int Capacity)
{
    if(Capacity<0) return 0;
    unitCapacity=Capacity;
    return 1;
}
int Unit::setUnitName(std::string Name)
{
    unitName=Name;
    return 1;
}

Unit::~Unit()
{
    //dtor
}
