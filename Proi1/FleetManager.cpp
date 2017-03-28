#include "FleetManager.h"

FleetManager::FleetManager()
{
    fleet= new Fleet;
}
FleetManager::~FleetManager()
{
    delete fleet;
}
//-----------------------------------
Unit* FleetManager::bPowU(Fleet *fleet)
{
    if(fleet->getFleetSize()==0){return NULL;}
    Unit *tmp, *best;
    int top;
    tmp=fleet->firstUnit;
    top=tmp->getUnitPower();
    best=tmp;
    while(tmp)
    {
        if(tmp->getUnitPower()>tmp)
        {
            top=tmp->getUnitPower();
            best=tmp;
        }
        tmp=tmp->next;
    }
    Unit theBest(best);
    return theBest;
}
Unit* FleetManager::bSpeU(Fleet *fleet)
{
    if(fleet->getFleetSize()==0){return NULL;}
    Unit *tmp, *best;
    int top;
    tmp=fleet->firstUnit;
    top=tmp->getUnitSpeed();
    best=tmp;
    while(tmp)
    {
        if(tmp->getUnitSpeed()>tmp)
        {
            top=tmp->getUnitSpeed();
            best=tmp;
        }
        tmp=tmp->next;
    }
    Unit theBest(best);
    return theBest;
}
Unit* FleetManager::bDefU(Fleet *fleet)
{
    if(fleet->getFleetSize()==0){return NULL;}
    Unit *tmp, *best;
    int top;
    tmp=fleet->firstUnit;
    top=tmp->getUnitDefense();
    best=tmp;
    while(tmp)
    {
        if(tmp->getUnitDefense()>tmp)
        {
            top=tmp->getUnitDefense();
            best=tmp;
        }
        tmp=tmp->next;
    }
    Unit theBest(best);
    return theBest;
}
Unit* FleetManager::bCapaU(Fleet *fleet)
{
    if(fleet->getFleetSize()==0){return NULL;}
    Unit *tmp, *best;
    int top;
    tmp=fleet->firstUnit;
    top=tmp->getUnitCapacity();
    best=tmp;
    while(tmp)
    {
        if(tmp->getUnitCapacity()>tmp)
        {
            top=tmp->getUnitCapacity();
            best=tmp;
        }
        tmp=tmp->next;
    }
    Unit theBest(best);
    return theBest;
}



/*
//----------------------------------
int FleetManager::bestPowerUnit(Fleet* fleet, Formation* best)
{
    if(fleet->getFleetSize()==0||best->getFormWidth()>0||best->getCheckStartForm()==1){return 0;}
    best->startFormation((fleet->getFleetSize()/5)+1);
    best->nullArr();
    Unit *tmp;
    int top;
    tmp=fleet->firstUnit;
    top=tmp->getUnitPower();
    best->formArray[best->getR()][best->getW()]=tmp;
    best->updateRW();
    best->setFormNowSize(1);
    tmp=tmp->next;
    while(tmp)
    {
        if(tmp->getUnitPower()>top)
        {
            top=tmp->getUnitPower();
            best->nullArr();
            best->updateRW();
            best->formArray[best->getR()][best->getW()]=tmp;
            best->updateRW();
            best->setFormNowSize(1);
        }
        else if(tmp->getUnitPower()==top)
        {
            best->formArray[best->getR()][best->getW()]=tmp;
            best->updateRW();
            best->setFormNowSize(best->getFormNowSize()+1);
        }
        tmp=tmp->next;
    }
    return 1;
}
int FleetManager::bestSpeedUnit(Fleet *fleet, Formation* best)
{
    if(fleet->getFleetSize()==0||best->getFormWidth()>0||best->getCheckStartForm()==1){return 0;}
    best->startFormation((fleet->getFleetSize()/5)+1);
    best->nullArr();
    Unit *tmp;
    int top;
    tmp=fleet->firstUnit;
    top=tmp->getUnitSpeed();
    best->formArray[best->getR()][best->getW()]=tmp;
    best->updateRW();
    best->setFormNowSize(1);
    tmp=tmp->next;
    while(tmp)
    {
        if(tmp->getUnitSpeed()>top)
        {
            top=tmp->getUnitSpeed();
            best->nullArr();
            best->updateRW();
            best->formArray[best->getR()][best->getW()]=tmp;
            best->updateRW();
            best->setFormNowSize(1);
        }
        else if(tmp->getUnitSpeed()==top)
        {
            best->formArray[best->getR()][best->getW()]=tmp;
            best->updateRW();
            best->setFormNowSize(best->getFormNowSize()+1);
        }
        tmp=tmp->next;
    }
    return 1;
}
int FleetManager::bestCapacityUnit(Fleet *fleet, Formation* best)
{
    if(fleet->getFleetSize()==0||best->getFormWidth()>0||best->getCheckStartForm()==1){return 0;}
    best->startFormation((fleet->getFleetSize()/5)+1);
    best->nullArr();
    Unit *tmp;
    int top;
    tmp=fleet->firstUnit;
    top=tmp->getUnitCapacity();






    top=tmp->getUnitCapacity();
    best->formArray[best->getR()][best->getW()]=tmp;
    best->updateRW();
    best->setFormNowSize(1);
    tmp=tmp->next;




    while(tmp)
    {
        if(tmp->getUnitCapacity()>top)
        {
            top=tmp->getUnitCapacity();
            best->nullArr();
            best->updateRW();
            best->formArray[best->getR()][best->getW()]=tmp;
            best->updateRW();
            best->setFormNowSize(1);
        }
        else if(tmp->getUnitCapacity()==top)
        {
            best->formArray[best->getR()][best->getW()]=tmp;
            best->updateRW();
            best->setFormNowSize(best->getFormNowSize()+1);
        }
        tmp=tmp->next;
    }
    return 1;
}
int FleetManager::bestDefenseUnit(Fleet *fleet, Formation* best)
{
    if(fleet->getFleetSize()==0||best->getFormWidth()>0||best->getCheckStartForm()==1){return 0;}
    best->startFormation((fleet->getFleetSize()/5)+1);
    best->nullArr();
    Unit *tmp;
    int top;
    tmp=fleet->firstUnit;
    top=tmp->getUnitDefense();
    best->formArray[best->getR()][best->getW()]=tmp;
    best->updateRW();
    best->setFormNowSize(1);
    tmp=tmp->next;
    while(tmp)
    {
        if(tmp->getUnitDefense()>top)
        {
            top=tmp->getUnitDefense();
            best->nullArr();
            best->updateRW();
            best->formArray[best->getR()][best->getW()]=tmp;
            best->updateRW();
            best->setFormNowSize(1);
        }
        else if(tmp->getUnitDefense()==top)
        {
            best->formArray[best->getR()][best->getW()]=tmp;
            best->updateRW();
            best->setFormNowSize(best->getFormNowSize()+1);
        }
        tmp=tmp->next;
    }
    return 1;
}
//------------------------------------------------
int FleetManager::bestPowerUnit(Formation* Form, Formation* best)
{
    if(Form->getFormNowSize()==0||best->getFormWidth()>0||best->getCheckStartForm()==1){return 0;}
    best->startFormation(Form->getFormMaxSize()+1);
    best->nullArr();
    Unit* tmp;
    int top=0;
    for(int i=0; i<Form->getFormRows(); i++)
    {
        for(int j=0; j<Form->getFormWidth(); j++)
        {
            tmp=Form->getUnitArr(i,j);
            if(tmp)
            {
                if(top<tmp->getUnitPower())
                {
                    top=tmp->getUnitPower();
                    best->nullArr();
                    best->updateRW();
                    best->formArray[best->getR()][best->getW()]=tmp;
                    best->updateRW();
                    best->setFormNowSize(1);
                }
                else if(top==tmp->getUnitPower())
                {
                    best->formArray[best->getR()][best->getW()]=tmp;
                    best->updateRW();
                    best->setFormNowSize(best->getFormNowSize()+1);
                }
            }
        }
    }
    best->updateFormation();
    if(best->getUnitArr(0,0)==NULL) return 0;
    return 1;
}
int FleetManager::bestSpeedUnit(Formation* Form, Formation* best)
{
    if(Form->getFormNowSize()==0||best->getFormWidth()>0||best->getCheckStartForm()==1){return 0;}
    best->startFormation(Form->getFormMaxSize()+1);
    best->nullArr();
    Unit* tmp;
    int top=0;
    for(int i=0; i<Form->getFormRows(); i++)
    {
        for(int j=0; j<Form->getFormWidth(); j++)
        {
            tmp=Form->getUnitArr(i,j);
            if(tmp)
            {
                if(top<tmp->getUnitSpeed())
                {
                    top=tmp->getUnitSpeed();
                    best->nullArr();
                    best->updateRW();
                    best->formArray[best->getR()][best->getW()]=tmp;
                    best->updateRW();
                    best->setFormNowSize(1);
                }
                else if(top==tmp->getUnitSpeed())
                {
                    best->formArray[best->getR()][best->getW()]=tmp;
                    best->updateRW();
                    best->setFormNowSize(best->getFormNowSize()+1);
                }
            }
        }
    }
    best->updateFormation();
    if(best->getUnitArr(0,0)==NULL) return 0;
    return 1;
}
int FleetManager::bestCapacityUnit(Formation* Form, Formation* best)
{
    if(Form->getFormNowSize()==0||best->getFormWidth()>0||best->getCheckStartForm()==1){return 0;}
    best->startFormation(Form->getFormMaxSize()+1);
    best->nullArr();
    Unit* tmp;
    int top=0;
    for(int i=0; i<Form->getFormRows(); i++)
    {
        for(int j=0; j<Form->getFormWidth(); j++)
        {
            tmp=Form->getUnitArr(i,j);
            if(tmp)
            {
                if(top<tmp->getUnitCapacity())
                {
                    top=tmp->getUnitCapacity();
                    best->nullArr();
                    best->updateRW();
                    best->formArray[best->getR()][best->getW()]=tmp;
                    best->updateRW();
                    best->setFormNowSize(1);
                }
                else if(top==tmp->getUnitCapacity())
                {
                    best->formArray[best->getR()][best->getW()]=tmp;
                    best->updateRW();
                    best->setFormNowSize(best->getFormNowSize()+1);
                }
            }
        }
    }
    best->updateFormation();
    if(best->getUnitArr(0,0)==NULL) return 0;
    return 1;
}
int FleetManager::bestDefenseUnit(Formation* Form, Formation* best)
{
    if(Form->getFormNowSize()==0||best->getFormWidth()>0||best->getCheckStartForm()==1){return 0;}
    best->startFormation(Form->getFormMaxSize()+1);
    best->nullArr();
    Unit* tmp;
    int top=0;
    for(int i=0; i<Form->getFormRows(); i++)
    {
        for(int j=0; j<Form->getFormWidth(); j++)
        {
            tmp=Form->getUnitArr(i,j);
            if(tmp)
            {
                if(top<tmp->getUnitDefense())
                {
                    top=tmp->getUnitDefense();
                    best->nullArr();
                    best->updateRW();
                    best->formArray[best->getR()][best->getW()]=tmp;
                    best->updateRW();
                    best->setFormNowSize(1);
                }
                else if(top==tmp->getUnitDefense())
                {
                    best->formArray[best->getR()][best->getW()]=tmp;
                    best->updateRW();
                    best->setFormNowSize(best->getFormNowSize()+1);
                }
            }
        }
    }
    best->updateFormation();
    if(best->getUnitArr(0,0)==NULL) return 0;
    return 1;
}
//-----------------------------------------------------
int FleetManager::bestDefenseForm(Fleet* fleet, Fleet* best)
{
    if(fleet->getFleetFormNumb()==0) return 0;
    Formation* tmp;
    int top;
    tmp=fleet->lastFormation;
    top=tmp->getFormationDefense();
    tmp=tmp->prev;
    while(tmp)
    {
        if(top<tmp->getFormationDefense()) top=tmp->getFormationDefense();
        tmp->tmp->prev;
    }
    tmp=fleet->lastFormation;
    best->lastFormation=NULL;
    while(tmp)
    {
        if(top==tmp->getFormationDefense())
        {
            Formation (*tmp);
            best->lastFormation->next=tmp;
            best->lastFormation=tmp;
            best->lastFormation->prev=tmp->prev;
            best->setFleetFormNumb(best->getFleetFormNumb()+1);
        }
        tmp=tmp->prev;
    }
    return 1;
}
int FleetManager::bestPowerForm(Fleet* fleet, Fleet* best)
{
    if(fleet->getFleetFormNumb()==0) return 0;
    Formation* tmp;
    int top;
    tmp=fleet->lastFormation;
    best->lastFormation=fleet->lastFormation;
    top=best->lastFormation->getFormationPower();
    best->setFleetFormNumb(1);
    tmp=tmp->prev;
    while(tmp)
    {
        if(top<tmp->getFormationPower())
        {
            best->nullFormList();
            best->lastFormation=tmp;
            top=tmp->getFormationPower();
            best->setFleetFormNumb(1);
        }
        else if(top==tmp->getFormationPower())
        {
            best->lastFormation->next=tmp;
            best->lastFormation=tmp;
            best->setFleetFormNumb(best->getFleetFormNumb()+1);
        }
        tmp=tmp->prev;
    }
    return 1;
}
int FleetManager::bestSpeedForm(Fleet* fleet, Fleet* best)
{
    if(fleet->getFleetFormNumb()==0) return 0;
    Formation* tmp;
    int top;
    tmp=fleet->lastFormation;
    best->lastFormation=fleet->lastFormation;
    top=best->lastFormation->getFormationSpeed();
    best->setFleetFormNumb(1);
    tmp=tmp->prev;
    while(tmp)
    {
        if(top<tmp->getFormationSpeed())
        {
            best->nullFormList();
            best->lastFormation=tmp;
            top=tmp->getFormationSpeed();
            best->setFleetFormNumb(1);
        }
        else if(top==tmp->getFormationSpeed())
        {
            best->lastFormation->next=tmp;
            best->lastFormation=tmp;
            best->setFleetFormNumb(best->getFleetFormNumb()+1);
        }
        tmp=tmp->prev;
    }
    return 1;
}
int FleetManager::bestCapacityForm(Fleet* fleet, Fleet* best)
{
    if(fleet->getFleetFormNumb()==0) return 0;
    Formation* tmp;
    int top;
    tmp=fleet->lastFormation;
    best->lastFormation=fleet->lastFormation;
    top=best->lastFormation->getFormationCapacity();
    best->setFleetFormNumb(1);
    tmp=tmp->prev;
    while(tmp)
    {
        if(top<tmp->getFormationCapacity())
        {
            best->nullFormList();
            best->lastFormation=tmp;
            top=tmp->getFormationCapacity();
            best->setFleetFormNumb(1);
        }
        else if(top==tmp->getFormationCapacity())
        {
            best->lastFormation->next=tmp;
            best->lastFormation=tmp;
            best->setFleetFormNumb(best->getFleetFormNumb()+1);
        }
        tmp=tmp->prev;
    }
    return 1;
}*/
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
    form->setFormType(Name);
}
void FleetManager::setFormPower(Formation* form)
{
    form->setFormPower();
}
void FleetManager::setFormDefense(Formation* form)
{
    form->setFormDefense();
}
void FleetManager::setFormSpeed(Formation* form)
{
    form->setFormSpeed();
}
void FleetManager::setFormCapacity(Formation* form)
{
    form->setFormCapacity();
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
    if(this->isUnitInForm(form, unit)==0||unit==NULL)return 0;
    int iWidth=form->getUnitWidth(unit);
    int iRow=form->getUnitRow(unit);
    unit->setInFormation(NULL);
    form->formArray[iRow][iWidth]=NULL;
    this->updateFormation(form);
    form->updateRW();
    return 1;
}
int FleetManager::pushUnitToForm(Formation* form, Unit* unit)
{
    if(form->getFormNowSize()==form->getFormMaxSize()||unit==NULL||this->isUnitInForm(form, unit)==1) return 0;
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
            form->formArray[form->getR()][form->getW()]=unit;
            unit->setInFormation(form);
            form->setFormNowSize(form->getFormNowSize()+1);
            updateFormation(form);
            form->updateRW();
            return 1;
        }
        tmpUnit=tmpUnit->next;
    }
    return 0;
}
//--------------------//If there is unit/form return 0
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
        if(tmp->getFormationName()==name) {return 0;}
        tmp=tmp->prev;
    }
    return 1;
}
int FleetManager::isUnitInForm(Formation* form, Unit* unit)
{
    if(form->isUnitInForm(unit)==1)return 1;
    else return 0;
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
