#include "..\lib\googletest\googletest\include\gtest\gtest.h"
#include "..\include\iMovement.hpp"
#include "..\include\Drone.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime> 

TEST(Action, moveRight)
{
    MoveRight mr;
    Drone testDrone;

    mr.action(testDrone);

    EXPECT_EQ(testDrone.getPositionX(), 1);
}

TEST(Action, moveLeft)
{
    MoveLeft ml;
    Drone testDrone;

    ml.action(testDrone);

    EXPECT_EQ(testDrone.getPositionX(), -1);
}

TEST(Action, accelerate)
{
    Accelerate acc;
    Drone testDrone;

    acc.action(testDrone);

    EXPECT_EQ(testDrone.getPositionZ(), 1);
    EXPECT_EQ(testDrone.getSpeed(), 1);
}

TEST(Action, reverse)
{
    Reverse rev;
    Drone testDrone;

    rev.action(testDrone);

    EXPECT_EQ(testDrone.getPositionZ(), -1);
}

TEST(Action, stop)
{
    Stop st;
    Drone testDrone;

    st.action(testDrone);

    EXPECT_EQ(testDrone.getSpeed(), 0);
}

TEST(Action, rotateLeft)
{
    RotateLeft rl;
    Drone testDrone;

    rl.action(testDrone);

    EXPECT_EQ(testDrone.getOrientation(), 315);
}

TEST(Action, rotateRight)
{
    RotateRight rr;
    Drone testDrone;

    rr.action(testDrone);

    EXPECT_EQ(testDrone.getOrientation(), 45);
}

TEST(Action, ascend)
{
    Ascend asc;
    Drone testDrone;

    asc.action(testDrone);

    EXPECT_EQ(testDrone.getPositionY(), 1);
}

TEST(Action, descend)
{
    Descend des;
    Drone testDrone;

    des.action(testDrone);

    EXPECT_EQ(testDrone.getPositionY(), -1);
}