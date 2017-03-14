#include "Fleet.h"

Fleet::Fleet()
{
   Unit **fleetUnits = new Unit*[fleetMaxSize];
}

Fleet::~Fleet()
{
    delete[] fleetUnits;
}
