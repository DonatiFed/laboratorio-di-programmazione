//
// Created by Donat on 31/08/2023.
//
#include "ObjectNumberUpdate.h"
#include <iostream>

ObjectNumberUpdate::ObjectNumberUpdate(List *s) : subject(s) {
    s->registerObserver(this);
}

void ObjectNumberUpdate::update() {
    std::cout << "total number of elements: " << subject->TotalObjectsnumber() << std::endl;
}

ObjectNumberUpdate::~ObjectNumberUpdate() {
    subject->unregisterObserver(this);
}