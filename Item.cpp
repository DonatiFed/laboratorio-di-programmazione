//
// Created by Donat on 29/08/2023.
//
#include "Item.h"
#include <iostream>

Item::Item(std::string u ,int q,std::string c, std::string n,  bool b) :unitOfMeasure(u),quantity(q),category(c),name(n),bought(b){}


int Item::getQuantity() {
    return quantity;
}

bool Item::isBought() {
    return bought;
}
void Item::setName(std::string name) {
    Item::name=name;
}
std::string Item::getName() {
    return name;
}
void Item::setCategory(std::string category) {
    Item::category=category;
}
void Item::setQuantity(int quantity) {
    Item::quantity=quantity;
}
void Item::setUnitOfMeasure(std::string unitOfMeasure) {
    Item::unitOfMeasure=unitOfMeasure;
}
void Item::setBought(bool b) {
    bought=b;
}

