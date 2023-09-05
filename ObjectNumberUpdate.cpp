//
// Created by Donat on 31/08/2023.
//
#include "ObjectNumberUpdate.h"
#include <iostream>

ObjectNumberUpdate::ObjectNumberUpdate(List *s):subject(s) {
    s->registerObserver(this);
}

void ObjectNumberUpdate::update() {
    subject->printTotalObjects();
}
ObjectNumberUpdate::~ObjectNumberUpdate() {
    subject->unregisterObserver(this);
}