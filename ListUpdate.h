//
// Created by Donat on 22/12/2023.
//

#ifndef UNTITLED18_LISTUPDATE_H
#define UNTITLED18_LISTUPDATE_H

#include "Subject.h"
#include "Shoppinglist.h"

class ListUpdate : public Observer {
public:
    ListUpdate(ShoppingList *s);

    void update() override;

    ~ListUpdate() override;

private:
    ShoppingList *subject;
};


#endif //OBSERVER_H_LISTUPDATE_H
