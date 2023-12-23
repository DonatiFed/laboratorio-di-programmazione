//
// Created by Donat on 22/12/2023.
//
#include <gtest/gtest.h>
#include "../Subject.h"
#include "../ListUpdate.h"
#include "../ObjectNumberUpdate.h"
#include "../ObjectToBuyUpdate.h"
#include <iostream>


TEST(ListUpdateTest, AddObserver) {
    std::string list1name = "List1";
    List *s = new List(list1name);
    ListUpdate *o = new ListUpdate(s);
}

TEST(ListUpdateTest, Update) {
    std::string list1name = "List1";
    List *s = new List(list1name);
    ObjectNumberUpdate *o2 = new ObjectNumberUpdate(s);
    ObjectToBuyUpdate *o3 = new ObjectToBuyUpdate(s);
    ListUpdate *o = new ListUpdate(s);


    Item cream("Kg", 2, "milk", "cream", false);
    Item icecream("Kg", 2, "milk", "icecream", false);
    Item yogurt("g", 500, "milk", "yogurt", false);
    Item milk("l", 3, "milk", "milk", false);
    Item cheese("Kg", 2, "milk", "cheese", false);
    Item eggs("number", -3, "protein foods", "eggs", false);
    s->addItem(cream);
    s->addItem(icecream);
    s->addItem(yogurt);
    s->addItem(milk);
    s->addItem(cheese);
    s->addItem(eggs);
    s->changeBought("cream", true);
    s->removeItem("yogurt");
    delete o;
    delete s;


}