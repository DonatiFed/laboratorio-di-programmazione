//
// Created by Donat on 29/08/2023.
//

#ifndef UNTITLED18_USER_H
#define UNTITLED18_USER_H



#include <iostream>
#include <map>
#include "Shoppinglist.h"

class User {
public:
    User(const std::string &n);

    std::map<std::string, ShoppingList *> getLists() const;

    std::string getName() const;

    void changeName(const std::string &n);

    void addList(ShoppingList *list);

    void addList(const std::string &n) ;

    void removeList(const std::string &n);

    void printLists();



private:
    std::string name;
    std::map<std::string, ShoppingList *> lists;


};
#endif //UNTITLED18_USER_H