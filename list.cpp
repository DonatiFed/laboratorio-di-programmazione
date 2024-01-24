//
// Created by Donat on 31/08/2023.
//
#include <iostream>
#include <map>
#include <sstream>
#include "List.h"
#include "Subject.h"


List::List(const std::string &name) : name(name), totalobjects(0), tobuyobjects(0) {
}



const std::string &List::getName() const {
    return name;
}

void List::addItem(const std::string &unitOfMeasure, int quantity, const std::string &category,const std::string &names, bool bought) {

    Item i(unitOfMeasure, quantity, category, name, false);
    list.insert(std::make_pair(names, i));
    totalobjects++;
    if (quantity>0){
        tobuyobjects++;
    }
    // std::cout << "Item added" << std::endl;
    notify();


}

void List::addItem(Item i) {
    list.insert(std::make_pair(i.getName(), i));
    totalobjects++;
    if (i.getQuantity()>0){
        tobuyobjects++;
    }
    //  std::cout << "Item added" << std::endl;
    notify();

}

void List::removeItem(const std::string &n) {
    auto it = list.find(n);
    if (it == list.end()) {
        //  std::cout << "No item removed" << std::endl;
    } else {
        list.erase(n);
        //  std::cout << "Item removed" << std::endl;
        totalobjects--;
        tobuyobjects--;
        notify();
    }
}


void List::changeBought(const std::string &names, bool b) {
    auto i = list.find(names);
    if (i == list.end()) {
        // std::cout << "Item not found" << std::endl;
        return;
    }
    if (i->second.isBought() == b) {
        // std::cout << "no need to change" << std::endl;
        return;
    }
    i->second.setBought(b);
    if (b) {
        tobuyobjects--;
    } else {
        tobuyobjects++;
    }
    // std::cout << "Bought changed" << std::endl;
    notify();
}


int List::totalObjectsNumber() const{
    return totalobjects;
}

int List::toBuyNumber() const{
    return tobuyobjects;
}

void List::registerObserver(Observer *o) {
    obs.push_back(o);
}

void ::List::unregisterObserver(Observer *o) {
    obs.remove(o);
}

void List::notify() {
    for (auto x: obs) {
        x->update();
    }
}

void List::changeName(const std::string &n) {
    name = n;
}

std::map<std::string, Item> List::getList() const {
    return list;
}

std::string List::totElementsList() {
    std::string s;
    std::string result;
    std::string q;
    for (auto x: list) {
        std::stringstream ss;
        ss << x.second.getQuantity();
        q = ss.str(); // trasformo un intero in una stringa
        s = "\n" + x.second.getName() + " " + q + " " + x.second.getUnitOfMeasure() + " " + x.second.getCategory();
        result += s;
    }
    return result;
}

std::string List::toBuyElementsList() {
    std::string s;
    std::string result;
    std::string q;
    for (auto x: list) {
        if(!x.second.isBought()){
            std::stringstream ss;
            ss << x.second.getQuantity();
            q = ss.str(); // trasformo un intero in una stringa
            s = "\n" + x.second.getName() + " " + q + " " + x.second.getUnitOfMeasure() + " " + x.second.getCategory();
            result += s;
        }

    }
    return result;
}

