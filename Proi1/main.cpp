#include <iostream>
#include "Unit.h"
#include "Formation.h"
#include "Fleet.h"
#include "FleetManager.h"

void formationAsset(FleetManager *myFleet);

int main()
{
    FleetManager *myFleet;
    myFleet=new FleetManager;
    formationAsset(myFleet);
    return( 0 );
}

void formationAsset(FleetManager *myFleet)
{
    /*myFleet->addFormation(myFleet->fleet);
    myFleet->addFormation(myFleet->fleet);
    myFleet->changeFormation(myFleet->fleet);
    myFleet->addUnit(myFleet->fleet);
    myFleet->addUnit(myFleet->fleet);
    myFleet->deleteUnit(myFleet->fleet);
    myFleet->deleteFormation(myFleet->fleet);
    myFleet->changeFormation(myFleet->fleet);
*/}
