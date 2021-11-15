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
    Package pack;

    IBag151.chargePackage(pack);

    IBag151.deliverPackage();

    EXPECT_TRUE(IBag151.getPackageInfo() == true);
}

TEST(Pack, ChargePackage)
{
    Drone IBag151;
    Package testPackage;

    IBag151.chargePackage(testPackage);

    EXPECT_TRUE(IBag151.getPackageInfo() == false);
}