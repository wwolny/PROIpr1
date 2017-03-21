#include "Fleet.h"

Fleet::Fleet()
{
    firstUnit=NULL;
    currentFormation=NULL;
    lastFormation=NULL;
    currentUnit=NULL;
    fleetFormNumb=0;
    fleetName="";
    fleetSize=0;
    fleetSpeed=0;
    fleetPower=0;
    fleetDefense=0;
    fleetCapacity=0;
}

Fleet::~Fleet()
{

}
int Fleet::setFleetSize(int Size)
{
    if(Size<0) return 0;
    fleetSize=Size;
    return 1;
}
int Fleet::setFleetSpeed(int Speed)
{
    if(Speed<0) return 0;
    fleetSpeed=Speed;
    return 1;
}
int Fleet::setFleetPower(int Power)
{
    if(Power<0) return 0;
    fleetPower=Power;
    return 1;
}
int Fleet::setFleetDefense(int Defense)
{
    if(Defense<0) return 0;
    fleetDefense=Defense;
    return 1;
}
int Fleet::setFleetCapacity(int Capacity)
{
    if(Capacity<0) return 0;
    fleetCapacity=Capacity;
    return 1;
}
int Fleet::setFleetFormNumb(int FormNumb)
{
    if(FormNumb<0) return 0;
    fleetFormNumb=FormNumb;
    return 1;
}
int Fleet::setFleetName(std::string Name)
{
    fleetName=Name;
    return 1;
}
