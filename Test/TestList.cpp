//
// Created by Donat on 18/09/2023.
//

#include <gtest/gtest.h>
#include "../list.h"
#include "../Item.h"


TEST(ListTest, Constructor) {
    List l("List1");
}
TEST(ListTest, AddObject) {
    List l("List1");
    l.addItem("Kg", 2,"milk","yogurt", false);
}
TEST(ListTest, RemoveObject) {
    List l("List1");
    l.addItem("Kg", 2,"milk","yogurt", false);
    l.removeItem("yogurt");
}
TEST(ListTest, ChangeBought) {
    List l("List1");
    Item i("Kg", 1,"milk","yogurt", false);
    l.addItem(i);
    l.changeBought(&i,true);
}

TEST(ListTest, PrintList) {
    List l("List1");
    l.addItem("Kg", 1,"milk","yogurt", false);
    l.printList();
}
TEST(ListTest, PrintTotalObjects) {
    List l("List1");
    l.addItem("Kg", 1,"milk","yogurt", false);
    l.addItem("kg",1,"bakery","bread", false);

    l.printTotalObjects();
}
TEST(ListTest, PrintObjectsToBuy) {
    List l("List1");
    l.addItem("Kg", 1,"milk","yogurt", false);
    Item i("kg",1,"bakery","bread", false);
    l.addItem(i);
    l.changeBought(&i,true);
    l.printObjectsToBuy();

}
