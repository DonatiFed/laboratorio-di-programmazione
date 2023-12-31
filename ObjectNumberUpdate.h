//
// Created by Donat on 31/08/2023.
//

#ifndef UNTITLED18_OBJECTNUMBERUPDATE_H
#define UNTITLED18_OBJECTNUMBERUPDATE_H


#include "Subject.h"
#include "List.h"

class ObjectNumberUpdate : public Observer {
public:
    ObjectNumberUpdate(List *s);

    void update() override;

    ~ObjectNumberUpdate() override;

private:
    List *subject;
};

#endif //UNTITLED18_OBJECTNUMBERUPDATE_H