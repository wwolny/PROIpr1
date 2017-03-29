#include "TEST.h"

TEST::TEST()
{
    Man= new FleetManager;
}

TEST::~TEST()
{
    delete Man;
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
    if(Man->createUnit(Man->fleet, "Ship", 10, 2, 3, 54)==0) return 0;
    if(Man->createUnit(Man->fleet, "WarShip", 12, 33, 43, 2)==0) return 0;
    if(Man->createUnit(Man->fleet, "Tank", 23, 3, 143, 5)==0) return 0;
    if(Man->createUnit(Man->fleet, "Sword", 213, 21, 43, 12)==0) return 0;
    if(Man->createUnit(Man->fleet, "Meatball", 234, 23, 42, 54)==0) return 0;
    if(Man->createUnit(Man->fleet, "Star", 123, 730, 32, 59)==0) return 0;
    if(Man->createUnit(Man->fleet, "Star1", 1123, 73, 23, 523)==0) return 0;
    if(Man->createUnit(Man->fleet, "Star2", 11, 354, 43, 53)==0) return 0;
    if(Man->createUnit(Man->fleet, "Star3", 123, 343, 43, 2435)==0) return 0;
    if(Man->createUnit(Man->fleet, "Star4", 332, 1233, 5, 25)==0) return 0;
    if(Man->createUnit(Man->fleet, "Star5", 142, 1235, 42, 53)==0) return 0;

    if(Man->fleet->getFleetSize()==0) return 0;
    Unit Capa(*Man->bCapaU(Man->fleet));
    if(Capa.getUnitCapacity()!=2435) return 0;

    Unit Pow(*Man->bPowU(Man->fleet));
    if(Pow  .getUnitPower()!=1235) return 0;

    Unit Def(*Man->bDefU(Man->fleet));
    if(Def.getUnitDefense()!=143) return 0;

    Unit Spe(*Man->bSpeU(Man->fleet));
    if(Spe.getUnitSpeed()!=1123) return 0;

    return 1;
}
bool TEST::testBestUnitInForm()
{
    FleetManager *Man;
    Man= new FleetManager;
    if(Man->createFormation(Man->fleet, 5, "Line")==0) return 0;
    if(Man->createUnit(Man->fleet, "Ship", 2, 23, 332, 23)==0) return 0;
    if(Man->createUnit(Man->fleet, "WarShip", 321, 21, 12, 31)==0) return 0;
    if(Man->createUnit(Man->fleet, "Tank", 123, 231, 321, 21)==0) return 0;
    if(Man->createUnit(Man->fleet, "Sword", 21, 321, 31, 21)==0) return 0;
    if(Man->createUnit(Man->fleet, "Meatball", 12, 21, 41, 51)==0) return 0;
    if(Man->createUnit(Man->fleet, "Star", 0, 10, 2, 0)==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Line"), Man->giveUnit("Ship"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Line"), Man->giveUnit("WarShip"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Line"), Man->giveUnit("Tank"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Line"), Man->giveUnit("Sword"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Line"), Man->giveUnit("Meatball"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Line"), Man->giveUnit("Star"))==0) return 0;

    if(Man->fleet->getFleetSize()==0) return 0;
    Unit Pow(*Man->bPowU(Man->giveForm("Line")));
    if(Pow.getUnitPower()!=321) return 0;

    Unit Def(*Man->bDefU(Man->giveForm("Line")));
    if(Def.getUnitDefense()!=332) return 0;

    Unit Spe(*Man->bSpeU(Man->giveForm("Line")));
    if(Spe.getUnitSpeed()!=321) return 0;

    Unit Capa(*Man->bCapaU(Man->giveForm("Line")));
    if(Capa.getUnitCapacity()!=51) return 0;
    return 1;
}
bool TEST::testBestForm()
{
    FleetManager *Man;
    Man= new FleetManager;
    if(Man->createFormation(Man->fleet, 1, "Line")==0) return 0;
    if(Man->createFormation(Man->fleet, 5, "Dragon")==0) return 0;
    if(Man->createFormation(Man->fleet, 3, "Lava")==0) return 0;
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
    if(Man->pushUnitToForm(Man->giveForm("Dragon"), Man->giveUnit("Sword"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Dragon"), Man->giveUnit("Meatball"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Dragon"), Man->giveUnit("Star"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Dragon"), Man->giveUnit("Star2"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Lava"), Man->giveUnit("Star3"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Lava"), Man->giveUnit("Star4"))==0) return 0;
    if(Man->pushUnitToForm(Man->giveForm("Lava"), Man->giveUnit("Star5"))==0) return 0;

    if(Man->fleet->getFleetFormNumb()==0) return 0;
    Formation Spe(*Man->bSpeF(Man->fleet));
    if(Spe.getFormationSpeed()!=396) return 0;

    Formation Pow(*Man->bPowF(Man->fleet));
    if(Pow.getFormationPower()!=2809) return 0;

    Formation Def(*Man->bDefF(Man->fleet));
    if(Def.getFormationDefense()!=160) return 0;

    Formation Capa(*Man->bCapaF(Man->fleet));
    if(Capa.getFormationCapacity()!=2513) return 0;

    return 1;
}
