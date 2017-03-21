#include "FleetManager.h"
Unit* FleetManager::bestPowerUnit(Fleet *fleet)
{
    if(fleet->getFleetSize()==0)
    {
        return NULL;
    }
    Unit *tmp, *uPower;
    int iPower;
    tmp=fleet->firstUnit;
    iPower=tmp->getUnitPower();
    uPower=tmp;
    while(tmp)
    {
        if(tmp->getUnitPower()>iPower)
        {
            iPower=tmp->getUnitPower();
            uPower=tmp;
        }
        tmp=tmp->next;
    }
    return uPower;
}



Unit *bestSpeedUnit(Fleet *fleet)
{
    if(fleet->getFleetSize()==0)
    {
        return NULL;
    }
    Unit *tmp;
    int iSpeed;
    tmp=fleet->firstUnit;
    iSpeed=tmp->getUnitSpeed();
    fleet->currentUnit=tmp;
    while(tmp)
    {
        if(tmp->getUnitSpeed()>iSpeed)
        {
            iSpeed=tmp->getUnitSpeed();
            fleet->currentUnit=tmp;
        }
        tmp=tmp->next;
    }
    return fleet->currentUnit;
}
Unit *bestCapacityUnit(Fleet *fleet)
{
    if(fleet->getFleetSize()==0)
    {
        return NULL;
    }
    Unit *tmp, *uCapa;
    int iCapa;
    tmp=fleet->firstUnit;
    iCapa=tmp->getUnitCapacity();
    uCapa=tmp;
    while(tmp)
    {
        if(tmp->getUnitCapacity()>iCapa)
        {
            iCapa=tmp->getUnitCapacity();
            uCapa=tmp;
        }
        tmp=tmp->next;
    }
    return uCapa;
}
Unit *bestDefenseUnit(Fleet *fleet)
{
    if(fleet->getFleetSize()==0)
    {
        return NULL;
    }
    Unit *tmp, *uDef;
    int iDef;
    tmp=fleet->firstUnit;
    iDef=tmp->getUnitDefense();
    uDef=tmp;
    while(tmp)
    {
        if(tmp->getUnitDefense()>iDef)
        {
            iDef=tmp->getUnitDefense();
            uDef=tmp;
        }
        tmp=tmp->next;
    }
    return uDef;
}

int FleetManager::changeFormation(Fleet* fleet, Formation* formName)//0 if there is no such a formation, 1 if everything is ok
{
    Formation* tmpForm=fleet->lastFormation;
    if(tmpForm==NULL) return 0;
    for(int i=0; i<fleet->getFleetFormNumb(); i++)
    {
        if(tmpForm==formName)
        {
            fleet->currentFormation=formName;
            return 1;
        }
        tmpForm=tmpForm->prev;
    }
    return 0;
}
int FleetManager::addFormation(Fleet *fleet, std::string formType, int formPower, int formDefense, int formSpeed, int formCapacity)
{
    Formation *newFormation;
    newFormation= new Formation;
    setFormation(newFormation, formType, formPower, formDefense, formSpeed, formCapacity);
    if(fleet->lastFormation==NULL)
    {
        fleet->lastFormation=newFormation;
        return 0;
    }
    newFormation->prev=fleet->lastFormation;
    fleet->lastFormation->next=newFormation;
    fleet->lastFormation=newFormation;
    fleet->setFleetFormNumb(fleet->getFleetFormNumb()+1);
    return 1;
}

int FleetManager::deleteFormation(Fleet *fleet, Formation* delFormation)
{
    Formation* tmpForm;
    tmpForm=fleet->lastFormation;
    if(tmpForm==NULL) return 0;
    for(int i=0; i<fleet->getFleetFormNumb(); i++)
    {
        if(tmpForm==delFormation)
        {
            if(tmpForm==fleet->currentFormation)    fleet->currentFormation=NULL;
            if(tmpForm==fleet->lastFormation && fleet->getFleetFormNumb()==1)
            {
                fleet->setFleetFormNumb(0);
                fleet->lastFormation=NULL;
            }
            else if(tmpForm==fleet->lastFormation)
            {
                fleet->setFleetFormNumb(fleet->getFleetFormNumb()-1);
                fleet->lastFormation=fleet->lastFormation->prev;
            }
            if(tmpForm->next){tmpForm->next->prev=tmpForm->prev;}
            if(tmpForm->prev){tmpForm->prev->next=tmpForm->next;}
            delete tmpForm;
            return 1;
        }
        tmpForm=tmpForm->prev;
    }
    return 0;
}
int FleetManager::addUnit(Fleet *fleet, std::string unitName, int unitSpeed, int unitPower, int unitDefense, int unitCapacity)
{
    Unit* newUnit;
    newUnit=new Unit;
    createUnit(newUnit, unitName, unitPower, unitDefense, unitCapacity, unitSpeed);
    if(fleet->firstUnit==NULL)  {fleet->firstUnit=newUnit;    return 1;}
    fleet->firstUnit->prev=newUnit;
    newUnit->next=fleet->firstUnit;
    fleet->firstUnit=newUnit;
    fleet->setFleetSize(fleet->getFleetSize()+1);
    return 1;
}
int FleetManager::deleteUnit(Fleet *fleet, Unit* delUnit)
{
    Unit* tmpUnit;
    tmpUnit=fleet->firstUnit;
    if(tmpUnit==NULL) return 0;
    for(int i=0; i<fleet->getFleetSize(); i++)
    {
        if(tmpUnit==delUnit)
        {
            if(tmpUnit==fleet->firstUnit&& fleet->getFleetSize()==1)
            {
                fleet->setFleetSize(0); fleet->firstUnit=NULL;
            }
            else if(tmpUnit==fleet->firstUnit)
            {
                fleet->setFleetSize(fleet->getFleetSize()-1);
                fleet->firstUnit=fleet->firstUnit->next;
                fleet->firstUnit->prev=NULL;
            }
            if(tmpUnit->next){tmpUnit->next->prev=tmpUnit->prev;}
            if(tmpUnit->prev){tmpUnit->prev->next=tmpUnit->next;}
            delete tmpUnit;
            return 1;
        }
        tmpUnit=tmpUnit->next;
    }
    return 0;
}
void FleetManager::setFleetSpeed(Fleet *fleet, int speed)
{

    //fleet->fleetSpeed=(bestSpeedUnit(fleet)->unitSpeed/fleet->fleetSize)*fleet->formSpeed;
}
void FleetManager::setFleetPower(Fleet *fleet, int power)
{
    //fleet->fleetPower=(bestPowerUnit(fleet)->unitPower/fleet->fleetSize)*fleet->formPower;
}
void FleetManager::setFleetDefense(Fleet *fleet, int defense)
{
    //fleet->fleetDefense=(bestDefenseUnit(fleet)->unitDefense/fleet->fleetSize)*fleet->formDefense;
}
void FleetManager::setFleetCapacity(Fleet *fleet, int capacity)
{
    //fleet->fleetCapacity=(bestCapacityUnit(fleet)->unitCapacity/fleet->fleetSize)*fleet->formCapacity;
}
void FleetManager::fleetUpdate(Fleet *fleet, int speed, int power, int defense, int capacity)
{
    setFleetSpeed(fleet, speed);
    setFleetPower(fleet, power);
    setFleetDefense(fleet, defense);
    setFleetCapacity(fleet, capacity);
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

void FleetManager::addUnitName(Unit* unit, std::string name)
{
    unit->setUnitName(name);
}
void FleetManager::addUnitPower(Unit* unit, int Power)
{
    unit->setUnitPower(Power);
}
void FleetManager::addUnitDefense(Unit* unit, int Defense)
{
    unit->setUnitDefense(Defense);
}
void FleetManager::addUnitCapacity(Unit* unit, int Capacity)
{
    unit->setUnitCapacity(Capacity);
}
void FleetManager::addUnitSpeed(Unit* unit, int Speed)
{
    unit->setUnitSpeed(Speed);
}
void FleetManager::createUnit(Unit* unit, std::string name, int Power, int Defense, int Capacity, int Speed)
{
    addUnitName(unit, name);
    addUnitPower(unit, Power);
    addUnitDefense(unit, Defense);
    addUnitCapacity(unit, Capacity);
    addUnitSpeed(unit, Speed);
}
/*void FleetManager::Wypisz()
{
    std::cout<<"Unit Name: "<<unitName<<std::endl<<"Power: "<<unitPower<<std::endl<<
    "Speed: "<<unitSpeed<<std::endl<<"Defense: "<<unitDefense<<std::endl<<"Capacity: "<<unitCapacity;
}*/

void FleetManager::setFormType(Formation* form, std::string Name)
{
    form->setFormationName(Name);
}
void FleetManager::setFormPower(Formation* form, int Power)
{
    form->setFormationPower(Power);
}
void FleetManager::setFormDefense(Formation* form, int Defense)
{
    form->setFormationDefense(Defense);
}
void FleetManager::setFormSpeed(Formation* form, int Speed)
{
    form->setFormationSpeed(Speed);
}
void FleetManager::setFormCapacity(Formation* form, int Capacity)
{
    form->setFormationCapacity(Capacity);
}
void FleetManager::setFormation(Formation* form, std::string Name, int Power, int Defense, int Speed, int Capacity)
{
    setFormType(form, Name);
    setFormPower(form, Power);
    setFormDefense(form, Defense);
    setFormSpeed(form, Speed);
    setFormCapacity(form, Capacity);
}
