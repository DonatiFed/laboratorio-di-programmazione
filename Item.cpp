//
// Created by Donat on 29/08/2023.
//
#include "Item.h"
#include <iostream>

Item::Item(std::string &u, int q, std::string &c, std::string &n, bool b) : unitOfMeasure(u), category(c),
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

void Item::setName(const std::string &names) {
    Item::name = names;
}

std::string Item::getName() const {
    return name;
}

void Item::setCategory(std::string &categorys) {
    Item::category = categorys;
}

void Item::setQuantity(int quantiti) {
    if (quantiti <= 0) {
        Item::quantity = 0;
    } else {
        Item::quantity = quantiti;
    }
}

const std::string &Item::getUnitOfMeasure() const {
    return unitOfMeasure;
}

void Item::setUnitOfMeasure(std::string &unitofMeasure) {
    Item::unitOfMeasure = unitofMeasure;
}

void Item::setBought(bool b) {
    bought = b;
}

const std::string &Item::getCategory() const {
    return category;
}

