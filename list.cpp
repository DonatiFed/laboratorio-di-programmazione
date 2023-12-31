//
// Created by Donat on 31/08/2023.
//
#include <iostream>
#include <map>
#include <sstream>
#include "List.h"
#include "Subject.h"
#include "ObjectNumberUpdate.h"

List::List(std::string &n) : name(n), totalobjects(0), tobuyobjects(0) {
}

void List::setName(std::string &name) {
    List::name = name;
}

const std::string &List::getName() const {
    return name;
}

void List::addItem(std::string &unitOfMeasure, int quantity, std::string &category, std::string &name, bool bought) {

    Item i(unitOfMeasure, quantity, category, name, false);
    list.insert(std::make_pair(name, i));
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


void List::changeBought(const std::string &name, bool b) {
    auto i = list.find(name);
    if (i == list.end()) {
        // std::cout << "Item not found" << std::endl;
        return;
    }
    if (i->second.isBought() == b) {
        // std::cout << "no need to change" << std::endl;
        return;
    }
    i->second.setBought(b);
    if (b == true) {
        tobuyobjects--;
    } else {
        tobuyobjects++;
    }
    // std::cout << "Bought changed" << std::endl;
    notify();
}


int List::TotalObjectsnumber() {
    return totalobjects;
}

int List::ToBuynumber() {
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

void List::changeName(std::string &n) {
    name = n;
}

std::map<std::string, Item> List::getList() const {
    return list;
}

std::string List::totelementslist() {
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

std::string List::tobuyelementslist() {
    std::string s;
    std::string result;
    std::string q;
    for (auto x: list) {
        if(x.second.isBought()==false){
            std::stringstream ss;
            ss << x.second.getQuantity();
            q = ss.str(); // trasformo un intero in una stringa
            s = "\n" + x.second.getName() + " " + q + " " + x.second.getUnitOfMeasure() + " " + x.second.getCategory();
            result += s;
        }

    }
    return result;
}

