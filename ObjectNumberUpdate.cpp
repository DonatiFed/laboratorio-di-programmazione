//
// Created by Donat on 31/08/2023.
//
#include "ObjectNumberUpdate.h"
#include <iostream>

ObjectNumberUpdate::ObjectNumberUpdate(ShoppingList *s) : subject(s) {
    s->registerObserver(this);
}

void ObjectNumberUpdate::update() {
    std::cout << "total number of elements: " << subject->totalObjectsNumber() << std::endl;
}

ObjectNumberUpdate::~ObjectNumberUpdate() {
    subject->unregisterObserver(this);
}