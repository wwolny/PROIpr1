#include "MENU.h"

MENU::MENU()
{
    myFleet=new FleetManager;
}

MENU::~MENU()
{
    delete myFleet;
}
void MENU::writeForm(Formation* form)
{
    std::cout<<"Formation name: "<<form->getFormationName()<<std::endl<<"Power: "<<form->getFormationPower()<<"   Defense: ";
    std::cout<<form->getFormationDefense()<<"   Speed: "<<form->getFormationSpeed()<<"   Capacity: "<<form->getFormationCapacity()<<std::endl;
    return;
}
void MENU::writeUnit(Unit* unit)
{
    std::cout<<"Unit name: "<<unit->getUnitName()<<std::endl<<"Power: "<<unit->getUnitPower()<<"   Defense: ";
    std::cout<<unit->getUnitDefense()<<"   Speed: "<<unit->getUnitSpeed()<<"   Capacity: "<<unit->getUnitCapacity()<<std::endl;
}
void MENU::writeUnitAll(Fleet* fleet)
{
    Unit* tmp;
    tmp=fleet->firstUnit;
    while(tmp)
    {
        writeUnit(tmp);
        tmp=tmp->next;
    }
    delete tmp;
    return;
}
void MENU::writeFormAll(Fleet* fleet)
{
    Formation* tmp;
    tmp=fleet->lastFormation;
    while(tmp)
    {
        writeForm(tmp);
        tmp=tmp->prev;
    }
    delete tmp;
    return;
}
void MENU::writeAllUnitInForm(Formation* form)
{
    for(int i=0; i<form->getFormRows(); i++)
    {
        for(int j=0; j<form->getFormWidth(); j++)
        {
            if(form->formArray[i][j]!=NULL) writeUnit(form->formArray[i][j]);
        }
    }
    return;
}
void MENU::options()
{
    std::cout<<"[q] create formation"<<std::endl;
    std::cout<<"[w] delete formation"<<std::endl;
    std::cout<<"[a] create unit"<<std::endl;
    std::cout<<"[s] delete unit"<<std::endl;
    std::cout<<"[z] add unit to formation"<<std::endl;
    std::cout<<"[x] delete unit from formation"<<std::endl;
    std::cout<<"[b] best ones"<<std::endl;
    std::cout<<"[t] write down all units in fleet"<<std::endl;
    std::cout<<"[y] write down all formations in fleet"<<std::endl;
    std::cout<<"[u] write down all units in formation"<<std::endl;
    std::cout<<"[l] leave menu"<<std::endl;
}
void MENU::BestOptions()
{
    std::cout<<"Best unit in fleet:"<<std::endl;
    std::cout<<"[q] in Power"<<std::endl;
    std::cout<<"[w] in Speed"<<std::endl;
    std::cout<<"[e] in Capacity"<<std::endl;
    std::cout<<"[r] in Defense"<<std::endl;
    std::cout<<"Best unit in specific formation:"<<std::endl;
    std::cout<<"[a] in Power"<<std::endl;
    std::cout<<"[s] in Speed"<<std::endl;
    std::cout<<"[d] in Capacity"<<std::endl;
    std::cout<<"[f] in Defense"<<std::endl;
    std::cout<<"Best formation in fleet:"<<std::endl;
    std::cout<<"[z] in Power"<<std::endl;
    std::cout<<"[x] in Speed"<<std::endl;
    std::cout<<"[c] in Capacity"<<std::endl;
    std::cout<<"[v] in Defense"<<std::endl;
    std::cout<<"[l] leave menu"<<std::endl;
}
//--------------------------------------
int MENU::creForm(FleetManager* myFleet)
{
    char c;
    int width=0;
    std::string name="";
    std::cout<<"Type width of formation: ";
    std::cin>>c;
    if(!std::isdigit(c))return this->Fail();
    std::cin.unget();
    std::cin>>width;
    if(!isIntOK()) return this->Fail();
    std::cin.ignore(1000,'\n');
    std::cout<<"Type name of formation: ";
    std::cin>>name;
    std::cin.ignore(1000,'\n');
    if(myFleet->isFormName(name)==0) return this->Fail();
    if(myFleet->createFormation(myFleet->fleet, width ,name)==1) return this->Success();
    else return this->Fail();
}
int MENU::delFor(FleetManager* myFleet)
{
    std::string name;
    writeFormAll(myFleet->fleet);
    std::cout<<"type exactly the name of formation that should be deleted:";
    std::cin>>name;
    std::cin.ignore(1000,'\n');
    if(myFleet->isFormName(name)==1) return this->Fail();
    if(myFleet->deleteFormation(myFleet->fleet, myFleet->giveForm(name))==1) return this->Success();
    else return this->Fail();
}
int MENU::addUnit(FleetManager* myFleet)
{
    char c;
    std::string name="";
    int spe=0, def=0, pow=0, capa=0;
    std::cout<<"Type name of unit: ";
    std::cin>>name;
    std::cin.ignore(1000,'\n');
    if(myFleet->isUnitName(name)==0) return this->Fail();
    std::cout<<"Type speed of unit: ";
    std::cin>>c;
    if(!std::isdigit(c)) return this->Fail();
    std::cin.unget();
    std::cin>>spe;
    if(!isIntOK()) return this->Fail();
    std::cin.ignore(1000,'\n');
    std::cout<<"Type defense of unit: ";
    std::cin>>c;
    if(!std::isdigit(c)) return this->Fail();
    std::cin.unget();
    std::cin>>def;
    if(!isIntOK()) return this->Fail();
    std::cin.ignore(1000,'\n');
    std::cout<<"Type power of unit: ";
    std::cin>>c;
    if(!std::isdigit(c)) return this->Fail();
    std::cin.unget();
    std::cin>>pow;
    if(!isIntOK()) return this->Fail();
    std::cin.ignore(1000,'\n');
    std::cout<<"Type capacity of unit: ";
    std::cin>>c;
    if(!std::isdigit(c)) return this->Fail();
    std::cin.unget();
    std::cin>>capa;
    if(!isIntOK()) return this->Fail();
    std::cin.ignore(1000,'\n');
    if(myFleet->createUnit(myFleet->fleet,name,spe, pow, def,capa )==1)return this->Success();
    else return this->Fail();
}
int MENU::delUnit(FleetManager* myFleet)
{
    std::string name;
    this->writeUnitAll(myFleet->fleet);
    std::cout<<"Type name of unit that should be deleted: ";
    std::cin>>name;
    std::cin.ignore(1000,'\n');
    if(myFleet->isUnitName(name)==1) return this->Fail();
    if(myFleet->deleteUnit(myFleet->fleet, myFleet->giveUnit(name))==1) return this->Success();
    else return this->Fail();
}
int MENU::push(FleetManager* myFleet)
{
    std::string name, tmp;
    writeFormAll(myFleet->fleet);
    std::cout<<"Type name of formation: ";
    std::cin>>name;
    std::cin.ignore(1000,'\n');
    if(myFleet->isFormName(name)==1) return this->Fail();
    writeUnitAll(myFleet->fleet);
    std::cout<<"Type name of unit: ";
    std::cin>>tmp;
    std::cin.ignore(1000,'\n');
    if(myFleet->isUnitName(tmp)==1) return this->Fail();
    if(myFleet->pushUnitToForm(myFleet->giveForm(name), myFleet->giveUnit(tmp))==1) return this->Success();
    else return this->Fail();
}
int MENU::pull(FleetManager* myFleet)
{
    std::string name, tmp;
    writeFormAll(myFleet->fleet);
    std::cout<<"Type name of formation: ";
    std::cin>>name;
    std::cin.ignore(1000,'\n');
    if(myFleet->isFormName(name)==1) return this->Fail();
    this->writeAllUnitInForm(myFleet->giveForm(name));
    std::cout<<"Type name of unit: ";
    std::cin>>tmp;
    std::cin.ignore(1000,'\n');
    if(myFleet->isUnitName(tmp)==1) return this->Fail();
    if(myFleet->pullUnitFromForm(myFleet->giveForm(name), myFleet->giveUnit(tmp))==1) return this->Success();
    else return this->Fail();
}
int MENU::unitInForm(FleetManager* myFleet)
{
    std::string name;
    writeFormAll(myFleet->fleet);
    std::cout<<"Type name of formation: ";
    std::cin>>name;
    std::cin.ignore(1000,'\n');
    if(myFleet->isFormName(name)) return this->Fail();
    this->writeAllUnitInForm(myFleet->giveForm(name));
    return this->Success();
}
//----------------------------------------
void MENU::Menu()
{
    char Next;
    while(1)
    {
        this->options();
        std::cin>>Next;
        std::cin.ignore(1000,'\n');
        system("clear");
        switch (Next)
        {
            case 'q':
                this->creForm(myFleet);
                break;
            case 'w':
                this->delFor(myFleet);
                break;
            case 'a':
                this->addUnit(myFleet);
                break;
            case 's':
                this->delUnit(myFleet);
                break;
            case 'z':
                this->push(myFleet);
                break;
            case 'x':
                this->pull(myFleet);
                break;
            case 't':
                this->writeUnitAll(myFleet->fleet);
                this->getchar();
                break;
            case 'y':
                this->writeFormAll(myFleet->fleet);
                this->getchar();
                break;
            case 'u':
                this->unitInForm(myFleet);
                break;
            case 'b':
                this->BEST(myFleet);
                break;
            case 'l':
                return;
            default:
                std::cout<<"Bad Input!"<<std::endl;
                break;
        }
    }
}
//------------------------------------
int MENU::BEST(FleetManager* myFleet)
{
    char best;
    while(1)
    {
        this->BestOptions();
        std::cin>>best;
        std::cin.ignore(1000,'\n');
        system("clear");
        switch (best)
        {
            case 'q':
                this->unFlPow(myFleet);
                break;
            case 'w':
                this->unFlSpe(myFleet);
                break;
            case 'e':
                this->unFlCapa(myFleet);
                break;
            case 'r':
                this->unFlDef(myFleet);
                break;
            case 'a':
                this->unForPow(myFleet);
                break;
            case 's':
                this->unForSpe(myFleet);
                break;
            case 'd':
                this->unForCapa(myFleet);
                break;
            case 'f':
                this->unForDef(myFleet);
                break;
            case 'z':
                this->forPow(myFleet);
                break;
            case 'x':
                this->forSpe(myFleet);
                break;
            case 'c':
                this->forCapa(myFleet);
                break;
            case 'v':
                this->forDef(myFleet);
                break;
            case 'l':
                return 0;
            default:
                std::cout<<"Bad Input!"<<std::endl;
                break;
        }
    }
    return 1;
}
//---------------
int MENU::unFlCapa(FleetManager* myFleet)
{
    if(myFleet->fleet->getFleetSize()==0) return this->Fail();
    Unit best(*myFleet->bCapaU(myFleet->fleet));
    std::cout<<"The best capacity unit in fleet is: "<<std::endl;
    this->writeUnit(&best);
    return this->Success();
}
int MENU::unFlPow(FleetManager* myFleet)
{
    if(myFleet->fleet->getFleetSize()==0) return this->Fail();
    Unit best(*myFleet->bPowU(myFleet->fleet));
    std::cout<<"The most powerful unit in fleet is: "<<std::endl;
    this->writeUnit(&best);
    return this->Success();
}
int MENU::unFlSpe(FleetManager* myFleet)
{
    if(myFleet->fleet->getFleetSize()==0) return this->Fail();
    Unit best(*myFleet->bSpeU(myFleet->fleet));
    std::cout<<"The fastest unit in fleet is: "<<std::endl;
    this->writeUnit(&best);
    return this->Success();
}
int MENU::unFlDef(FleetManager* myFleet)
{
    if(myFleet->fleet->getFleetSize()==0) return this->Fail();
    Unit best(*myFleet->bDefU(myFleet->fleet));
    std::cout<<"The best capacity unit in fleet is: "<<std::endl;
    this->writeUnit(&best);
    return this->Success();
}
//-------------------
int MENU::unForPow(FleetManager* myFleet)
{
    if(myFleet->fleet->getFleetFormNumb()==0) return this->Fail();
    std::string name;
    writeFormAll(myFleet->fleet);
    std::cout<<"Type name of formation: ";
    std::cin>>name;
    std::cin.ignore(1000,'\n');
    if(myFleet->isFormName(name)==1) return this->Fail();
    Unit best(*myFleet->bPowU(myFleet->giveForm(name)));
    std::cout<<"The most powerful unit in formation: "<<std::endl;
    this->writeUnit(&best);
    return this->Success();
}
int MENU::unForSpe(FleetManager* myFleet)
{
    if(myFleet->fleet->getFleetFormNumb()==0) return this->Fail();
    std::string name;
    writeFormAll(myFleet->fleet);
    std::cout<<"Type name of formation: ";
    std::cin>>name;
    std::cin.ignore(1000,'\n');
    if(myFleet->isFormName(name)==1) return this->Fail();
    Unit best(*myFleet->bSpeU(myFleet->giveForm(name)));
    std::cout<<"The fastest unit in formation: "<<std::endl;
    this->writeUnit(&best);
    return this->Success();
}
int MENU::unForDef(FleetManager* myFleet)
{
    if(myFleet->fleet->getFleetFormNumb()==0) return this->Fail();
    std::string name;
    writeFormAll(myFleet->fleet);
    std::cout<<"Type name of formation: ";
    std::cin>>name;
    std::cin.ignore(1000,'\n');
    if(myFleet->isFormName(name)==1) return this->Fail();
    Unit best(*myFleet->bDefU(myFleet->giveForm(name)));
    std::cout<<"The best defensive unit in formation: "<<std::endl;
    this->writeUnit(&best);
    return this->Success();
}
int MENU::unForCapa(FleetManager* myFleet)
{
    if(myFleet->fleet->getFleetFormNumb()==0) return this->Fail();
    std::string name;
    writeFormAll(myFleet->fleet);
    std::cout<<"Type name of formation: ";
    std::cin>>name;
    std::cin.ignore(1000,'\n');
    if(myFleet->isFormName(name)==1) return this->Fail();
    Unit best(*myFleet->bCapaU(myFleet->giveForm(name)));
    std::cout<<"The best capacity unit in formation: "<<std::endl;
    this->writeUnit(&best);
    return this->Success();
}
//------------------------
int MENU::forPow(FleetManager* myFleet)
{
    if(myFleet->fleet->getFleetFormNumb()==0) return this->Fail();
    Formation best(*myFleet->bPowF(myFleet->fleet));
    std::cout<<"The most powerful formation in fleet: "<<std::endl;
    this->writeForm(&best);
    return this->Success();
}
int MENU::forSpe(FleetManager* myFleet)
{
    if(myFleet->fleet->getFleetFormNumb()==0) return this->Fail();
    Formation best(*myFleet->bSpeF(myFleet->fleet));
    std::cout<<"The fastest formation in fleet: "<<std::endl;
    this->writeForm(&best);
    return this->Success();
}
int MENU::forDef(FleetManager* myFleet)
{
    if(myFleet->fleet->getFleetFormNumb()==0) return this->Fail();
    Formation best(*myFleet->bDefF(myFleet->fleet));
    std::cout<<"The best defensive formation in fleet: "<<std::endl;
    this->writeForm(&best);
    return this->Success();
}
int MENU::forCapa(FleetManager* myFleet)
{
    if(myFleet->fleet->getFleetFormNumb()==0) return this->Fail();
    Formation best(*myFleet->bCapaF(myFleet->fleet));
    std::cout<<"The best capacity formation in fleet: "<<std::endl;
    this->writeForm(&best);
    return this->Success();
}
//----------------
void MENU::getchar()
{
    std::cin.get();
}
int MENU::Success()
{
    std::cout<<"Success!"<<std::endl;
    getchar();
    return 1;
}
int MENU::Fail()
{
    std::cout<<"Fail!"<<std::endl;
    getchar();
    return 0;
}
int MENU::isIntOK()//if fail return 0
{
    if(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        return this->Fail();
    }
    else return 1;
}
