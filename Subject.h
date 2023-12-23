//
// Created by Donat on 31/08/2023.
//

#ifndef UNTITLED18_SUBJECT_H
#define UNTITLED18_SUBJECT_H


#include "Observer.h"

class Subject {
public:
    virtual void registerObserver(Observer *o) = 0;

    virtual void unregisterObserver(Observer *o) = 0;

    virtual void notify() = 0;

    virtual ~Subject() {}

};

#endif UNTITLED18_SUBJECT_H