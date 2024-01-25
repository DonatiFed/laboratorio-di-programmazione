//
// Created by Donat on 31/08/2023.
//

#ifndef UNTITLED18_OBJECTNUMBERUPDATE_H
#define UNTITLED18_OBJECTNUMBERUPDATE_H


#include "Subject.h"
#include "Shoppinglist.h"

class ObjectNumberUpdate : public Observer {
public:
    ObjectNumberUpdate(ShoppingList *s);

    void update() override;

    ~ObjectNumberUpdate() override;

private:
    ShoppingList *subject;
};

#endif //UNTITLED18_OBJECTNUMBERUPDATE_H