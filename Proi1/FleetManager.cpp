#include "FleetManager.h"

void changeFormation(Fleet *fleet)
{
    if(fleet->fleetFormationsNumber==0)
    {
        std::cout<<"You cannot change the formation, becouse there is no formations available";
        return;
    }
    std::cout<<"Which formation you want to chose(Type exactly the same name): "<<std::endl;
    for(int i=0;i<fleet->fleetFormationsNumber;i++)
    {
        std::cout<<i+1<<". \""<<fleet->fleetFormations[i]->formType<<"\""<<std::endl;
    }
    std::string test;
    int Good=0, j=0;
    std::cin>>test;
    std::cin.ignore(1000,'\n');
    for(j=0;j<fleet->fleetFormationsNumber;j++)
    {
        if(test==fleet->fleetFormations[j]->formType)
        {
            Good=1; break;
        }
    }
    if(Good)    fleet->currentFormation=fleet->fleetFormations[j];
    else std::cout<<"Zle dane!";
}
void addFormation(Fleet *fleet)
{
    if(fleet->fleetFormationsNumber>=fleet->fleetMaxFormations)
    {
        std::cout<<"You cannot add more formations, becouse you've already used all available space.";
        return;
    }
    Formation *newFormation;
    newFormation->setFormation();//???????????????????????????????????????
    fleet->fleetFormations[fleet->fleetFormationsNumber]=newFormation;
    fleet->fleetFormationsNumber++;
}
void deleteFormation(Fleet *fleet)
{
    if(fleet->fleetFormationsNumber==0)
    {
        std::cout<<"There is no formations";
        return;
    }
    Formation *newFormation;
    newFormation->setFormation();//???????????????????????????????????????
    fleet->fleetFormations[fleet->fleetFormationsNumber]=newFormation;
    fleet->fleetFormationsNumber++;
}
void addUnit(Fleet *fleet);
void deleteUnit(Fleet *fleet);
void setFleetSpeed(Fleet *fleet);
void setFleetPower(Fleet *fleet);
void setFleetDefense(Fleet *fleet);
void setFleetCapacity(Fleet *fleet);
void fleetUpdate(Fleet *fleet);
Unit bestPowerUnit(Fleet *fleet);
Unit bestSpeedUnit(Fleet *fleet);
Unit bestCapacityUnit(Fleet *fleet);
Unit bestDefenseUnit(Fleet *fleet);

FleetManager::FleetManager()
{
    //ctor
}

FleetManager::~FleetManager()
{
    //dtor
}
