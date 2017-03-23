#include "Formation.h"

Formation::Formation()
{
    this->next=NULL;
    this->prev=NULL;
    this->formType="";
    this->formPower=0;
    this->formDefense=0;
    this->formSpeed=0;
    this->formCapacity=0;
    this->checkStartForm=0;
}
Formation::Formation(int Width)
{
    this->next=NULL;
    this->prev=NULL;
    this->formType="";
    this->formPower=0;
    this->formDefense=0;
    this->formSpeed=0;
    this->formCapacity=0;
    this->formArray[Width][Rows];
    this->checkStartForm=1;
    this->formMaxSize=Width*this->Rows;
}
int Formation::operator++()
{
    if(this->formNowSize==this->formMaxSize) return -1;
    this->formNowSize=this->formNowSize+1;
    return this->formNowSize;
}

int Formation::operator--()
{
    if(this->formNowSize==0) return -1;
    this->formNowSize--;
    return this->formNowSize;
}

Formation::~Formation()
{

}

Unit* Formation::getUnitArr(int Width, int Row)
{
    if(Width>this->formWidth||Row>this->Rows) return NULL;
    return *formArray[Width][Row];
}

int Formation::startFormation(int Width)
{
    if(this->checkStartForm==1) return 0;
    this->formArray[Width][Rows];
    this->checkStartForm=1;
    this->formMaxSize=this->Rows*Width;
    return 1;
}

int Formation::setFormationSpeed(int Speed)
{
    if(Speed<0||this->checkStartForm==1) return 0;
    this->formSpeed=Speed;
    return 1;
}
int Formation::setFormationDefense(int Defense)
{
    if(Defense<0||this->checkStartForm==1) return 0;
    this->formDefense=Defense;
    return 1;
}
int Formation::setFormationPower(int Power)
{
    if(Power<0||checkStartForm==1) return 0;
    this->formPower=Power;
    return 1;
}
int Formation::setFormationCapacity(int Capacity)
{
    if(Capacity<0||this->checkStartForm==1) return 0;
    this->formCapacity=Capacity;
    return 1;
}
int Formation::setFormationName(std::string Name)
{
    if(this->checkStartForm==1) return 0;
    this->formType=Name;
    return 1;
}
