//
// Created by Donat on 29/08/2023.
//

#ifndef UNTITLED18_LIST_H
#define UNTITLED18_LIST_H
#include <iostream>
#include <map>
#include "Item.h"
#include <vector>
#include "Subject.h"
#include <list>

#endif //UNTITLED18_LIST_H
class List: public Subject{
public:
    List(std::string name);
    std::string getName();
    void setName(std::string name);
    void addItems();
    void removeItem();
    void changeQuantity();
    void changeCategory();
    void changeUnitOfMeasure();
    void changeBought();
    void changeName();
    void printList();
    void printCategories();
    void printUnitiesOfMeasure();
   void printTotalObjects();
   void printObjectsToBuy();
   void registerObserver(Observer* o) override;
    void unregisterObserver(Observer* o) override;
    void notify() override;


private:
    std::string name;
    std::map<std::string,Item> list;

    std::map<int,std::string> unitiesOfMeasure;
    std::map<int,std::string> categories;
    std::list<Observer*> obs;
    int totalobjects;
    int tobuyobjects;

};