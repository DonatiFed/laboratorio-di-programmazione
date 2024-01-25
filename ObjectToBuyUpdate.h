//
// Created by Donat on 31/08/2023.
//

#ifndef UNTITLED18_OBJECTTOBUYUPDATE_H
#define UNTITLED18_OBJECTTOBUYUPDATE_H


#include "Subject.h"
#include "Shoppinglist.h"

class ObjectToBuyUpdate : public Observer {
public:
    ObjectToBuyUpdate(ShoppingList *s);

    void update() override;

    ~ObjectToBuyUpdate() override;

private:
    ShoppingList *subject;
};

#endif //UNTITLED18_OBJECTTOBUYUPDATE_H