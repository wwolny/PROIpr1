#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Unit.h"
#include "Formation.h"
#include "Fleet.h"
#include "FleetManager.h"
#include "TEST.h"

class MENU
{
    public:
        MENU();
        ~MENU();
        void Menu();
        void writeUnit(Unit* unit);
        void writeForm(Formation* form);
        void writeUnitAll(Fleet* fleet);
        void writeFormAll(Fleet* fleet);
        void writeAllUnitInForm(Formation* form);
        void options();
        void BestOptions();
        int creForm(FleetManager* myFleet);
        int delFor(FleetManager* myFleet);
        int addUnit(FleetManager* myFleet);
        int delUnit(FleetManager* myFleet);
        int push(FleetManager* myFleet);
        int pull(FleetManager* myFleet);
        int unitInForm(FleetManager* myFleet);
        int BEST(FleetManager* myFleet);
        int unFlCapa(FleetManager* myFleet, Formation* Best);
        int unFlPow(FleetManager* myFleet, Formation* Best);
        int unFlDef(FleetManager* myFleet, Formation* Best);
        int unFlSpe(FleetManager* myFleet, Formation* Best);
        int unForPow(FleetManager* myFleet, Formation* Best);
        int unForDef(FleetManager* myFleet, Formation* Best);
        int unForCapa(FleetManager* myFleet, Formation* Best);
        int unForSpe(FleetManager* myFleet, Formation* Best);
        int forPow(FleetManager* myFleet, Fleet* Best);
        int forDef(FleetManager* myFleet, Fleet* Best);
        int forSpe(FleetManager* myFleet, Fleet* Best);
        int forCapa(FleetManager* myFleet, Fleet* Best);
        void getchar();
        int Success();
        int Fail();
        int isIntOK();
    private:
        FleetManager* myFleet;
};

#endif // MENU_H
