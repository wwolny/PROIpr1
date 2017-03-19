#include "Fleet.h"

Fleet::Fleet()
{
    firstUnit=NULL;
    currentFormation=NULL;
    lastFormation=NULL;
    currentUnit=NULL;
    fleetFormationsNumber=0;
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
