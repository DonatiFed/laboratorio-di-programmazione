#include <iostream>
#include "User.h"
void ListManager(List* list){
    bool continueiteration=true;
    char choice;
    do {
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "1) Add an item" << std::endl;
        std::cout << "2) Remove an item" << std::endl;
        std::cout<<"3) Change category of an item"<<std::endl;
        std::cout<<"4) Change quantity of an item"<<std::endl;
        std::cout<<"5) mark an object as bought/to buy"<<std::endl;
        std::cout << "6) Change name" << std::endl;
        std::cout<<"7) Exit"<<std::endl;

        std::cin >> choice;
        switch (choice) {
            case '1':
                list->addItems();
                break;
            case '2':
                list->removeItem();
                break;
            case '3':
                list->changeCategory();
                break;
            case '4':
                list->changeQuantity();
                list->changeUnitOfMeasure();
                break;
            case '5':
                list->changeBought();
                break;
            case '6':
                list->changeName();
                break;

            case '7':
                continueiteration = false;
                break;
            default:
                std::cout << "Select a number between 1 and 5" << std::endl;
                break;
        }
    }while(continueiteration);

}


int main() {
std::string name;
std::cout<<"Insert your name"<<std::endl;
std::cin>>name;
    User u(name);
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
                std::cout<<"Which list do you want to select?"<<std::endl;
                int n;
                std::cin>>n;
                if(n<=0||n>u.getLists().size()){
                    std::cout<<"Select a number between 0 and"<<u.getLists().size()<<std::endl;
                    int j=1;
                    for(auto it=u.getLists().begin();it!=u.getLists().end();it++){
                        if(j==n){
                            ListManager(it->second);
                            break;
                        }
                        j++;
                    }
                    break;
                }
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