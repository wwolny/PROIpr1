#define BOOST_TEST_MODULE Test
#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include "Unit.h"
#include "Formation.h"
#include "Fleet.h"
#include "FleetManager.h"

BOOST_AUTO_TEST_SUITE(Unit)

BOOST_AUTO_TEST_CASE(Test1)
{
	FleetManager *myFleet;
	    
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Union)

BOOST_AUTO_TEST_CASE(Test1)
{
    Node2 n;
    BOOST_CHECK(sizeof(n) == sizeof(double));
}

BOOST_AUTO_TEST_SUITE_END()
