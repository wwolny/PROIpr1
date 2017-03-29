#include "Fleet.h"

Fleet::Fleet()
{
    this->firstUnit=NULL;
    this->lastFormation=NULL;
    this->fleetFormNumb=0;
    this->fleetName="";
    this->fleetSize=0;
}

Fleet::~Fleet()
{
    Formation* form;
    Unit* unit;
    while(this->firstUnit)
    {
        unit=this->firstUnit;
        this->firstUnit=this->firstUnit->next;
        delete unit;
    }
    while(this->lastFormation)
    {
        form=this->lastFormation;
        this->lastFormation=this->lastFormation->prev;
        delete form;
    }
}
Fleet::Fleet (const Fleet& fleet)
{
    firstUnit=NULL;
    lastFormation=NULL;
    fleetFormNumb=fleet.fleetFormNumb;
    fleetName=fleet.fleetName;
    fleetSize=fleet.fleetSize;
}
Fleet& Fleet::operator=(const Fleet *fleet)
{
    firstUnit=NULL;
    lastFormation=NULL;
    fleetFormNumb=fleet->fleetFormNumb;
    fleetName=fleet->fleetName;
    fleetSize=fleet->fleetSize;
    return *this;
}
int Fleet::setFleetSize(int Size)
{
    if(Size<0) return 0;
    this->fleetSize=Size;
    return 1;
}

int Fleet::setFleetFormNumb(int FormNumb)
{
    if(FormNumb<0) return 0;
    this->fleetFormNumb=FormNumb;
    return 1;
}
int Fleet::setFleetName(std::string Name)
{
    this->fleetName=Name;
    return 1;
}

void Fleet::nullFormList()
{
    Formation* tmp;
    while(this->lastFormation)
    {
        tmp=this->lastFormation;
        this->lastFormation=this->lastFormation->prev;
        if(tmp) tmp->next=NULL;
    }
    tmp=NULL;
}
