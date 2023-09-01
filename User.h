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
    User();
    std::map <std::string,List*> getLists();
    std::string getName();
    void setName(std::string name);
    void changeName();
    void addList(List *list);
    void addList();
    void removeList();
    void printLists();
    List* selectList();
    void listActions(List* list);

private:
    std::string name;
    std::map<std::string,List*> lists;


};