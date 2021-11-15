#ifndef PACKAGE_HPP
#define PACKAGE_HPP

class Package{
    private:
        bool was_delivered = false;
    public:
        Package(){};
        ~Package(){};
        bool delivered(){
            was_delivered = true;
            notifyDelivered();
            return was_delivered;
        }
        void notifyDelivered(){
            std::cout << "El paquete ha sido entregado." << std::endl;
        }
        bool getStatus(){
            return was_delivered;
        }
};


#endif // PACKAGE_HPP