#include "Unit.h"

Unit::Unit()
{
    //ctor
}

void Unit::addUnitType()
{
    std::cout<<"Type type: ";
    std::cin>>unitType;
}

void Unit::addUnitName()
{
    std::cout<<"Type name: ";
    std::cin>>unitName;
}
void Unit::addUnitPower()
{
    std::cout<<"Type power: ";
    std::cin>>unitPower;
}
void Unit::addUnitDefense()
{
    std::cout<<"Type defense: ";
    std::cin>>unitDefense;
}
void Unit::addUnitCapacity()
{
    std::cout<<"Type capacity: ";
    std::cin>>unitCapacity;
}
void Unit::addUnitSpeed()
{
    std::cout<<"Type speed: ";
    std::cin>>unitSpeed;
}
void Unit::createUnit()
{
    addUnitType();
    addUnitName();
    addUnitPower();
    addUnitDefense();
    addUnitCapacity();
    addUnitSpeed();
}
void Unit::Wypisz()
{
    std::cout<<"Type: "<<unitType<<std::endl<<"Name: "<<unitName<<std::endl<<"Power: "<<unitPower<<std::endl<<
    "Speed: "<<unitSpeed<<std::endl<<"Defense: "<<unitDefense<<std::endl<<"Capacity: "<<unitCapacity;
}

Unit::~Unit()
{
    //dtor
}
