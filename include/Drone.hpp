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
        void chargePackage(Package pack){
            package = pack;
        }
        bool getPackageInfo(){
            bool pack_status = package.getStatus();
            return pack_status;
        }
        std::string getEngineStatus(){
            return engine_status;
        }
};


#endif // DRONE_HPP