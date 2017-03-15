#include "FleetManager.h"
Unit *bestPowerUnit(Fleet *fleet)
{
    if(fleet->fleetSize==0)
    {
        return NULL;
    }
    Unit *tmp, *uPower;
    int iPower;
    tmp=fleet->firstUnit;
    iPower=tmp->unitPower;
    uPower=tmp;
    while(tmp)
    {
        if(tmp->unitPower>iPower)
        {
            iPower=tmp->unitPower;
            uPower=tmp;
        }
    }
    return uPower;
}
Unit *bestSpeedUnit(Fleet *fleet)
{
    if(fleet->fleetSize==0)
    {
        return NULL;
    }
    Unit *tmp, *uSpeed;
    int iSpeed;
    tmp=fleet->firstUnit;
    iSpeed=tmp->unitSpeed;
    uSpeed=tmp;
    while(tmp)
    {
        if(tmp->unitSpeed>iSpeed)
        {
            iSpeed=tmp->unitSpeed;
            uSpeed=tmp;
        }
    }
    return uSpeed;
}
Unit *bestCapacityUnit(Fleet *fleet)
{
    if(fleet->fleetSize==0)
    {
        return NULL;
    }
    Unit *tmp, *uCapa;
    int iCapa;
    tmp=fleet->firstUnit;
    iCapa=tmp->unitCapacity;
    uCapa=tmp;
    while(tmp)
    {
        if(tmp->unitCapacity>iCapa)
        {
            iCapa=tmp->unitCapacity;
            uCapa=tmp;
        }
    }
    return uCapa;
}
Unit *bestDefenseUnit(Fleet *fleet)
{
    if(fleet->fleetSize==0)
    {
        return NULL;
    }
    Unit *tmp, *uDef;
    int iDef;
    tmp=fleet->firstUnit;
    iDef=tmp->unitDefense;
    uDef=tmp;
    while(tmp)
    {
        if(tmp->unitDefense>iDef)
        {
            iDef=tmp->unitDefense;
            uDef=tmp;
        }
    }
    return uDef;
}


void changeFormation(Fleet *fleet)
{
    Formation *tmp;
    tmp=fleet->lastFormation;
    if(fleet->fleetFormationsNumber==0)
    {
        std::cout<<"You cannot change the formation, because there is no formations available";
        return;
    }
    std::cout<<"Which formation you want to chose(Type exactly the same name): "<<std::endl;
    for(int i=0;i<fleet->fleetFormationsNumber;i++)
    {
        std::cout<<i+1<<". \""<<tmp->formType<<"\""<<std::endl;
    }
    std::string test;
    int Good=0;
    std::cin>>test;
    std::cin.ignore(1000,'\n');
    for(int j=0;j<fleet->fleetFormationsNumber;j++)
    {
        if(test==tmp->formType)
        {
            Good=1; break;
        }
        tmp=tmp->prev;
    }
    if(!Good) {std::cout<<"Zle dane!"; return;}
    fleet->currentFormation=tmp;
}
void addFormation(Fleet *fleet)
{
    Formation *newFormation;
    newFormation=new Formation;
    newFormation->setFormation();
    if(fleet->lastFormation==NULL)
    {
        fleet->lastFormation=newFormation;
        return;
    }
    fleet->lastFormation->next=newFormation;
    newFormation->prev=fleet->lastFormation->next;
    fleet->lastFormation=newFormation;
    fleet->fleetFormationsNumber++;
}
void deleteFormation(Fleet *fleet)
{
    Formation *tmp;
    tmp=fleet->lastFormation;
    std::cout<<"Which formation do you want to delete(Type exactly the same name): "<<std::endl;
    for(int i=0;i<fleet->fleetFormationsNumber;i++)
    {
        std::cout<<i+1<<". \""<<tmp->formType<<"\""<<std::endl;
    }
    std::string test;
    int Good=0;
    std::cin>>test;
    std::cin.ignore(1000,'\n');
    for(int j=0;j<fleet->fleetFormationsNumber;j++)
    {
        if(test==tmp->formType)
        {
            Good=1; break;
        }
        tmp=tmp->prev;
    }
    if(!Good) {std::cout<<"Zle dane!"; return;}
    if(tmp==fleet->currentFormation){fleet->currentFormation=NULL;}
    if(tmp==fleet->lastFormation && fleet->fleetFormationsNumber==1)
    {
        fleet->fleetFormationsNumber=0; fleet->lastFormation=NULL;
    }
    else if(tmp==fleet->lastFormation)
    {
        fleet->fleetFormationsNumber--; fleet->lastFormation=fleet->lastFormation->prev;
    }
    if(tmp->next){tmp->next->prev=tmp->prev;}
    if(tmp->prev){tmp->prev->next=tmp->next;}
    delete tmp;
}
void addUnit(Fleet *fleet)
{
    Unit *newUnit, *tmp;
    newUnit=new Unit;
    newUnit->createUnit();
    tmp=fleet->firstUnit;
    if(fleet->firstUnit==NULL){fleet->firstUnit=newUnit;    return;}
    tmp->next=fleet->firstUnit;
    fleet->firstUnit->prev=tmp;
    fleet->firstUnit=tmp;
    fleet->fleetSize++;
}
void deleteUnit(Fleet *fleet)
{
    Unit *tmp;
    tmp=fleet->firstUnit;
    std::cout<<"Which unit do you want to delete(Type exactly the same name): "<<std::endl;
    for(int i=0;i<fleet->fleetSize;i++)
    {
        std::cout<<i+1<<". \""<<tmp->unitName<<"\""<<std::endl;
    }
    std::string test;
    int Good=0;
    std::cin>>test;
    std::cin.ignore(1000,'\n');
    for(int j=0;j<fleet->fleetSize;j++)
    {
        if(test==tmp->unitName)
        {
            Good=1; break;
        }
        tmp=tmp->next;
    }
    if(!Good) {std::cout<<"Zle dane!"; return;}
    if(tmp==fleet->firstUnit&& fleet->fleetSize==1)
    {
        fleet->fleetSize=0; fleet->firstUnit=NULL;
    }
    else if(tmp==fleet->firstUnit)
    {
        fleet->fleetFormationsNumber--; fleet->firstUnit=fleet->firstUnit->next;
    }
    if(tmp->next){tmp->next->prev=tmp->prev;}
    if(tmp->prev){tmp->prev->next=tmp->next;}
    delete tmp;
}
void setFleetSpeed(Fleet *fleet)
{
    fleet->fleetSpeed=(bestSpeedUnit(fleet)->unitSpeed/fleet->fleetSize)*fleet->formSpeed;
}
void setFleetPower(Fleet *fleet)
{
    fleet->fleetPower=(bestPowerUnit(fleet)->unitPower/fleet->fleetSize)*fleet->formPower;
}
void setFleetDefense(Fleet *fleet)
{
    fleet->fleetDefense=(bestDefenseUnit(fleet)->unitDefense/fleet->fleetSize)*fleet->formDefense;
}
void setFleetCapacity(Fleet *fleet)
{
    fleet->fleetCapacity=(bestCapacityUnit(fleet)->unitCapacity/fleet->fleetSize)*fleet->formCapacity;
}
void fleetUpdate(Fleet *fleet)
{
    setFleetSpeed(fleet);
    setFleetPower(fleet);
    setFleetDefense(fleet);
    setFleetCapacity(fleet);
}

FleetManager::FleetManager()
{
    Fleet *fleet;
    fleet=new Fleet;
}

FleetManager::~FleetManager()
{
    while(fleet->lastFormation)
    {
        fleet->lastFormation=fleet->lastFormation->prev;
        delete fleet->lastFormation->next;
    }
    delete fleet;
}
