#ifndef TEST_H
#define TEST_H

#include <iostream>
#include "FleetManager.h"
#include "Unit.h"
#include "Formation.h"
#include "Fleet.h"

class TEST
{
    public:
        TEST();
        ~TEST();
        bool testFormation();
        bool testUnit();
        bool testBestUnit();
        bool testBestForm();
        bool testBestUnitInForm();
    private:
        FleetManager *Man;

};

#endif // TEST_H
