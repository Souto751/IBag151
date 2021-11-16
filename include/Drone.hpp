#ifndef DRONE_HPP
#define DRONE_HPP

#include <string>
#include "./Package.hpp"
#include "./Camera.hpp"

class Drone{
    private:
        std::string engine_status = "off";
        int pos_x = 0;
        int pos_y = 0;
        int pos_z = 0;
        int orientation = 0;
        int speed = 0;
        Camera camera;
        Package package;
    public:
        Drone(){};
        ~Drone(){};
        void engineOn(){
            engine_status = "on";
        }
        void engineOff(){
            engine_status = "off";
        }
        void deliverPackage(){
            package.delivered();
        }
        void chargePackage(Package &pack){
            package = pack;
        }
        bool getPackageInfo(){
            bool pack_status = package.getStatus();
            return pack_status;
        }
        std::string getEngineStatus(){
            return engine_status;
        }
        void setPositionX(int newPosX){
            pos_x = newPosX;
        }
        void setPositionY(int newPosY){
            pos_y = newPosY;
        }
        void setPositionZ(int newPosZ){
            pos_z = newPosZ;
        }
        void setSpeed(int sp){
            speed = sp;
        }
        void setOrientation(int newOrientation){
            orientation = newOrientation;
        }
        int getPositionX(){
            return pos_x;
        }
        int getPositionY(){
            return pos_y;
        }
        int getPositionZ(){
            return pos_z;
        }
        int getSpeed(){
            return speed;
        }
        int getOrientation(){
            return orientation;
        }
}IBag151;


#endif // DRONE_HPP