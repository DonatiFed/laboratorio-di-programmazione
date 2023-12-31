//
// Created by Donat on 29/08/2023.
//
#include "Item.h"
#include <iostream>

Item::Item(std::string u, int q, std::string c, std::string n, bool b) : unitOfMeasure(u), category(c),
                                                                         name(n)  {
    if (q <= 0) {
        quantity = 0;
        bought= true;
    } else {
        quantity = q;
        bought=b;
    }
}


int Item::getQuantity() const {
    return quantity;
}

bool Item::isBought() const {
    return bought;
}

void Item::setName(std::string &name) {
    Item::name = name;
}

std::string Item::getName() const {
    return name;
}

void Item::setCategory(std::string &category) {
    Item::category = category;
}

void Item::setQuantity(int quantity) {
    if (quantity <= 0) {
        Item::quantity = 0;
    } else {
        Item::quantity = quantity;
    }
}

const std::string &Item::getUnitOfMeasure() const {
    return unitOfMeasure;
}

void Item::setUnitOfMeasure(std::string &unitOfMeasure) {
    Item::unitOfMeasure = unitOfMeasure;
}

void Item::setBought(bool b) {
    bought = b;
}

const std::string &Item::getCategory() const {
    return category;
}

