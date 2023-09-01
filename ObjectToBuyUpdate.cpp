//
// Created by Donat on 31/08/2023.
//
#include <iostream>
#include "ObjectToBuyUpdate.h"

ObjectToBuyUpdate::ObjectToBuyUpdate(List *s):subject(s) {
    s->registerObserver(this);
}

void ObjectToBuyUpdate::update() {
    printObjectsToBuy();
}
void ObjectToBuyUpdate::printObjectsToBuy() {
    subject->printObjectsToBuy();
}
