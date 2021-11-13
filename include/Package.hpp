#ifndef PACKAGE_HPP
#define PACKAGE_HPP

class Package{
    private:
        bool is_delivered = false;
    public:
        Package(){};
        ~Package(){};
        bool delivered(){
            return is_delivered;
        }
        void notifyDelivered(){
            std::cout << "El paquete ha sido entregado" << std::endl;
        }
};


#endif // PACKAGE_HPP