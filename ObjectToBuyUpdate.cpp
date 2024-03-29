//
// Created by Donat on 31/08/2023.
//
#include <iostream>
#include "ObjectToBuyUpdate.h"

ObjectToBuyUpdate::ObjectToBuyUpdate(ShoppingList *s) : subject(s) {
    s->registerObserver(this);
}

void ObjectToBuyUpdate::update() {
    std::cout << "Objects to buy: " << subject->toBuyNumber() << std::endl;
}

ObjectToBuyUpdate::~ObjectToBuyUpdate() {
    subject->unregisterObserver(this);
}
