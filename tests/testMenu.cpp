#include "..\lib\googletest\googletest\include\gtest\gtest.h"
#include "..\include\iMovement.hpp"
#include "..\include\Drone.hpp"
#include "..\include\Menu.hpp"
#include <iostream>
#include <string>

TEST(Menu, CorrectOption)
{
    int option = -1;
    try{
        option = selectOption();
    }catch(std::ios_base::failure &fail){
        option = -1;
        std::cin.clear();
    }

    EXPECT_TRUE(option >= 0 && option <= 14);
}

TEST(Menu, Option1)
{
    int option = 1;
    menuAction(option);

    EXPECT_TRUE(IBag151.getEngineStatus() == "on");
}

TEST(Menu, StopEngine)
{
    int option = 2;
    menuAction(option);

    EXPECT_TRUE(IBag151.getEngineStatus() == "off");
}

TEST(Menu, TestAccelerate)
{
    int option = 3;
    menuAction(option);

    EXPECT_EQ(IBag151.getSpeed(), 1);
    EXPECT_EQ(IBag151.getPositionZ(), 1);
}

TEST(Menu, TestBreak)
{
    int option = 4;
    menuAction(option);

    EXPECT_EQ(IBag151.getSpeed(), 0);
}

TEST(Menu, TestReverse)
{
    int option = 5;
    menuAction(option);

    EXPECT_EQ(IBag151.getSpeed(), -1);
    EXPECT_EQ(IBag151.getPositionZ(), -1);
}

TEST(Menu, TestAscend)
{
    int option = 6;
    menuAction(option);

    EXPECT_EQ(IBag151.getPositionY(), 1);
}

TEST(Menu, TestDescend)
{
    int option = 7;
    menuAction(option);

    EXPECT_EQ(IBag151.getPositionY(), -1);
}

TEST(Menu, TestMoveLeft)
{
    int option = 8;
    menuAction(option);

    EXPECT_EQ(IBag151.getPositionZ(), -1);
}

TEST(Menu, TestMoveRight)
{
    int option = 9;
    menuAction(option);

    EXPECT_EQ(IBag151.getPositionZ(), 1);
}

TEST(Menu, TestRotateLeft)
{
    int option = 10;
    menuAction(option);

    EXPECT_EQ(IBag151.getOrientation(), 45);
}

TEST(Menu, TestRotateRight)
{
    int option = 11;
    menuAction(option);

    EXPECT_EQ(IBag151.getOrientation(), 315);
}

TEST(Menu, Charge)
{
    int option = 12;
    menuAction(option);

    EXPECT_TRUE(IBag151.getPackageInfo() == false);
}

TEST(Menu, Deliver)
{
    int option = 13;
    menuAction(option);

    EXPECT_TRUE(IBag151.getPackageInfo() == true);
}

TEST(Menu, Exit)
{
    int option = 14;
    menuAction(option);

    testing::internal::CaptureStdout();
    IBag151.deliverPackage();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("Hasta luego!\n", output);
}