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
        if(tmp->getUnitPower()>top)
        {
            top=tmp->getUnitPower();
            best=tmp;
        }
        tmp=tmp->next;
    }
    return best;
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
        if(tmp->getUnitSpeed()>top)
        {
            top=tmp->getUnitSpeed();
            best=tmp;
        }
        tmp=tmp->next;
    }
    return best;
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
        if(tmp->getUnitDefense()>top)
        {
            top=tmp->getUnitDefense();
            best=tmp;
        }
        tmp=tmp->next;
    }
    return best;
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
        if(tmp->getUnitCapacity()>top)
        {
            top=tmp->getUnitCapacity();
            best=tmp;
        }
        tmp=tmp->next;
    }
    return best;
}
//----------------------------------------
Unit* FleetManager::bPowU(Formation* Form)
{
    Unit* tmp, * best;
    best=NULL;
    int top=-1;
    tmp=Form->getUnitArr(0,0);
    if(tmp)
    {
        best=Form->getUnitArr(0,0);
        top=best->getUnitPower();
    }
    for(int i=0; i<Form->getFormRows(); i++)
    {
        for(int j=0; j<Form->getFormWidth(); j++)
        {
            tmp=Form->getUnitArr(i,j);
            if(tmp)
            {
                if(top<tmp->getUnitPower())
                {
                    best=tmp;
                    top=best->getUnitPower();
                }
            }
        }
    }
    return best;
}
Unit* FleetManager::bSpeU(Formation* Form)
{
    Unit* tmp, * best;
    best=NULL;
    int top=-1;
    tmp=Form->getUnitArr(0,0);
    if(tmp)
    {
        best=Form->getUnitArr(0,0);
        top=best->getUnitSpeed();
    }
    for(int i=0; i<Form->getFormRows(); i++)
    {
        for(int j=0; j<Form->getFormWidth(); j++)
        {
            tmp=Form->getUnitArr(i,j);
            if(tmp)
            {
                if(top<tmp->getUnitSpeed())
                {
                    best=tmp;
                    top=best->getUnitSpeed();
                }
            }
        }
    }
    return best;
}
Unit* FleetManager::bDefU(Formation* Form)
{
    Unit* tmp, * best;
    best=NULL;
    int top=-1;
    tmp=Form->getUnitArr(0,0);
    if(tmp)
    {
        best=Form->getUnitArr(0,0);
        top=best->getUnitDefense();
    }
    for(int i=0; i<Form->getFormRows(); i++)
    {
        for(int j=0; j<Form->getFormWidth(); j++)
        {
            tmp=Form->getUnitArr(i,j);
            if(tmp)
            {
                if(top<tmp->getUnitDefense())
                {
                    best=tmp;
                    top=best->getUnitDefense();
                }
            }
        }
    }
    return best;
}
Unit* FleetManager::bCapaU(Formation* Form)
{
    Unit* tmp, * best;
    best=NULL;
    int top=-1;
    tmp=Form->getUnitArr(0,0);
    if(tmp)
    {
        best=Form->getUnitArr(0,0);
        top=best->getUnitCapacity();
    }
    for(int i=0; i<Form->getFormRows(); i++)
    {
        for(int j=0; j<Form->getFormWidth(); j++)
        {
            tmp=Form->getUnitArr(i,j);
            if(tmp)
            {
                if(top<tmp->getUnitCapacity())
                {
                    best=tmp;
                    top=best->getUnitCapacity();
                }
            }
        }
    }
    return best;
}
//------------------------
Formation* FleetManager::bPowF(Fleet* fleet)
{
    if(fleet->getFleetFormNumb()==0) return NULL;
    Formation* tmp, * best;
    best=NULL;
    int top=-1;
    tmp=fleet->lastFormation;
    if(tmp)
    {
        best=fleet->lastFormation;
        top=best->getFormationPower();
    }
    while(tmp)
    {
        if(top<tmp->getFormationPower())
        {
            best=tmp;
            top=best->getFormationPower();
        }
        tmp=tmp->prev;
    }
    return best;
}
Formation* FleetManager::bSpeF(Fleet* fleet)
{
    if(fleet->getFleetFormNumb()==0) return NULL;
    Formation* tmp, * best;
    int top;
    tmp=fleet->lastFormation;
    best=fleet->lastFormation;
    top=best->getFormationSpeed();
    while(tmp)
    {
        if(top<tmp->getFormationSpeed())
        {
            best=tmp;
            top=best->getFormationSpeed();
        }
        tmp=tmp->prev;
    }
    return best;
}
Formation* FleetManager::bDefF(Fleet* fleet)
{
    if(fleet->getFleetFormNumb()==0) return NULL;
    Formation* tmp, * best;
    int top;
    tmp=fleet->lastFormation;
    best=fleet->lastFormation;
    top=best->getFormationDefense();
    while(tmp)
    {
        if(top<tmp->getFormationDefense())
        {
            best=tmp;
            top=best->getFormationDefense();
        }
        tmp=tmp->prev;
    }
    return best;
}
Formation* FleetManager::bCapaF(Fleet* fleet)
{
    if(fleet->getFleetFormNumb()==0) return NULL;
    Formation* tmp, * best;
    int top;
    tmp=fleet->lastFormation;
    best=fleet->lastFormation;
    top=best->getFormationCapacity();
    while(tmp)
    {
        if(top<tmp->getFormationCapacity())
        {
            best=tmp;
            top=best->getFormationCapacity();
        }
        tmp=tmp->prev;
    }
    return best;
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
        fleet->setFleetSize(1);
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
                if(fleet->firstUnit)    fleet->firstUnit->prev=NULL;
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
