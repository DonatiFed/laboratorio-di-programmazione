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


class ShoppingList : public Subject {
public:
    explicit ShoppingList(const std::string &name);

    const std::string &getName() const;

    void setName(const std::string &name);

    void addItem(const std::string &unitOfMeasure, int quantity, const std::string &category,const std::string &name, bool bought);

    void addItem(Item i);

    void removeItem(const std::string &n);

    void changeName(const std::string &n);


   int totalObjectsNumber() const;

    int toBuyNumber() const;

    void registerObserver(Observer *o) override;

    void unregisterObserver(Observer *o) override;

    void notify() override;

    std::map<std::string, Item> getList() const;

    void changeBought(const std::string &name, bool b);

    std::string totElementsList();

    std::string toBuyElementsList();

    const std::list<Observer *> &getObs() const;


private:
    std::string name;
    std::map<std::string, Item> list;

    std::list<Observer *> obs;
    int totalobjects;
    int tobuyobjects;

};

#endif //UNTITLED18_LIST_H