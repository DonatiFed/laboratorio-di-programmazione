//
// Created by Donat on 31/08/2023.
//
#include "User.h"

#include <iostream>

User::User(){
    std::cout<<"Enter Username: "<<std::endl;
    std::string n;
    std::cin>>n;
    name=n;
}
void User::setName(std::string name) {
    this->name=name;
}
std::string User::getName() {
    return name;
}

std::map <std::string,List*> User::getLists() {
    return lists;
}
void User::changeName() {
    std::cout<<"Enter new Username: "<<std::endl;
    std::string n;
    std::cin>>n;
    name=n;
}
void User::addList(List* list) {
    lists.insert(std::make_pair(list->getName(),list));

}
void User::addList() {
    std::cout<<"Enter the name of the list: "<<std::endl;
    std::string n;
    std::cin>>n;
    List* l = new List(n);
    lists.insert(std::make_pair(l->getName(),l));
    std::cout<<"List created"<<std::endl;
    std::cout<<"Add some items to the list"<<std::endl;
    l->addItems();


}
void User::removeList() {
    std::cout<<"Which list do you want to remove?: "<<std::endl;
    printLists();
    int n;
    std::cin>>n;
    if(n<=0){
        std::cout<<"Select a number higher than 0"<<std::endl;
        return;
    }
    if(n>lists.size()){
        std::cout<<"Select a number lower than "<<lists.size()<<std::endl;
        return;
    }
    int i=1;
    for(auto it=lists.begin();it!=lists.end();it++){
        if(i==n){
            lists.erase(it);
            return;
        }
        i++;
    }
}
void User::printLists() {
    if (lists.size()==0){
        std::cout<<"You don't have any list"<<std::endl;
        return;
    }
    std::cout<<"Your lists: "<<std::endl;
    int i=1;
    for(auto x:lists){
        std::cout<<i<<") "<<x.first<<std::endl;
        i++;
    }
}
List* User::selectList() {

    int n;
    bool listselected=false;
    do{
        std::cout<<"Which list do you want to select?: "<<std::endl;
        printLists();
    std::cin>>n;
    if(n<=0){
        std::cout<<"Select a number higher than 0"<<std::endl;
        continue;
    }
    if(n>lists.size()){
        std::cout<<"Select a number lower than "<<lists.size()+1<<std::endl;
        continue;
    }
    int i=1;
    for(auto it=lists.begin();it!=lists.end();it++){
        if(i==n){
            it->second->printList();
            return it->second;
        }
        i++;
    }
    }while(!listselected);
}
void User::listActions(List* list) {
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