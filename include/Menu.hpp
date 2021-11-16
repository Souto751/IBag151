#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <limits>
#include "./Drone.hpp"
#include "./iMovement.hpp"

int selectOption(){
    int option = -1;

    std::cout << "Insert option: ";
    std::cin >> option;
    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        option = -1;
    }
    
    return option;
}

void menuAction(int &option){
    if(option == 1) IBag151.engineOff();
    if(option == 2) IBag151.engineOn();
    if(option == 3) reverse.action(IBag151);
    if(option == 4) accelerate.action(IBag151);
    if(option == 5) stop.action(IBag151);
    if(option == 6) descend.action(IBag151);
    if(option == 7) ascend.action(IBag151);
    if(option == 8) moveRight.action(IBag151);
    if(option == 9) moveLeft.action(IBag151);
    if(option == 10) rotateRight.action(IBag151);
    if(option == 11) rotateLeft.action(IBag151);
    if(option == 12) IBag151.deliverPackage();
    if(option == 13) {
        Package pack;
        IBag151.chargePackage(pack);
    }
    if(option == 14) option = -1;
}

void displayMenu(){
    int option = 0;
    do{
        std::cout << "App Drone IBag151" << std::endl << std::endl;
        std::cout << "--Drive Drone--" << std::endl;
        std::cout << "1. Start Engine" << std::endl;
        std::cout << "2. Stop Engine" << std::endl;
        std::cout << "3. Accelerate" << std::endl;
        std::cout << "4. Break" << std::endl;
        std::cout << "5. Reverse" << std::endl;
        std::cout << "6. Ascend" << std::endl;
        std::cout << "7. Descend" << std::endl;
        std::cout << "8. Turn Left" << std::endl;
        std::cout << "9. Turn Right" << std::endl;
        std::cout << "10. Rotate Left" << std::endl;
        std::cout << "11. Rotate Right" << std::endl << std::endl;
        std::cout << "--Package--" << std::endl;
        std::cout << "12. Pick Up a Package" << std::endl;
        std::cout << "13. Deliver Package" << std::endl << std::endl;
        std::cout << "--System--" << std::endl;
        std::cout << "14. Exit" << std::endl << std::endl;
        std::cout << "--Option--" << std::endl;

        option = selectOption();
        
        if(option < 0 || option > 14){
            std::cout << "Invalid Option" << std::endl;
            option = 0;
            std::cin.ignore();
        }

        menuAction(option);
    }while(option >= 0 && option <= 14);
}

#endif // MENU_HPP