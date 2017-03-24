#include "FleetManager.h"

FleetManager::FleetManager()
{
    fleet= new Fleet;
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
//---------------------------------
Unit* FleetManager::bestPowerUnit(Fleet *fleet)
{
    if(fleet->getFleetSize()==0){return NULL;}
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
Unit* FleetManager::bestSpeedUnit(Fleet *fleet)
{
    if(fleet->getFleetSize()==0)    {return NULL;}
    Unit *tmp, *uSpeed;
    int iSpeed;
    tmp=fleet->firstUnit;
    iSpeed=tmp->getUnitSpeed();
    uSpeed=tmp;
    while(tmp)
    {
        if(tmp->getUnitSpeed()>iSpeed)
        {
            iSpeed=tmp->getUnitSpeed();
            uSpeed=tmp;
        }
        tmp=tmp->next;
    }
    return uSpeed;
}
Unit* FleetManager::bestCapacityUnit(Fleet *fleet)
{
    if(fleet->getFleetSize()==0){return NULL;}
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
Unit* FleetManager::bestDefenseUnit(Fleet *fleet)
{
    if(fleet->getFleetSize()==0){return NULL;}
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
//--------------------------------------------------
Unit* FleetManager::bestPowerUnit(Formation* Form)
{
    Unit* tmp, * uPow;
    int iPow;
    tmp=Form->getUnitArr(0,0);
    uPow=Form->getUnitArr(0,0);
    iPow=Form->getUnitArr(0,0)->getUnitPower();
    for(int i=0; i<Form->getFormRows(); i++)
    {
        for(int j=0; j<Form->getFormWidth(); j++)
        {
            tmp=Form->getUnitArr(j,i);
            if(iPow<tmp->getUnitPower())
            {
                uPow=tmp;
                iPow=uPow->getUnitPower();
            }
        }
    }
    return uPow;
}
Unit* FleetManager::bestSpeedUnit(Formation* Form)
{
    Unit* tmp, * uSpe;
    int iSpe;
    tmp=Form->getUnitArr(0,0);
    uSpe=Form->getUnitArr(0,0);
    iSpe=Form->getUnitArr(0,0)->getUnitSpeed();
    for(int i=0; i<Form->getFormRows(); i++)
    {
        for(int j=0; j<Form->getFormWidth(); j++)
        {
            tmp=Form->getUnitArr(j,i);
            if(iSpe<tmp->getUnitSpeed())
            {
                uSpe=tmp;
                iSpe=uSpe->getUnitSpeed();
            }
        }
    }
    return uSpe;
}
Unit* FleetManager::bestCapacityUnit(Formation* Form)
{
    Unit* tmp, * uCapa;
    int iCapa;
    tmp=Form->getUnitArr(0,0);
    uCapa=Form->getUnitArr(0,0);
    iCapa=Form->getUnitArr(0,0)->getUnitCapacity();
    for(int i=0; i<Form->getFormRows(); i++)
    {
        for(int j=0; j<Form->getFormWidth(); j++)
        {
            tmp=Form->getUnitArr(j,i);
            if(iCapa<tmp->getUnitCapacity())
            {
                uCapa=tmp;
                iCapa=uCapa->getUnitCapacity();
            }
        }
    }
    return uCapa;
}
Unit* FleetManager::bestDefenseUnit(Formation* Form)
{
    Unit* tmp, * uDef;
    int iDef;
    tmp=Form->getUnitArr(0,0);
    uDef=Form->getUnitArr(0,0);
    iDef=Form->getUnitArr(0,0)->getUnitDefense();
    for(int i=0; i<Form->getFormRows(); i++)
    {
        for(int j=0; j<Form->getFormWidth(); j++)
        {
            tmp=Form->getUnitArr(j,i);
            if(iDef<tmp->getUnitDefense())
            {
                uDef=tmp;
                iDef=uDef->getUnitDefense();
            }
        }
    }
    return uDef;
}
//-----------------------------------------------------
Formation* FleetManager::bestDefenseForm(Fleet* fleet)
{
    if(fleet->getFleetFormNumb()==0) return NULL;
    Formation* tmp, * fDef;
    int iDef;
    tmp=fleet->lastFormation;
    fDef=fleet->lastFormation;
    iDef=fDef->getFormationDefense();
    while(tmp)
    {
        if(iDef<tmp->getFormationDefense())
        {
            fDef=tmp;
            iDef=fDef->getFormationDefense();
        }
        tmp=tmp->prev;
    }
    return fDef;
}
Formation* FleetManager::bestPowerForm(Fleet* fleet)
{
    if(fleet->getFleetFormNumb()==0) return NULL;
    Formation* tmp, * fPow;
    int iPow;
    tmp=fleet->lastFormation;
    fPow=fleet->lastFormation;
    iPow=fPow->getFormationPower();
    while(tmp)
    {
        if(iPow<tmp->getFormationPower())
        {
            fPow=tmp;
            iPow=fPow->getFormationPower();
        }
        tmp=tmp->prev;
    }
    return fPow;
}
Formation* FleetManager::bestSpeedForm(Fleet* fleet)
{
    if(fleet->getFleetFormNumb()==0) return NULL;
    Formation* tmp, * fSpe;
    int iSpe;
    tmp=fleet->lastFormation;
    fSpe=fleet->lastFormation;
    iSpe=fSpe->getFormationSpeed();
    while(tmp)
    {
        if(iSpe<tmp->getFormationSpeed())
        {
            fSpe=tmp;
            iSpe=fSpe->getFormationSpeed();
        }
        tmp=tmp->prev;
    }
    return fSpe;
}
Formation* FleetManager::bestCapacityForm(Fleet* fleet)
{
    if(fleet->getFleetFormNumb()==0) return NULL;
    Formation* tmp, * fCapa;
    int iCapa;
    tmp=fleet->lastFormation;
    fCapa=fleet->lastFormation;
    iCapa=fCapa->getFormationCapacity();
    while(tmp)
    {
        if(iCapa<tmp->getFormationCapacity())
        {
            fCapa=tmp;
            iCapa=fCapa->getFormationCapacity();
        }
        tmp=tmp->prev;
    }
    return fCapa;
}
//--------------------------------------------------
int FleetManager::createFormation(Fleet *fleet, int Width, std::string formType)
{
    if(isFormName(formType)==0)return 0;
    Formation *newFormation;
    newFormation= new Formation(Width);
    setFormation(newFormation, formType);
    if(fleet->lastFormation==NULL)
    {
        fleet->lastFormation=newFormation;
        fleet->setFleetFormNumb(fleet->getFleetFormNumb()+1);
        return 1;
    }
    newFormation->prev=fleet->lastFormation;
    fleet->lastFormation->next=newFormation;
    fleet->lastFormation=newFormation;
    fleet->setFleetFormNumb(fleet->getFleetFormNumb()+1);
    return 1;
}
int FleetManager::deleteFormation(Fleet *fleet, Formation* delFormation)
{
    if(delFormation==NULL) return 0;
    Formation* tmpForm;
    tmpForm=fleet->lastFormation;
    if(tmpForm==NULL) return 0;
    for(int i=0; i<fleet->getFleetFormNumb(); i++)
    {
        if(tmpForm==delFormation)
        {
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
//-------------------------
int FleetManager::createUnit(Fleet *fleet, std::string unitName, int unitSpeed, int unitPower, int unitDefense, int unitCapacity)
{
    if(isUnitName(unitName)==0) return 0;
    Unit* newUnit;
    newUnit=new Unit;
    setUnit(newUnit, unitName, unitPower, unitDefense, unitCapacity, unitSpeed);
    if(fleet->firstUnit==NULL)
    {
        fleet->firstUnit=newUnit;
        fleet->setFleetSize(fleet->getFleetSize()+1);
        return 1;
    }
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
            if(tmpUnit->getInFormation()!=NULL) pullUnitFromForm(tmpUnit->getInFormation(), tmpUnit);
            delete tmpUnit;
            return 1;
        }
        tmpUnit=tmpUnit->next;
    }
    return 0;
}
//----------------------------
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
void FleetManager::setUnit(Unit* unit, std::string name, int Power, int Defense, int Capacity, int Speed)
{
    addUnitName(unit, name);
    addUnitPower(unit, Power);
    addUnitDefense(unit, Defense);
    addUnitCapacity(unit, Capacity);
    addUnitSpeed(unit, Speed);
}
//---------------------------
void FleetManager::setFormType(Formation* form, std::string Name)
{
    form->setFormationName(Name);
}
void FleetManager::setFormPower(Formation* form)
{
    if(form->getFormNowSize()==0) return;
    Unit* tmp;
    int iPow=0;
    tmp=form->getUnitArr(0,0);
    for(int i=0; i<form->getFormRows(); i++)
    {
        for(int j=0; j<form->getFormWidth(); j++)
        {
            tmp=form->getUnitArr(i,j);
            if(tmp) iPow=iPow+tmp->getUnitPower();
        }
    }
    form->setFormationPower(iPow);
}
void FleetManager::setFormDefense(Formation* form)
{
    if(form->getFormNowSize()==0) return;
    Unit* tmp;
    int iDef=0;
    tmp=form->getUnitArr(0,0);
    for(int i=0; i<form->getFormRows(); i++)
    {
        for(int j=0; j<form->getFormWidth(); j++)
        {
            tmp=form->getUnitArr(j,i);
            if(tmp) iDef+=tmp->getUnitDefense();
        }
    }
    form->setFormationDefense(iDef);
}
void FleetManager::setFormSpeed(Formation* form)
{
    if(form->getFormNowSize()==0) return;
    Unit* tmp;
    int iSpe=0;
    tmp=form->getUnitArr(0,0);
    for(int i=0; i<form->getFormRows(); i++)
    {
        for(int j=0; j<form->getFormWidth(); j++)
        {
            tmp=form->getUnitArr(j,i);
            if(tmp)  iSpe+=tmp->getUnitSpeed();
        }
    }
    iSpe=iSpe/(form->getFormNowSize());
    form->setFormationSpeed(iSpe);
}
void FleetManager::setFormCapacity(Formation* form)
{
    if(form->getFormNowSize()==0) return;
    Unit* tmp;
    int iCapa=0;
    tmp=form->getUnitArr(0,0);
    for(int i=0; i<form->getFormRows(); i++)
    {
        for(int j=0; j<form->getFormWidth(); j++)
        {
            tmp=form->getUnitArr(j,i);
            if(tmp) iCapa+=tmp->getUnitCapacity();
        }
    }
    form->setFormationCapacity(iCapa);
}
void FleetManager::setFormation(Formation* form, std::string Name)
{
    setFormType(form, Name);
    setFormPower(form);
    setFormDefense(form);
    setFormSpeed(form);
    setFormCapacity(form);
}
void FleetManager::updateFormation(Formation* form)
{
    setFormPower(form);
    setFormDefense(form);
    setFormSpeed(form);
    setFormCapacity(form);
}
//------------------
int FleetManager::pullUnitFromForm(Formation* form, Unit* unit)
{
    int iWidth=form->getUnitWidth(unit);
    int iRow=form->getUnitRow(unit);
    if(iRow<0 || iWidth<0)
    {
        return 0;
    }
    unit->setInFormation(NULL);
    form->formArray[iRow][iWidth]=NULL;
    updateFormation(form);
    return 1;
}
int FleetManager::pushUnitToForm(Formation* form, Unit* unit, int Width, int Row)
{
    if(Width>form->getFormWidth()||Row>form->getFormRows()||form->getFormNowSize()==form->getFormMaxSize()) return 0;
    Unit* tmpUnit;
    tmpUnit=fleet->firstUnit;
    if(tmpUnit==NULL) return 0;
    for(int i=0; i<fleet->getFleetSize(); i++)
    {
        if(tmpUnit==unit)
        {
            if(tmpUnit->getInFormation()!=NULL)
            {
                pullUnitFromForm(tmpUnit->getInFormation(), unit);
            }
            if(form->formArray[Row][Width]!=NULL)
            {
                pullUnitFromForm(form, form->formArray[Row][Width]);
            }
            form->formArray[Row][Width]=unit;
            unit->setInFormation(form);
            form->setFormNowSize(form->getFormNowSize()+1);
            updateFormation(form);
            return 1;
        }
    }
    return 0;
}
//--------------------
int FleetManager::isUnitName(std::string name)
{
    Unit* tmp;
    tmp=fleet->firstUnit;
    while(tmp)
    {
        if(tmp->getUnitName()==name) return 0;
        tmp=tmp->next;
    }
    return 1;
}
int FleetManager::isFormName(std::string name)
{
    Formation* tmp;
    tmp=fleet->lastFormation;
    while(tmp)
    {
        if(tmp->getFormationName()==name) return 0;
        tmp=tmp->prev;
    }
    return 1;
}
//------------------------------
class Formation* FleetManager::giveForm(std::string name)
{
    Formation* tmp;
    tmp=fleet->lastFormation;
    while(tmp)
    {
        if(tmp->getFormationName()==name) return tmp;
        tmp=tmp->prev;
    }
    return NULL;
}
class Unit* FleetManager::giveUnit(std::string name)
{
    Unit* tmp;
    tmp=fleet->firstUnit;
    while(tmp)
    {
        if(tmp->getUnitName()==name) return tmp;
        tmp=tmp->next;
    }
    return NULL;
}
//-------------
