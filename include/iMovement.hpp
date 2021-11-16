#ifndef IMOVEMENT_HPP
#define IMOVEMENT_HPP

#include "./Drone.hpp"

class IMovement{
    public:
        IMovement(){};
        virtual ~IMovement(){};
        virtual void action(Drone&) = 0;
};

class MoveRight : public IMovement{
    public:
        MoveRight(){};
        ~MoveRight(){};
        void action(Drone &drone){
            drone.setPositionX(drone.getPositionX() + 1);
        }
}moveRight;

class MoveLeft : public IMovement{
    public:
        MoveLeft(){};
        ~MoveLeft(){};
        void action(Drone &drone){
            drone.setPositionX(drone.getPositionX() - 1);
        }
}moveLeft;

class Accelerate : public IMovement{
    public:
        Accelerate(){};
        ~Accelerate(){};
        void action(Drone &drone){
            drone.setPositionZ(drone.getPositionZ() + 1);
            drone.setSpeed(drone.getSpeed() + 1);
        }
}accelerate;

class Reverse : public IMovement{
    public:
        Reverse(){};
        ~Reverse(){};
        void action(Drone &drone){
            drone.setPositionZ(drone.getPositionZ() - 1);
            drone.setSpeed(drone.getSpeed() - 1);
        }
}reverse;

class Stop : public IMovement{
    public:
        Stop(){};
        ~Stop(){};
        void action(Drone &drone){
            drone.setSpeed(0);
        }
}stop;

class RotateRight : public IMovement{
    public:
        RotateRight(){};
        ~RotateRight(){};
        void action(Drone &drone){
            drone.setOrientation(drone.getOrientation() + 45);
            if(drone.getOrientation() == 360) drone.setOrientation(0);
        }
}rotateRight;

class RotateLeft : public IMovement{
    public:
        RotateLeft(){};
        ~RotateLeft(){};
        void action(Drone &drone){
            if(drone.getOrientation() == 0) drone.setOrientation(360);
            drone.setOrientation(drone.getOrientation() - 45);
        }
}rotateLeft;

class Ascend : public IMovement{
    public:
        Ascend(){};
        ~Ascend(){};
        void action(Drone &drone){
            drone.setPositionY(drone.getPositionY() + 1);
        }
}ascend;

class Descend : public IMovement{
    public:
        Descend(){};
        ~Descend(){};
        void action(Drone &drone){
            drone.setPositionY(drone.getPositionY() - 1);
        }
}descend;

#endif //IMOVEMENT_HPP