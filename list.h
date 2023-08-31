//
// Created by Donat on 29/08/2023.
//

#ifndef UNTITLED18_LIST_H
#define UNTITLED18_LIST_H
#include <iostream>
#include <map>
#include "Item.h"
#include <vector>

#endif //UNTITLED18_LIST_H
class List{
public:
    List(std::string n);
    std::string getName();
    void setName(std::string name);
    void addItem();
    void removeItem();
    void changeQuantity();
    void changeCategory();
    void changeUnitOfMeasure();
    void changeBought();
    void printList();
    void printCategories();
    void printUnitiesOfMeasure();
   void printTotalObjects();
   void printtObjectsToBuy();


private:
    std::string name;
    std::map<std::string,Item> list;

    std::map<int,std::string> unitiesOfMeasure;
    std::map<int,std::string> categories;

    int totalobjects;
    int tobuyobjects;


};