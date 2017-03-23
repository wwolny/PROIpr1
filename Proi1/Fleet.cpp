#include "Fleet.h"

Fleet::Fleet()
{
    this->firstUnit=NULL;
    this->lastFormation=NULL;
    this->fleetFormNumb=0;
    this->fleetName="";
    this->fleetSize=0;
    /*this->fleetSpeed=0;
    this->fleetPower=0;
    this->fleetDefense=0;
    this->fleetCapacity=0;*/
}

Fleet::~Fleet()
{

}
int Fleet::operator++()
{
    this->fleetFormNumb++;
    return 1;
}
int Fleet::operator--()
{
    if(this->fleetFormNumb==0)return 0;
    this->fleetFormNumb--;
    return 1;
}

int Fleet::setFleetSize(int Size)
{
    if(Size<0) return 0;
    this->fleetSize=Size;
    return 1;
}

int Fleet::setFleetFormNumb(int FormNumb)
{
    if(FormNumb<0) return 0;
    this->fleetFormNumb=FormNumb;
    return 1;
}
int Fleet::setFleetName(std::string Name)
{
    this->fleetName=Name;
    return 1;
}
/*
int Fleet::setFleetSpeed(int Speed)
{
    if(Speed<0) return 0;
    this->fleetSpeed=Speed;
    return 1;
}
int Fleet::setFleetPower(int Power)
{
    if(Power<0) return 0;
    this->fleetPower=Power;
    return 1;
}
int Fleet::setFleetDefense(int Defense)
{
    if(Defense<0) return 0;
    this->fleetDefense=Defense;
    return 1;
}
int Fleet::setFleetCapacity(int Capacity)
{
    if(Capacity<0) return 0;
    this->fleetCapacity=Capacity;
    return 1;
}*/
