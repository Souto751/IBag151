#ifndef IMOVEMENT_HPP
#define IMOVEMENT_HPP

class IMovement{
    public:
        IMovement(){};
        virtual ~IMovement(){};
        virtual void action(int&) = 0;
};

class MoveRight : public IMovement{
    public:
        MoveRight(){};
        ~MoveRight(){};
        void action(int &posX){
            posX++;
        }
};

class MoveLeft : public IMovement{
    public:
        MoveLeft(){};
        ~MoveLeft(){};
        void action(int &posX){
            posX--;
        }
};

class Accelerate : public IMovement{
    public:
        Accelerate(){};
        ~Accelerate(){};
        void action(int &posZ){
            posZ++;
        }
};

class Reverse : public IMovement{
    public:
        Reverse(){};
        ~Reverse(){};
        void action(int &posZ){
            posZ--;
        }
};

class Stop : public IMovement{
    public:
        Stop(){};
        ~Stop(){};
        void action(int &speed){
            speed = 0;
        }
};

class RotateRight : public IMovement{
    public:
        RotateRight(){};
        ~RotateRight(){};
        void action(int &orientation){
            orientation += 45;
            if(orientation = 360) orientation = 0;
        }
};

class RotateLeft : public IMovement{
    public:
        RotateLeft(){};
        ~RotateLeft(){};
        void action(int &orientation){
            if(orientation == 0) orientation = 360;
            orientation -= 45;
        }
};

class Ascend : public IMovement{
    public:
        Ascend(){};
        ~Ascend(){};
        void action(int &posY){
            posY++;
        }
};

class Descend : public IMovement{
    public:
        Descend(){};
        ~Descend(){};
        void action(int &posY){
            posY--;
        }
};

#endif //IMOVEMENT_HPP