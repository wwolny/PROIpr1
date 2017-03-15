#include "Unit.h"

Unit::Unit()
{
    //ctor
}

void Unit::addUnitName()
{
    std::cout<<"Type name: ";
    std::cin>>unitName;
    std::cin.ignore(1000,'\n');
}
void Unit::addUnitPower()
{
    std::cout<<"Type power: ";
    while(!(std::cin >>unitPower))
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout<<"Invalid input. Try again: ";
    }
}
void Unit::addUnitDefense()
{
    std::cout<<"Type defense: ";
    while(!(std::cin >>unitDefense))
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout<<"Invalid input. Try again: ";
    }
}
void Unit::addUnitCapacity()
{
    std::cout<<"Type capacity: ";
    while(!(std::cin >>unitCapacity))
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout<<"Invalid input. Try again: ";
    }
}
void Unit::addUnitSpeed()
{
    std::cout<<"Type speed: ";
    while(!(std::cin >>unitPower))
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout<<"Invalid input. Try again: ";
    }
}
void Unit::createUnit()
{
    addUnitName();
    addUnitPower();
    addUnitDefense();
    addUnitCapacity();
    addUnitSpeed();
}
void Unit::Wypisz()
{
    std::cout<<"Name: "<<unitName<<std::endl<<"Power: "<<unitPower<<std::endl<<
    "Speed: "<<unitSpeed<<std::endl<<"Defense: "<<unitDefense<<std::endl<<"Capacity: "<<unitCapacity;
}

Unit::~Unit()
{
    //dtor
}
