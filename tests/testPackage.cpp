#include "..\lib\googletest\googletest\include\gtest\gtest.h"
#include "..\include\Package.hpp"
#include <iostream>
#include <string>

TEST(Delivered, isDelivered)
{
    Package testPackage;

    EXPECT_EQ(testPackage.delivered(), true);
}

TEST(Notify, NotifyDelivery)
{
    Package testPackage;

    testing::internal::CaptureStdout();
    testPackage.notifyDelivered();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("El paquete ha sido entregado.\n", output);
}

TEST(Get, Status)
{
    Package testPack;

    EXPECT_TRUE(testPack.getStatus() == false);
}