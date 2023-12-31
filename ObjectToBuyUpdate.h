//
// Created by Donat on 31/08/2023.
//

#ifndef UNTITLED18_OBJECTTOBUYUPDATE_H
#define UNTITLED18_OBJECTTOBUYUPDATE_H


#include "Subject.h"
#include "List.h"

class ObjectToBuyUpdate : public Observer {
public:
    ObjectToBuyUpdate(List *s);

    void update() override;

    ~ObjectToBuyUpdate() override;

private:
    List *subject;
};

#endif //UNTITLED18_OBJECTTOBUYUPDATE_H