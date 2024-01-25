//
// Created by Donat on 31/08/2023.
//
#include "User.h"
#include "ObjectNumberUpdate.h"
#include "ObjectToBuyUpdate.h"

#include <iostream>

User::User(const std::string &n) : name(n) {
}

std::string User::getName() const {
    return name;
}

std::map<std::string, ShoppingList *> User::getLists() const {
    return lists;
}

void User::changeName(const std::string &n) {
    name = n;
}

void User::addList(ShoppingList *list) {
    lists.insert(std::make_pair(list->getName(), list));

}

void User::addList(const std::string &n) {
    std::string a=n;
    ShoppingList *l = new ShoppingList(n);
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
