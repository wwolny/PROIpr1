#include "FleetManagerTEST.h"
bool testAddFormation()
{
    FleetManager newManager;
    if(newManager.addFormation(newManager->fleet, 1, "Linia", 10, 5, 12, 8)==0) return NULL;
    }
bool testDeleteFormation();
bool testAddUnit();
bool testDeleteUnit();
bool testFleetUpdate();
bool testBestPowerUnit();
bool testBestSpeedUnit();
bool testBestCapacityUnit();
bool testBestDefenseUnit();
bool testCreateUnit();
bool testSetFormation();
