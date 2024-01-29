//
// Created by Donat on 18/09/2023.
//

#include <gtest/gtest.h>
#include "../Shoppinglist.h"
#include "../Item.h"


TEST(ListTest, Constructor) {
    std::cout<< "List Constructor test" << std::endl;
    std::string list1name = "List1";
    ShoppingList l(list1name);
    EXPECT_EQ(l.getName(), list1name);
    EXPECT_EQ(l.totalObjectsNumber(), 0);
    EXPECT_EQ(l.toBuyNumber(), 0);
    std::cout<< "List Constructor test done" << std::endl;
}

TEST(ListTest, AddObject) {
    std::cout << "List method AddObject test" << std::endl;
    std::string list1name = "List1";
    ShoppingList l(list1name);
    std::string uom = "Kg";
    std::string categ = "milk";
    std::string name = "icecream";
    l.addItem(uom, 2, categ, name, false);
    EXPECT_EQ(l.totalObjectsNumber(), 1);
    EXPECT_EQ(l.toBuyNumber(), 1);
    std::cout << "List method AddObject test done" << std::endl;

}

TEST(ListTest, RemoveObject) {
    std::cout << "List method RemoveObject test" << std::endl;
    std::string list1name = "List1";
    ShoppingList l(list1name);
    std::string uom = "Kg";
    std::string categ = "milk";
    std::string name = "yogurt";
    l.addItem(uom, 2, categ, name, false);
    l.removeItem("yogurt");
    EXPECT_EQ(l.totalObjectsNumber(), 0);
    EXPECT_EQ(l.toBuyNumber(), 0);
    std::cout << "List method RemoveObject test done" << std::endl;
}

TEST(ListTest, ChangeBought) {
    std::cout << "List method ChangeBought test" << std::endl;
    std::string list1name = "List1";
    ShoppingList l(list1name);
    std::string uom = "Kg";
    std::string categ = "milk";
    std::string name = "yogurt";
    Item i(uom, 2, categ, name, false);
    l.addItem(i);
    l.changeBought(i.getName(), true);
    EXPECT_EQ(l.totalObjectsNumber(), 1);
    EXPECT_EQ(l.toBuyNumber(), 0);
    std::cout << "List method ChangeBought test done" << std::endl;
}

TEST(ListTest, totelementsList) {
    std::cout << "List method totElementsList test" << std::endl;
    std::string list1name = "List1";
    ShoppingList l(list1name);
    std::string uom = "Kg";
    std::string categ = "milk";
    std::string name = "milk";
    l.addItem(uom, 2, categ, name, false);
    l.totElementsList();
    EXPECT_EQ(l.totElementsList(), "\nList1 2 Kg milk");
    std::cout << "List method totElementsList test done" << std::endl;
}


