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


class List : public Subject {
public:
    List(std::string &name);

    const std::string &getName() const;

    void setName(std::string &name);

    void addItem(std::string &unitOfMeasure, int quantity, std::string &category, std::string &name, bool bought);

    void addItem(Item i);

    void removeItem(const std::string &n);

    void changeName(std::string &n);


    int TotalObjectsnumber();

    int ToBuynumber();

    void registerObserver(Observer *o) override;

    void unregisterObserver(Observer *o) override;

    void notify() override;

    std::map<std::string, Item> getList() const;

    void changeBought(const std::string &name, bool b);

    std::string totelementslist();

    std::string tobuyelementslist();


private:
    std::string name;
    std::map<std::string, Item> list;

    std::list<Observer *> obs;
    int totalobjects;
    int tobuyobjects;

};

#endif //UNTITLED18_LIST_H