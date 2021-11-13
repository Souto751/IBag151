#include "..\lib\googletest\googletest\include\gtest\gtest.h"
#include "..\include\Camera.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime> 

TEST(Take, nPhoto)
{
    std::srand((unsigned)time(0));
    int n = (std::rand()%20)+1;
    
    Camera testCamera;

    std::string newPhoto;

    for(int i = 1; i <= n; i++){
        newPhoto = "01-15-" + std::to_string(i);
        testCamera.takePhoto(newPhoto);
    }

    EXPECT_TRUE(testCamera.getPhotos()[n-1] == newPhoto);
}

TEST(Get, NoPhotos)
{
    Camera testCamera;
    
    EXPECT_TRUE(testCamera.getPhotos().empty() == true);
}

TEST(Get, GetPhotos)
{
    Camera testCamera;
    testCamera.takePhoto("01-15-00");
    testCamera.takePhoto("01-13-01");
    testCamera.takePhoto("04-25-02");
    testCamera.takePhoto("75-150-03");

    std::vector<std::string> photos = {"01-15-00", "01-13-01", "04-25-02", "75-150-03"};

    for(int i = 0; i < testCamera.getPhotos().size(); i++){
        ASSERT_TRUE(testCamera.getPhotos()[i] == photos[i]);
    };

    
}