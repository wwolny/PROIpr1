#include "Formation.h"

Formation::Formation()
{
    this->next=NULL;
    this->prev=NULL;
    this->r=0;
    this->w=0;
    this->formType="";
    this->formPower=0;
    this->formDefense=0;
    this->formSpeed=0;
    this->formCapacity=0;
    this->checkStartForm=0;
    this->formWidth=0;
    this->formNowSize=0;
    this->formMaxSize=0;
    this->formArray=new Unit** [Rows];
}
Formation::Formation(int Width)
{
    this->next=NULL;
    this->prev=NULL;
    this->r=0;
    this->w=0;
    this->formType="";
    this->formPower=0;
    this->formDefense=0;
    this->formSpeed=0;
    this->formCapacity=0;
    this->formNowSize=0;
    this->formArray=new Unit** [Rows];
    if(Width>0)
    {
        this->formWidth=Width;
        for (int i=0; i<this->Rows; i++)
        {
            this->formArray[i] = new Unit* [Width];
        }
        this->nullArr();
        this->checkStartForm=1;
        this->formMaxSize=Width*this->Rows;
    }
}

Formation::~Formation()
{
    for(int i=0; i<Rows; i++)
    {
        if(this->getCheckStartForm())
        {
            for(int j=0; j<this->formWidth; j++)
            {
                if(this->formArray[i][j]) delete [] this->formArray[i][j];
            }
        }
        if(this->formArray[i]) delete [] this->formArray[i];
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
    if(this->checkStartForm==1||Width<1) return 0;
    this->formWidth=Width;
    for (int i=0; i<this->Rows; i++)
    {
        this->formArray[i] = new Unit* [Width];
    }
    this->nullArr();
    this->checkStartForm=1;
    this->formMaxSize=this->Rows*Width;
    return 1;
}

void Formation::setFormType(std::string Name)
{
    this->formType=Name;
}
void Formation::setFormPower()
{
    if(this->getFormNowSize()==0) return;
    Unit* tmp;
    int iPow=0;
    tmp=this->getUnitArr(0,0);
    for(int i=0; i<this->getFormRows(); i++)
    {
        for(int j=0; j<this->getFormWidth(); j++)
        {
            tmp=this->getUnitArr(i,j);
            if(tmp) iPow=iPow+tmp->getUnitPower();
        }
    }
    this->formPower=iPow;
}
void Formation::setFormDefense()
{
    if(this->getFormNowSize()==0) return;
    Unit* tmp;
    int iDef=0;
    tmp=this->getUnitArr(0,0);
    for(int i=0; i<this->getFormRows(); i++)
    {
        for(int j=0; j<this->getFormWidth(); j++)
        {
            tmp=this->getUnitArr(i,j);
            if(tmp) iDef+=tmp->getUnitDefense();
        }
    }
    this->formDefense=iDef;
}
void Formation::setFormSpeed()
{
    if(this->getFormNowSize()==0) return;
    Unit* tmp;
    int iSpe=0;
    tmp=this->getUnitArr(0,0);
    for(int i=0; i<this->getFormRows(); i++)
    {
        for(int j=0; j<this->getFormWidth(); j++)
        {
            tmp=this->getUnitArr(i,j);
            if(tmp)  iSpe+=tmp->getUnitSpeed();
        }
    }
    iSpe=(iSpe/(this->getFormNowSize()))+1;
    this->formSpeed=iSpe;
}
void Formation::setFormCapacity()
{
    if(this->getFormNowSize()==0) return;
    Unit* tmp;
    int iCapa=0;
    tmp=this->getUnitArr(0,0);
    for(int i=0; i<this->getFormRows(); i++)
    {
        for(int j=0; j<this->getFormWidth(); j++)
        {
            tmp=this->getUnitArr(i,j);
            if(tmp) iCapa+=tmp->getUnitCapacity();
        }
    }
    this->formCapacity=iCapa;
}
void Formation::setFormation(std::string Name)
{
    setFormType(Name);
    setFormPower();
    setFormDefense();
    setFormSpeed();
    setFormCapacity();
}
void Formation::updateFormation()
{
    setFormPower();
    setFormDefense();
    setFormSpeed();
    setFormCapacity();
}

int Formation::setFormNowSize(int Size)
{
    this->formNowSize=Size;
    return 1;
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

int Formation::updateRW()
{
    for(int i=0; i<this->Rows; i++)
    {
        for(int j=0; j<this->formWidth; j++)
        {
            if(formArray[i][j]==NULL)
            {
                this->r=i;
                this->w=j;
                return 1;
            }
        }
    }
    return 0;
}

void Formation::nullArr()
{
    for(int i=0; i<this->Rows; i++)
    {
        for(int j=0; j<this->formWidth; j++)
        {
            this->formArray[i][j]=NULL;
        }
    }
    this->setFormNowSize(0);
}
int Formation::isUnitInForm(Unit* unit)
{
    for(int i=0; i<this->Rows; i++)
    {
        for(int j=0; j<this->formWidth; j++)
        {
            if(this->formArray[i][j]==unit) return 1;
        }
    }
    return 0;
}
Formation::Formation (const Formation& form)//czy kopiowac tablice
{
    next=NULL;
    prev=NULL;
    r=0;
    w=0;
    formType=form.formType;
    formPower=form.formPower;
    formDefense=form.formDefense;
    formSpeed=form.formSpeed;
    formCapacity=form.formCapacity;
    checkStartForm=0;
    formWidth=0;
    formNowSize=0;
    formMaxSize=0;
    this->formArray=new Unit** [Rows];
}

Formation& Formation::operator=(const Formation *form)
{
    next=NULL;
    prev=NULL;
    r=0;
    w=0;
    formType=form->formType;
    formPower=form->formPower;
    formDefense=form->formDefense;
    formSpeed=form->formSpeed;
    formCapacity=form->formCapacity;
    checkStartForm=0;
    formWidth=0;
    formNowSize=0;
    formMaxSize=0;
    this->formArray=new Unit** [Rows];
    return *this;
}
