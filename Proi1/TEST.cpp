#include "TEST.h"

TEST::TEST()
{
    //ctor
}

TEST::~TEST()
{
    //dtor
}

bool TEST::testFormation()
{
    FleetManager *Man;
    Man= new FleetManager;
    if(Man->createFormation(Man->fleet, 5, "Artur")==0) return 0;
    if(Man->createFormation(Man->fleet, 5, "Line")==0) return 0;
    if(Man->createFormation(Man->fleet, 5, "Dok")==0) return 0;
    if(Man->createFormation(Man->fleet, 5, "Elephant")==0) return 0;
    if(Man->createFormation(Man->fleet, 5, "Ostrich")==0) return 0;
    if(Man->deleteFormation(Man->fleet, Man->giveForm("Fish"))==1) return 0;
    if(Man->deleteFormation(Man->fleet, Man->giveForm("Line"))==0) return 0;
    if(Man->deleteFormation(Man->fleet, Man->giveForm("Elephant"))==0) return 0;
    if((Man->isFormName("Ostrich"))==1) return 0;
    if(Man->createFormation(Man->fleet, 5, "Artur")==1) return 0;
    if(Man->isFormName("Artur")==1) return 0;
    return 1;
}
bool TEST::testUnit()
{
    FleetManager *Man;
    Man= new FleetManager;
    if(Man->createUnit(Man->fleet, "Ship", 1, 3, 4, 5)==0) return 0;
    if(Man->createUnit(Man->fleet, "WarShip", 1, 3, 4, 5)==0) return 0;
    if(Man->createUnit(Man->fleet, "Tank", 1, 3, 4, 5)==0) return 0;
    if(Man->createUnit(Man->fleet, "Sword", 1, 3, 4, 5)==0) return 0;
    if(Man->createUnit(Man->fleet, "Meatball", 1, 3, 4, 5)==0) return 0;
    if(Man->createUnit(Man->fleet, "Star", 1, 3, 4, 5)==0) return 0;
    if(Man->createFormation(Man->fleet, 1, "Line")==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Line"), Man->giveUnit("Ship"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Line"), Man->giveUnit("Mistake"))==1) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Line"), Man->giveUnit("WarShip"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Line"), Man->giveUnit("Tank"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Line"), Man->giveUnit("Sword"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Line"), Man->giveUnit("Meatball"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Line"), Man->giveUnit("Star"))==1) return 0;
    if(Man->pullUnitFromForm(Man->giveForm("Line"), Man->giveUnit("Meatball"))==0) return 0;
    if(Man->pullUnitFromForm(Man->giveForm("Line"), Man->giveUnit("Ship"))==0) return 0;
    if(Man->pullUnitFromForm(Man->giveForm("Line"), Man->giveUnit("Mistake"))==1) return 0;
    if(Man->pullUnitFromForm(Man->giveForm("Line"), Man->giveUnit("Star"))==1) return 0;
    return 1;
}
bool TEST::testBestUnit()
{
    FleetManager *Man;
    Man= new FleetManager;
    if(Man->createUnit(Man->fleet, "Ship", 10, 2, 3, 54)==0) return 0;
    if(Man->createUnit(Man->fleet, "WarShip", 12, 33, 43, 2)==0) return 0;
    if(Man->createUnit(Man->fleet, "Tank", 23, 3, 43, 5)==0) return 0;
    if(Man->createUnit(Man->fleet, "Sword", 213, 21, 43, 12)==0) return 0;
    if(Man->createUnit(Man->fleet, "Meatball", 234, 23, 42, 54)==0) return 0;
    if(Man->createUnit(Man->fleet, "Star", 1123, 730, 32, 59)==0) return 0;
    if(Man->createUnit(Man->fleet, "Star1", 1123, 73, 23, 523)==0) return 0;
    if(Man->createUnit(Man->fleet, "Star2", 11, 354, 43, 53)==0) return 0;
    if(Man->createUnit(Man->fleet, "Star3", 123, 343, 43, 2435)==0) return 0;
    if(Man->createUnit(Man->fleet, "Star4", 332, 1233, 5, 25)==0) return 0;
    if(Man->createUnit(Man->fleet, "Star5", 142, 1233, 42, 53)==0) return 0;
    Formation *Capa;
    Capa=new Formation;
    if(Man->bestCapacityUnit(Man->fleet, Capa)==0) return 0;
    std::cout<<"Capa Unit Max size: "<<Capa->getFormMaxSize()<<", Current size: "<<Capa->getFormNowSize()<<std::endl;
    Formation *Speed;
    Speed=new Formation;
    if(Man->bestSpeedUnit(Man->fleet, Speed)==0) return 0;
    std::cout<<"Speed Unit Max size: "<<Speed->getFormMaxSize()<<", Current size: "<<Speed->getFormNowSize()<<std::endl;
    Formation *Def;
    Def=new Formation;
    if(Man->bestDefenseUnit(Man->fleet, Def)==0) return 0;
    std::cout<<"Defense Unit Max size: "<<Def->getFormMaxSize()<<", Current size: "<<Def->getFormNowSize()<<std::endl;
    Formation *Pow;
    Pow=new Formation;
    if(Man->bestPowerUnit(Man->fleet, Pow)==0) return 0;
    std::cout<<"Power Unit Max size: "<<Pow->getFormMaxSize()<<", Current size: "<<Pow->getFormNowSize()<<std::endl;
    return 1;
}
bool TEST::testBestForm()
{
    FleetManager *Man;
    Man= new FleetManager;
    if(Man->createFormation(Man->fleet, 5, "Artur")==0) return 0;
    if(Man->createFormation(Man->fleet, 5, "Line")==0) return 0;
    if(Man->createFormation(Man->fleet, 5, "Dok")==0) return 0;
    if(Man->createFormation(Man->fleet, 5, "Elephant")==0) return 0;
    if(Man->createFormation(Man->fleet, 5, "Ostrich")==0) return 0;
    if(Man->createUnit(Man->fleet, "Ship", 1, 1, 1, 1)==0) return 0;
    if(Man->createUnit(Man->fleet, "WarShip", 1, 1, 1, 1)==0) return 0;
    if(Man->createUnit(Man->fleet, "Tank", 1, 1, 1, 1)==0) return 0;
    if(Man->createUnit(Man->fleet, "Sword", 1, 1, 1, 1)==0) return 0;
    if(Man->createUnit(Man->fleet, "Meatball", 1, 1, 1, 1)==0) return 0;
    if(Man->createUnit(Man->fleet, "Star", 0, 0, 0, 0)==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Line"), Man->giveUnit("Ship"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Artur"), Man->giveUnit("WarShip"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Dok"), Man->giveUnit("Tank"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Ostrich"), Man->giveUnit("Sword"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Elephant"), Man->giveUnit("Meatball"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Artur"), Man->giveUnit("Star"))==0) return 0;
    Fleet* Pow;
    Pow=new Fleet;
    if(Man->bestPowerForm(Man->fleet, Pow)==0) return 0;
    std::cout<<"Power Formation Current size: "<<Pow->getFleetFormNumb()<<std::endl;
    Fleet* Spe;
    Spe=new Fleet;
    if(Man->bestSpeedForm(Man->fleet, Spe)==0) return 0;
    std::cout<<"Speed Formation Current size: "<<Spe->getFleetFormNumb()<<std::endl;
    Fleet* Def;
    Def=new Fleet;
    if(Man->bestDefenseForm(Man->fleet, Def)==0) return 0;
    std::cout<<"Defense Formation Current size: "<<Def->getFleetFormNumb()<<std::endl;
    Fleet* Cap;
    Cap=new Fleet;
    if(Man->bestCapacityForm(Man->fleet, Cap)==0) return 0;
    std::cout<<"Capacity Formation Current size: "<<Cap->getFleetFormNumb()<<std::endl;
    return 1;
}
bool TEST::testBestUnitInForm()
{
    FleetManager *Man;
    Man= new FleetManager;
    if(Man->createFormation(Man->fleet, 5, "Line")==0) return 0;
    if(Man->createUnit(Man->fleet, "Ship", 10, 2, 3, 54)==0) return 0;
    if(Man->createUnit(Man->fleet, "WarShip", 12, 33, 43, 2)==0) return 0;
    if(Man->createUnit(Man->fleet, "Tank", 23, 3, 43, 5)==0) return 0;
    if(Man->createUnit(Man->fleet, "Sword", 213, 21, 43, 12)==0) return 0;
    if(Man->createUnit(Man->fleet, "Meatball", 234, 23, 42, 54)==0) return 0;
    if(Man->createUnit(Man->fleet, "Star", 1123, 730, 32, 59)==0) return 0;
    if(Man->createUnit(Man->fleet, "Star1", 1123, 73, 23, 523)==0) return 0;
    if(Man->createUnit(Man->fleet, "Star2", 11, 354, 43, 53)==0) return 0;
    if(Man->createUnit(Man->fleet, "Star3", 123, 343, 43, 2435)==0) return 0;
    if(Man->createUnit(Man->fleet, "Star4", 332, 1233, 5, 25)==0) return 0;
    if(Man->createUnit(Man->fleet, "Star5", 142, 1233, 42, 53)==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Line"), Man->giveUnit("Ship"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Line"), Man->giveUnit("Star1"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Line"), Man->giveUnit("WarShip"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Line"), Man->giveUnit("Tank"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Line"), Man->giveUnit("Sword"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Line"), Man->giveUnit("Meatball"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Line"), Man->giveUnit("Star"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Line"), Man->giveUnit("Star2"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Line"), Man->giveUnit("Star3"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Line"), Man->giveUnit("Star4"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Line"), Man->giveUnit("Star5"))==0) return 0;
    Formation *Pow;
    Pow=new Formation;
    if(Man->bestPowerUnit(Man->giveForm("Line"), Pow)==0) return 0;
    std::cout<<"Power of Line formation: "<<Pow->getFormationPower()<<std::endl;
    Formation *Def;
    Def=new Formation;
    if(Man->bestDefenseUnit(Man->giveForm("Line"), Def)==0) return 0;
    std::cout<<"Defense of Line formation: "<<Def->getFormationPower()<<std::endl;
    Formation *Spe;
    Spe=new Formation;
    if(Man->bestSpeedUnit(Man->giveForm("Line"), Spe)==0) return 0;
    std::cout<<"Speed of Line formation: "<<Spe->getFormationPower()<<std::endl;
    Formation *Capa;
    Capa=new Formation;
    if(Man->bestPowerUnit(Man->giveForm("Line"), Capa)==0) return 0;
    std::cout<<"Capacity of Line formation: "<<Capa->getFormationPower()<<std::endl;
    return 1;
}
