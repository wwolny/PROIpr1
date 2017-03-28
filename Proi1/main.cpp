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
    /*
    TEST test;
    if(test.testFormation()==1) std::cout<<"HipHipHurrra!"<<std::endl;
    if(test.testUnit()==1) std::cout<<"Tez Dobrze :)!"<<std::endl;
    if(test.testBestUnit()==1) std::cout<<"Jestes Zajebisty!"<<std::endl;
    if(test.testBestForm()==1) std::cout<<"O stary jestes juz tuz tuz!"<<std::endl;
    if(test.testBestUnitInForm()==1) std::cout<<"No i Gratulacje pieknie przeszedles 1% calej drogi, powodzenia dalej!"<<std::endl;
    */
    MENU menu;
    menu.Menu();
    return( 0 );
}
