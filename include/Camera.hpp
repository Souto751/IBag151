#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Camera{
    private:
        std::vector<std::string> photosList{};
    public:
        Camera();
        ~Camera();
        void takePhoto(std::string details);
        std::vector<std::string> getPhotos();
};

Camera::Camera(){};

Camera::~Camera(){};

void Camera::takePhoto(std::string details){
    std::reverse(photosList.begin(), photosList.end());
    photosList.push_back(details);
    std::reverse(photosList.begin(), photosList.end());
};

std::vector<std::string> Camera::getPhotos(){
    return photosList;
};


#endif // CAMERA_HPP