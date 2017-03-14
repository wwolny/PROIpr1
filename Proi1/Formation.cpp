#include "Formation.h"
#include <iostream>

Formation::Formation()
{
    //ctor
}
void Formation::setFormType()
{
    std::cout<<"Type name: ";
    std::cin>>formType;
}
void Formation::setFormPower()
{
    std::cout<<"Type power ratio: ";
    std::cin>>formPower;
}
void Formation::setFormDefense()
{
    std::cout<<"Type defense ratio: ";
    std::cin>>formDefense;
}
void Formation::setFormSpeed()
{
    std::cout<<"Type speed ratio: ";
    std::cin>>formSpeed;
}
void Formation::setFormCapacity()
{
    std::cout<<"Type capacity ratio: ";
    std::cin>>formCapacity;
}
Formation::~Formation()
{
    //dtor
}
