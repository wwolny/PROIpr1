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



Unit::~Unit()
{
    //dtor
}
