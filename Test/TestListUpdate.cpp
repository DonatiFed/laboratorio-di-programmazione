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
    std::cout << "ListUpdate method AddObserver test" << std::endl;
    std::string list1name = "List1";
    ShoppingList *s = new ShoppingList(list1name);
    auto *o = new ListUpdate(s);
    EXPECT_EQ(s->getObs().size(), 1);
    std::cout << "ListUpdate method AddObserver test done" << std::endl;
}

TEST(ListUpdateTest, Update) {
    std::cout << "ListUpdate method Update test" << std::endl;
    std::string list1name = "List1";
    ShoppingList *s = new ShoppingList(list1name);
    auto *o2 = new ObjectNumberUpdate(s);
    auto *o3 = new ObjectToBuyUpdate(s);
    auto *o = new ListUpdate(s);
    EXPECT_EQ(s->getObs().size(), 3);

    std::string uom1 = "Kg";
    std::string categ1 = "milk";
    std::string name1 = "cream";
    Item cream(uom1, 2, categ1,name1 , false);

    std::string uom2 = "Kg";
    std::string categ2 = "milk";
    std::string name2 = "icecream";
    Item icecream(uom2, 2, categ2,name2 , false);

    std::string uom3 = "g";
    std::string categ3= "milk";
    std::string name3 = "yogurt";
    Item yogurt(uom3, 500, categ3,name3 , false);

    std::string uom4 = "l";
    std::string categ4 = "milk";
    std::string name4 = "milk";
    Item milk(uom4, 3, categ4,name4, false);

    std::string uom5 = "Kg";
    std::string categ5 = "milk";
    std::string name5 = "cheese";
    Item cheese(uom5, 2, categ5,name5 , false);

    std::string uom6 = "number";
    std::string categ6 = "protein foods";
    std::string name6= "eggs";
    Item eggs(uom5, -3, categ5,name5 , false);
    EXPECT_EQ(eggs.getQuantity(), 0);



    s->addItem(cream);
    EXPECT_EQ(s->totalObjectsNumber(), 1);
    EXPECT_EQ(s->toBuyNumber(), 1);
    s->addItem(icecream);
    EXPECT_EQ(s->totalObjectsNumber(), 2);
    EXPECT_EQ(s->toBuyNumber(), 2);
    s->addItem(yogurt);
    EXPECT_EQ(s->totalObjectsNumber(), 3);
    EXPECT_EQ(s->toBuyNumber(), 3);
    s->addItem(milk);
    EXPECT_EQ(s->totalObjectsNumber(), 4);
    EXPECT_EQ(s->toBuyNumber(), 4);
    s->addItem(cheese);
    EXPECT_EQ(s->totalObjectsNumber(), 5);
    EXPECT_EQ(s->toBuyNumber(), 5);
    s->addItem(eggs);
    EXPECT_EQ(s->totalObjectsNumber(), 6);
    EXPECT_EQ(s->toBuyNumber(), 5);
    s->changeBought("cream", true);
    EXPECT_EQ(s->totalObjectsNumber(),6);
    EXPECT_EQ(s->toBuyNumber(), 4);
    s->removeItem("yogurt");
    EXPECT_EQ(s->totalObjectsNumber(), 5);
    EXPECT_EQ(s->toBuyNumber(), 3);
    delete o;
    delete s;
    EXPECT_EQ(s->getObs().size(), 2);
    std::cout << "ListUpdate method Update test done" << std::endl;

}