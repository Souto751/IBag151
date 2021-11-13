#include "..\lib\googletest\googletest\include\gtest\gtest.h"
#include "..\include\Drone.hpp"
#include "..\include\Package.hpp"
#include <iostream>
#include <string>

TEST(Engine, On)
{
    Drone IBag151;

    IBag151.engineOn();

    EXPECT_TRUE("on" == IBag151.getEngineStatus());

}

TEST(Engine, Off)
{
    Drone IBag151;

    IBag151.engineOff();

    EXPECT_TRUE("off" == IBag151.getEngineStatus());
}

TEST(Pack, DeliverPackage)
{
    Drone IBag151;
    Package* pack;
    Package* nullPackage = NULL;

    IBag151.deliverPackage();

    pack = IBag151.getPackageInfo();

    EXPECT_EQ(pack, nullPackage);
}

TEST(Pack, ChargePackage)
{
    Drone IBag151;
    Package testPackage;
    Package* nullPackage = NULL;

    IBag151.chargePackage(testPackage);

    EXPECT_NE(IBag151.getPackageInfo(), nullPackage);
}