#include "Fleet.h"

Fleet::Fleet()
{
    fleetMaxSize=100;
    fleetMaxFormations=10;
    Unit **fleetUnits = new Unit*[fleetMaxSize];
    fleetUnits[0]=NULL;
    Formation **fleetFormations = new Formation*[fleetMaxFormations];
    fleetFormations[0]=NULL;
    currentFormation=fleetFormations[0];
    fleetFormationsNumber=0;
    fleetSize=0;
    fleetSpeed=0;
    fleetPower=0;
    fleetDefense=0;
    fleetCapacity=0;
    fleetAttackNumber=0;
    fleetTransportNumber=0;
}

Fleet::~Fleet()
{
    for(int i=0;i<fleetFormationsNumber;i++)
    {
        delete fleetFormations[i];
    }
    delete[] fleetFormations;

    for(int i=0;i<fleetSize;i++)
    {
        delete fleetUnits[i];
    }
    delete[] fleetUnits;
}
