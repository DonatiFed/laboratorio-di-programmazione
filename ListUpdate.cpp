//
// Created by Donat on 22/12/2023.
//

#include "ListUpdate.h"
#include <iostream>

ListUpdate::ListUpdate(List *s) : subject(s) {
    s->registerObserver(this);
}

void ListUpdate::update() {
    std::cout << "list elements: " << subject->totelementslist() << std::endl;
    std::cout << "tobuy elements: " << subject->tobuyelementslist() << std::endl;
}

ListUpdate::~ListUpdate() {
    subject->unregisterObserver(this);
}