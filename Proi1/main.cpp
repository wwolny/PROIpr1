//regula 3
//testy
//klasa menu //System("clear");
#include <iostream>
#include <cstdlib>
#include "Unit.h"
#include "Formation.h"
#include "Fleet.h"
#include "FleetManager.h"
#include "TEST.h"

void Menu(FleetManager* myFleet);
void formationAsset(FleetManager *myFleet);
void writeUnit(Unit* unit);
void writeForm(Formation* form);
void writeUnitAll(Fleet* fleet);
void writeFormAll(Fleet* fleet);
void writeAllUnitInForm(Formation* form);
int main()
{
    //Formation a, b(5);
    //a.startFormation(5);
    TEST test;
    if(test.testFormation()==1) std::cout<<"HipHipHurrra!"<<std::endl;
    if(test.testUnit()==1) std::cout<<"Tez Dobrze :)!"<<std::endl;
    if(test.testBestUnit()==1) std::cout<<"Jestes Zajebisty!"<<std::endl;
    if(test.testBestForm()==1) std::cout<<"O stary jestes juz tuz tuz!"<<std::endl;
    if(test.testBestUnitInForm()==1) std::cout<<"No i Gratulacje pieknie przeszedles 1% calej drogi, powodzenia dalej!"<<std::endl;
    //FleetManager *myFleet;
    //myFleet=new FleetManager;
    //Menu(myFleet);
    //formationAsset(myFleet);
    return( 0 );
}

void formationAsset(FleetManager *myFleet)
{
    myFleet->createFormation(myFleet->fleet, 5, "Linia");
    myFleet->createUnit(myFleet->fleet, "Fregata", 5, 4, 3, 5);
    myFleet->createUnit(myFleet->fleet, "Fregata1", 5, 4, 3, 5);
    myFleet->createUnit(myFleet->fleet, "Fregata2", 5, 4, 3, 5);
    myFleet->createUnit(myFleet->fleet, "Fregata3", 5, 4, 3, 5);
    writeForm(myFleet->fleet->lastFormation);
    writeUnit(myFleet->fleet->firstUnit);
    myFleet->pushUnitToForm(myFleet->fleet->lastFormation ,myFleet->fleet->firstUnit);
    writeForm(myFleet->fleet->lastFormation);
    writeUnitAll(myFleet->fleet);
    std::string jednostka;
    std::cout<<"Podaj nazwe jednostki ktora dodasz do Formacji: ";
    std::cin>>jednostka;
    myFleet->pushUnitToForm(myFleet->giveForm("Linia"), myFleet->giveUnit(jednostka));
    writeAllUnitInForm(myFleet->giveForm("Linia"));
}
void writeForm(Formation* form)
{
    std::cout<<"Formation name: "<<form->getFormationName()<<std::endl<<"Power: "<<form->getFormationPower()<<"   Defense: ";
    std::cout<<form->getFormationDefense()<<"   Speed: "<<form->getFormationSpeed()<<"   Capacity: "<<form->getFormationCapacity()<<std::endl;
    return;
}
void writeUnit(Unit* unit)
{
    std::cout<<"Unit name: "<<unit->getUnitName()<<std::endl<<"Power: "<<unit->getUnitPower()<<"   Defense: ";
    std::cout<<unit->getUnitDefense()<<"   Speed: "<<unit->getUnitSpeed()<<"   Capacity: "<<unit->getUnitCapacity()<<std::endl;
}
void writeUnitAll(Fleet* fleet)
{
    Unit* tmp;
    tmp=fleet->firstUnit;
    while(tmp)
    {
        writeUnit(tmp);
        tmp=tmp->next;
    }
    return;
}
void writeFormAll(Fleet* fleet)
{
    Formation* tmp;
    tmp=fleet->lastFormation;
    while(tmp)
    {
        writeForm(tmp);
        tmp=tmp->prev;
    }
    return;
}
void writeAllUnitInForm(Formation* form)
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

void Menu(FleetManager* myFleet)
{/*
    int width, pow, spe, def, capa, i=0, j=0;
    std::string name, tmp;
    char Next;
    while(1){
    std::cout<<"[q]create formation"<<std::endl<<"[w]delete formation"<<std::endl<<"[e]create unit"<<std::endl<<"[r]delete unit"<<std::endl<<"[t]best transport foramtion"<<std::endl;
    std::cout<<"    [a]best attack formation"<<std::endl<<"[x] add unit to formation"<<std::endl<<"[c]delete unit from formation"<<std::endl<<"[u]write down all units"<<std::endl;
    std::cout<<"[f] write down all formations"<<std::endl<<"[l] leave menu"<<std::endl;

    std::cin>>Next;
    switch (Next)
    {
        case 'q':
            system("clear");
            std::cout<<"Type width of formation: ";         std::cin>>width;
            std::cout<<"Type name of formation: ";          std::cin>>name;
            myFleet->createFormation(myFleet->fleet, width,name);
            break;
        case 'w':
            writeFormAll(myFleet->fleet);
            std::cout<<"type exactly the same name of one that should be deleted:"; std::cin>>name;
            myFleet->deleteFormation(myFleet->fleet, myFleet->giveForm(name));
            break;
        case 'e':
            std::cout<<"Type name of unit: ";          std::cin>>name;
            std::cout<<"Type speed of unit: ";         std::cin>>spe;
            std::cout<<"Type defense of unit: ";         std::cin>>def;
            std::cout<<"Type power of unit: ";         std::cin>>pow;
            std::cout<<"Type capacity of unit: ";         std::cin>>capa;
            myFleet->createUnit(myFleet->fleet,name,spe, pow, def,capa );
            break;
        case 'r':
            std::cout<<"Type name of unit that should be deleted: ";          std::cin>>name;
            myFleet->deleteUnit(myFleet->fleet, myFleet->giveUnit(name));
            break;
        case 'a':
            writeForm(myFleet->bestPowerForm(myFleet->fleet));
            break;
        case 't':
            writeForm(myFleet->bestCapacityForm(myFleet->fleet));
            break;
        case 'x':
            writeFormAll(myFleet->fleet);
            std::cout<<"Type name of formation: ";          std::cin>>name;
            writeUnitAll(myFleet->fleet);
            std::cout<<"Type name of unit: ";          std::cin>>tmp;
            myFleet->pushUnitToForm(myFleet->giveForm(name), myFleet->giveUnit(tmp));
            i++; j++;
            break;
        case 'c':
            writeFormAll(myFleet->fleet);
            std::cout<<"Type name of formation: ";          std::cin>>name;
            writeUnitAll(myFleet->fleet);
            std::cout<<"Type name of unit: ";          std::cin>>tmp;
            myFleet->pullUnitFromForm(myFleet->giveForm(name), myFleet->giveUnit(tmp));
            break;
        case 'u':
            writeUnitAll(myFleet->fleet);
            break;
        case 'f':
            writeFormAll(myFleet->fleet);
            break;
        case 'l':
            return;
        default:
            std::cout<<"Bad Input!";
            break;
    }
    }*/
}
