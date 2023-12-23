//
// Created by Donat on 31/08/2023.
//
#include "User.h"
#include "ObjectNumberUpdate.h"
#include "ObjectToBuyUpdate.h"

#include <iostream>

User::User(std::string &n) : name(n) {
}

std::string User::getName() const {
    return name;
}

std::map<std::string, List *> User::getLists() const {
    return lists;
}

void User::changeName(std::string &n) {
    name = n;
}

void User::addList(List *list) {
    lists.insert(std::make_pair(list->getName(), list));

}

void User::addList(std::string &n) {
    List *l = new List(n);
    lists.insert(std::make_pair(l->getName(), l));
    // std::cout<<"List created"<<std::endl;

}

void User::removeList(const std::string &n) {
    auto it = lists.find(n);
    if (it == lists.end()) {
        // std::cout<<"No list removed"<<std::endl;
        return;
    }
    lists.erase(n);
    //std::cout<<"List removed"<<std::endl;
}

void User::printLists() {
    if (lists.size() == 0) {
        std::cout << "You don't have any list" << std::endl;
        return;
    }
    std::cout << "Your lists: " << std::endl;
    int i = 1;
    for (auto x: lists) {
        std::cout << i << ") " << x.first << std::endl;
        i++;
    }
}
/*List* User::selectList() {

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
*/