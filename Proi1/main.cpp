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
#include "MENU.h"

int main()
{

    TEST test;
    if(test.testFormation()==1) std::cout<<"formation: ok"<<std::endl;
    if(test.testUnit()==1) std::cout<<"units test: ok"<<std::endl;
    if(test.testBestUnit()==1) std::cout<<"Test for the best unit: ok"<<std::endl;
    if(test.testBestForm()==1) std::cout<<"Test for the best formation: ok"<<std::endl;
    if(test.testBestUnitInForm()==1) std::cout<<"Test for the best unit in formation: ok"<<std::endl;

    MENU menu;
    menu.Menu();
    return( 0 );
}
