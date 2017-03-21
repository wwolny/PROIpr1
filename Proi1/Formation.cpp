#include "Formation.h"

Formation::Formation()
{
    next=NULL;
    prev=NULL;
    formType="";
    formPower=0;
    formDefense=0;
    formSpeed=0;
    formCapacity=0;
}


Formation::~Formation()
{
    //dtor
}

int Formation::setFormationSpeed(int Speed)
{
    if(Speed<0) return 0;
    formSpeed=Speed;
    return 1;
}
int Formation::setFormationDefense(int Defense)
{
    if(Defense<0) return 0;
    formDefense=Defense;
    return 1;
}
int Formation::setFormationPower(int Power)
{
    if(Power<0) return 0;
    formPower=Power;
    return 1;
}
int Formation::setFormationCapacity(int Capacity)
{
    if(Capacity<0) return 0;
    formCapacity=Capacity;
    return 1;
}
int Formation::setFormationName(std::string Name)
{
    formType=Name;
    return 1;
}
