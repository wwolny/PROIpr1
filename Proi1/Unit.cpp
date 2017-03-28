#include "Unit.h"

Unit::Unit()
{
    this->next=NULL;
    this->prev=NULL;
    this->unitName="";
    this->unitSpeed=0;
    this->unitPower=0;
    this->unitDefense=0;
    this->unitCapacity=0;
    this->inFormation=NULL;
}
void Unit::setInFormation(Formation* form)
{
    this->inFormation=form;
}

int Unit::setUnitSpeed(int Speed)
{
    if(Speed<0) return 0;
    this->unitSpeed=Speed;
    return 1;
}
int Unit::setUnitDefense(int Defense)
{
    if(Defense<0) return 0;
    this->unitDefense=Defense;
    return 1;
}
int Unit::setUnitPower(int Power)
{
    if(Power<0) return 0;
    this->unitPower=Power;
    return 1;
}
int Unit::setUnitCapacity(int Capacity)
{
    if(Capacity<0) return 0;
    this->unitCapacity=Capacity;
    return 1;
}
int Unit::setUnitName(std::string Name)
{
    this->unitName=Name;
    return 1;
}

Unit::~Unit()
{
    delete this->next;
    delete this->prev;
}
