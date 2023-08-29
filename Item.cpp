//
// Created by Donat on 29/08/2023.
//
#include "Item.h"
#include <iostream>

std::string Item::getName() {
    return name;
}
std::string Item::getCategory() {
    return category;
}
int Item::getQuantity() {
    return quantity;
}
std::string Item::getUnitOfMeasure() {
    return unitOfMeasure;
}
bool Item::isBought() {
    return bought;
}
void Item::setName(std::string name) {
    Item::name=name;
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
void Item::setBought(bool bought) {
    Item::bought=bought;
}
Item::Item(std::string n, std::string c, int q, std::string u, bool b) :name(n),category(c),quantity(q),unitOfMeasure(u),bought(b){}
