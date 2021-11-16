#include "..\lib\googletest\googletest\include\gtest\gtest.h"
#include "..\include\iMovement.hpp"
#include "..\include\Drone.hpp"
#include "..\include\Menu.hpp"
#include <iostream>
#include <string>

TEST(Menu, CorrectOption)
{
    int option = -1;
    
    option = selectOption();

    ASSERT_TRUE(option >= 0);
    ASSERT_TRUE(option <= 14);
}

TEST(Menu, Option1_StartEngine)
{
    int option = 1;
    menuAction(option);

    EXPECT_TRUE(IBag151.getEngineStatus() == "on");
}

TEST(Menu, Option2_StopEngine)
{
    int option = 2;
    menuAction(option);

    EXPECT_TRUE(IBag151.getEngineStatus() == "off");
}

TEST(Menu, Option3_TestAccelerate)
{
    int option = 3;
    menuAction(option);

    EXPECT_EQ(IBag151.getSpeed(), 1);
    EXPECT_EQ(IBag151.getPositionZ(), 1);
}

TEST(Menu, Option4_TestBreak)
{
    int option = 4;
    menuAction(option);

    EXPECT_EQ(IBag151.getSpeed(), 0);
}

TEST(Menu, Option5_TestReverse)
{
    int option = 5;
    menuAction(option);

    EXPECT_EQ(IBag151.getSpeed(), -1);
    EXPECT_EQ(IBag151.getPositionZ(), 0);
}

TEST(Menu, Option6_TestAscend)
{
    int option = 6;
    menuAction(option);

    EXPECT_EQ(IBag151.getPositionY(), 1);
}

TEST(Menu, Option7_TestDescend)
{
    int option = 7;
    menuAction(option);

    EXPECT_EQ(IBag151.getPositionY(), 0);
}

TEST(Menu, Option8_TestMoveLeft)
{
    int option = 8;
    menuAction(option);

    EXPECT_EQ(IBag151.getPositionX(), -1);
}

TEST(Menu, Option9_TestMoveRight)
{
    int option = 9;
    menuAction(option);

    EXPECT_EQ(IBag151.getPositionX(), 0);
}

TEST(Menu, Option10_TestRotateLeft)
{
    int option = 10;
    menuAction(option);

    EXPECT_EQ(IBag151.getOrientation(), 315);
}

TEST(Menu, Option11_TestRotateRight)
{
    int option = 11;
    menuAction(option);

    EXPECT_EQ(IBag151.getOrientation(), 0);
}

TEST(Menu, Option12_Charge)
{
    int option = 12;
    menuAction(option);

    EXPECT_TRUE(IBag151.getPackageInfo() == false);
}

TEST(Menu, Option13_Deliver)
{
    int option = 13;
    menuAction(option);

    testing::internal::CaptureStdout();
    IBag151.deliverPackage();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(IBag151.getPackageInfo() == true);
    EXPECT_EQ("El paquete ha sido entregado.\n", output);
}

TEST(Menu, Option14_Exit)
{
    int option = 14;

    testing::internal::CaptureStdout();
    menuAction(option);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("Hasta luego!\n", output);
}