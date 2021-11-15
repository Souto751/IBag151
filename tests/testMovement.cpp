#include "..\lib\googletest\googletest\include\gtest\gtest.h"
#include "..\include\iMovement.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime> 

TEST(Action, moveRight)
{
    MoveRight mr;
    int initialPosX = 0;

    mr.action(initialPosX);

    EXPECT_EQ(initialPosX, 1);
}

TEST(Action, moveLeft)
{
    MoveLeft ml;
    int initialPosX = 0;

    ml.action(initialPosX);

    EXPECT_EQ(initialPosX, -1);
}

TEST(Action, accelerate)
{
    Accelerate acc;
    int initialPosZ = 0;

    acc.action(initialPosZ);

    EXPECT_EQ(initialPosZ, 1);
}

TEST(Action, reverse)
{
    Reverse rev;
    int initialPosZ = 0;

    rev.action(initialPosZ);

    EXPECT_EQ(initialPosZ, -1);
}

TEST(Action, stop)
{
    Stop st;
    int speed = 10;

    st.action(speed);

    EXPECT_EQ(speed, 0);
}

TEST(Action, rotateLeft)
{
    RotateLeft rl;
    int orientation = 0;

    rl.action(orientation);

    EXPECT_EQ(orientation, 315);
}

TEST(Action, rotateRight)
{
    RotateRight rr;
    int orientation = 315;

    rr.action(orientation);

    EXPECT_EQ(orientation, 0);
}

TEST(Action, ascend)
{
    Ascend asc;
    int initialPosY = 0;

    asc.action(initialPosY);

    EXPECT_EQ(initialPosY, 1);
}

TEST(Action, descend)
{
    Descend des;
    int initialPosY = 10;

    des.action(initialPosY);

    EXPECT_EQ(initialPosY, 9);
}