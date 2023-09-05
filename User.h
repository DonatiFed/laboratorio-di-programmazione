//
// Created by Donat on 29/08/2023.
//

#ifndef UNTITLED18_USER_H
#define UNTITLED18_USER_H

#endif //UNTITLED18_USER_H
#include <iostream>
#include <map>
#include "List.h"
class User{
public:
    User(std::string n);
    std::map <std::string,List*> getLists();
    std::string getName();
    void changeName(std::string n);
    void addList(List *list);
    void addList(std::string n);
    void removeList(std::string n);
    void printLists();
 //   List* selectList();


private:
    std::string name;
    std::map<std::string,List*> lists;


};