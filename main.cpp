#include <iostream>
#include "User.h"


int main() {

    User u;
    bool continueProgram = true;
    char choice;
    do {
        std::cout << u.getName() << ",what would you like to do?" << std::endl;
        std::cout << "1) Change Username" << std::endl;
        std::cout << "2) Create a list" << std::endl;
        std::cout << "3) Remove a list" << std::endl;
        std::cout << "4) See lists" << std::endl;
        std::cout << "5) Exit the supermarket" << std::endl;
        std::cin >> choice;
        switch (choice) {
            case '1':
                u.changeName();
                break;
            case '2':
                u.addList();


                break;
            case '3':
                if(u.getLists().size()==0){
                    std::cout<<"You don't have any list"<<std::endl;
                    break;
                }
               u.removeList();
               break;
            case '4':
                if(u.getLists().size()==0){
                    std::cout<<"You don't have any list"<<std::endl;
                    break;
                }
                u.printLists();
               u.listActions(u.selectList());
                break;
                    case '5':
                        std::cout << "Goodbye " << u.getName() << std::endl;
                        continueProgram = false;
                    break;
                    default:
                        std::cout << "Scelta non valida" << std::endl;
                    break;

    }
    } while (continueProgram);
}