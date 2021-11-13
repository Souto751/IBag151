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
        Package* package = NULL;
    public:
        Drone(){};
        ~Drone(){
            delete package;
        };
        void engineOn(){
            engine_status = "prendido";
        }
        void engineOff(){
            engine_status = "apagado";
        }
        void deliverPackage(){
            std::cout << "El paquete ha sido entregado" << std::endl;
        }
        void chargePackage(Package &pack){
            package = NULL;
        }
        Package * getPackageInfo(){
            return package;
        }
        std::string getEngineStatus(){
            return engine_status;
        }
};


#endif // DRONE_HPP