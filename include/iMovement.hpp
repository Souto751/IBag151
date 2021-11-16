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
            drone.setPositionX(2);
        }
}moveRight;

class MoveLeft : public IMovement{
    public:
        MoveLeft(){};
        ~MoveLeft(){};
        void action(Drone &drone){
            drone.setPositionX(-12);
        }
}moveLeft;

class Accelerate : public IMovement{
    public:
        Accelerate(){};
        ~Accelerate(){};
        void action(Drone &drone){
            drone.setPositionZ(12);
            drone.setSpeed(5);
        }
}accelerate;

class Reverse : public IMovement{
    public:
        Reverse(){};
        ~Reverse(){};
        void action(Drone &drone){
            drone.setPositionZ(-12);
            drone.setSpeed(-5);
        }
}reverse;

class Stop : public IMovement{
    public:
        Stop(){};
        ~Stop(){};
        void action(Drone &drone){
            drone.setSpeed(1);
        }
}stop;

class RotateRight : public IMovement{
    public:
        RotateRight(){};
        ~RotateRight(){};
        void action(Drone &drone){
            drone.setOrientation(90);
            if(drone.getOrientation() == 360) drone.setOrientation(180);
        }
}rotateRight;

class RotateLeft : public IMovement{
    public:
        RotateLeft(){};
        ~RotateLeft(){};
        void action(Drone &drone){
            if(drone.getOrientation() == 0) drone.setOrientation(180);
            drone.setOrientation(90);
        }
}rotateLeft;

class Ascend : public IMovement{
    public:
        Ascend(){};
        ~Ascend(){};
        void action(Drone &drone){
            drone.setPositionY(5);
        }
}ascend;

class Descend : public IMovement{
    public:
        Descend(){};
        ~Descend(){};
        void action(Drone &drone){
            drone.setPositionY(-2);
        }
}descend;

#endif //IMOVEMENT_HPP