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
    this->formArray=new Unit** [Rows];
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
    this->formArray=new Unit** [Rows];
    for (int i=0; i<this->Rows; i++)
    {
        this->formArray[i] = new Unit* [Width];
    }
    for(int i=0; i<this->Rows; i++)
    {
        for(int j=0; j<Width; j++)
        {
            this->formArray[i][j]=NULL;
        }
    }
    this->formWidth=Width;
    this->checkStartForm=1;
    this->formMaxSize=Width*this->Rows;
}
Formation Formation::operator++()
{
    if(this->formNowSize==this->formMaxSize) return *this;
    this->formNowSize=this->formNowSize+1;
    return *this;
}

Formation Formation::operator--()
{
    if(this->formNowSize==0) return *this;
    this->formNowSize--;
    return *this;
}

Formation::~Formation()
{
    for(int i=0; i<Rows; i++)
    {
        for(int j=0; j<this->formWidth; j++)
        {
            delete [] this->formArray[i][j];
        }
        delete [] this->formArray[i];
    }
    delete [] formArray;
}

Unit* Formation::getUnitArr(int Width, int Row)
{
    if(Width>this->formWidth||Row>this->Rows) return NULL;
    return formArray[Width][Row];
}

int Formation::startFormation(int Width)
{
    if(this->checkStartForm==1) return 0;
    for (int i=0; i<this->Rows; i++)
    {
        this->formArray[i] = new Unit* [Width];
    }
    for(int i=0; i<this->Rows; i++)
    {
        for(int j=0; j<Width; j++)
        {
            this->formArray[i][j]=NULL;
        }
    }
    this->formWidth=Width;
    this->checkStartForm=1;
    this->formMaxSize=this->Rows*Width;
    return 1;
}

int Formation::setFormationSpeed(int Speed)
{
    if(Speed<0||this->checkStartForm==0) return 0;
    this->formSpeed=Speed;
    return 1;
}
int Formation::setFormationDefense(int Defense)
{
    if(Defense<0||this->checkStartForm==0) return 0;
    this->formDefense=Defense;
    return 1;
}
int Formation::setFormationPower(int Power)
{
    if(Power<0||checkStartForm==0) return 0;
    this->formPower=Power;
    return 1;
}
int Formation::setFormationCapacity(int Capacity)
{
    if(Capacity<0||this->checkStartForm==0) return 0;
    this->formCapacity=Capacity;
    return 1;
}
int Formation::setFormationName(std::string Name)
{
    if(this->checkStartForm==0) return 0;
    this->formType=Name;
    return 1;
}
int Formation::setFormNowSize(int Size)
{
    this->formNowSize=Size;
}

int Formation::getUnitWidth(Unit* unit)
{
    for(int i=0; i<this->getFormRows(); i++)
    {
        for(int j=0; j<getFormWidth(); j++)
        {
            if(this->formArray[i][j]==unit)
            {
                return j;
            }
        }
    }
    return -1;
}
int Formation::getUnitRow(Unit* unit)
{
    for(int i=0; i<this->getFormRows(); i++)
    {
        for(int j=0; j<this->getFormWidth(); j++)
        {
            if(this->formArray[i][j]==unit)
            {
                return i;
            }
        }
    }
    return -1;
}


