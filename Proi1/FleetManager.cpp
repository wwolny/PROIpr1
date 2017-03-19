#include "FleetManager.h"
Unit* FleetManager::bestPowerUnit(Fleet *fleet)
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
        tmp=tmp->next;
    }
    return uPower;
}



Unit *bestSpeedUnit(Fleet *fleet)
{
    if(fleet->fleetSize==0)
    {
        return NULL;
    }
    Unit *tmp;
    int iSpeed;
    tmp=fleet->firstUnit;
    iSpeed=tmp->unitSpeed;
    fleet->currentUnit=tmp;
    while(tmp)
    {
        if(tmp->unitSpeed>iSpeed)
        {
            iSpeed=tmp->unitSpeed;
            fleet->currentUnit=tmp;
        }
        tmp=tmp->next;
    }
    return fleet->currentUnit;
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
        tmp=tmp->next;
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
        tmp=tmp->next;
    }
    return uDef;
}


void FleetManager::changeFormation(Fleet* fleet, Formation* formName)
{
    fleet->currentFormation=formName;
}
void FleetManager::addFormation(Fleet *fleet)
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
void FleetManager::deleteFormation(Fleet *fleet)
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
    tmp=fleet->lastFormation;
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
void FleetManager::addUnit(Fleet *fleet)
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
void FleetManager::deleteUnit(Fleet *fleet)
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
    tmp=fleet->firstUnit;
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
void FleetManager::setFleetSpeed(Fleet *fleet)
{
    //fleet->fleetSpeed=(bestSpeedUnit(fleet)->unitSpeed/fleet->fleetSize)*fleet->formSpeed;
}
void FleetManager::setFleetPower(Fleet *fleet)
{
    //fleet->fleetPower=(bestPowerUnit(fleet)->unitPower/fleet->fleetSize)*fleet->formPower;
}
void FleetManager::setFleetDefense(Fleet *fleet)
{
    //fleet->fleetDefense=(bestDefenseUnit(fleet)->unitDefense/fleet->fleetSize)*fleet->formDefense;
}
void FleetManager::setFleetCapacity(Fleet *fleet)
{
    //fleet->fleetCapacity=(bestCapacityUnit(fleet)->unitCapacity/fleet->fleetSize)*fleet->formCapacity;
}
void FleetManager::fleetUpdate(Fleet *fleet)
{
    setFleetSpeed(fleet);
    setFleetPower(fleet);
    setFleetDefense(fleet);
    setFleetCapacity(fleet);
}

FleetManager::FleetManager()
{
    fleet=new Fleet;
}

FleetManager::~FleetManager()
{
    while(fleet->firstUnit)
    {
        fleet->firstUnit=fleet->firstUnit->next;
        delete fleet->firstUnit->prev;
    }
    while(fleet->lastFormation)
    {
        fleet->lastFormation=fleet->lastFormation->prev;
        delete fleet->lastFormation->next;
    }
    delete fleet;
}

void FleetManager::addUnitName(Unit unit, std::string name)
{
    unit->unitName=name;
}
void FleetManager::addUnitPower(Unit unit, int Power)
{
    unit->unitPower=Power;
}
void FleetManager::addUnitDefense(Unit unit, int Defense)
{
    unit->unitDefense=Defense;
}
void FleetManager::addUnitCapacity(Unit unit, int Capacity)
{
    unit->unitCapacity=Capacity;
}
void FleetManager::addUnitSpeed(Unit unit, int Speed)
{
    unit->unitSpeed=Speed;
}
void FleetManager::createUnit(Unit unit, std::string name, int Power, int Defense, int Capacity, int Speed)
{
    addUnitName(unit, name);
    addUnitPower(unit, Power);
    addUnitDefense(unit, Defense);
    addUnitCapacity(unit, Capacity);
    addUnitSpeed(unit, Speed);
}
void FleetManager::Wypisz()
{
    std::cout<<"Unit Name: "<<unitName<<std::endl<<"Power: "<<unitPower<<std::endl<<
    "Speed: "<<unitSpeed<<std::endl<<"Defense: "<<unitDefense<<std::endl<<"Capacity: "<<unitCapacity;
}

void FleetManager::setFormType(Formation form, std::string Name)
{
    form->formType=Name;
}
void FleetManager::setFormPower(Formation form, int Power)
{
    form->formPower=Power;
}
void FleetManager::setFormDefense(Formation form, int Defense)
{
    form->formDefense=Defense;
}
void FleetManager::setFormSpeed(Formation form, int Speed)
{
    form->formSpeed=Speed;
}
void FleetManager::setFormCapacity(Formation form, int Capacity)
{
    form->formCapacity=Capacity;
}
void FleetManager::setFormation(Formation form, std::string Name, int Power, int Defense, int Speed, int Capacity)
{
    setFormType(form, Name);
    setFormPower(form, Power);
    setFormDefense(form, Defense);
    setFormSpeed(form, Speed);
    setFormCapacity(form, Capacity);
