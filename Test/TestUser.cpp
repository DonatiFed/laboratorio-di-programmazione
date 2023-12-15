//
// Created by Donat on 18/09/2023.
//
#include <gtest/gtest.h>
#include "../User.h"
TEST(Usertest, Constructor) {
    User u("Donat");


}
TEST(Usertest, Changename) {
    User u("Donat");
    u.changeName("Donat2");

}
TEST(Usertest, AddList) {
    User u("Donat");
    List l("List2");
    u.addList("List1");
    u.addList(&l);

}
TEST(Usertest, RemoveList) {
    User u("Donat");
    List l("List2");
    u.addList("List1");
    u.addList(&l);
    u.removeList("List1");
    u.removeList("List2");

}
TEST(Usertest, PrintLists) {
    User u("Donat");
    List l("List2");
    u.addList("List1");
    u.addList(&l);
    u.printLists();

}
TEST(Usertest, GetLists) {
    User u("Donat");
    List l("List2");
    u.addList("List1");
    u.addList(&l);
    u.getLists();

}
TEST(Usertest,printLists){
    User u("Donat");
    List l("List2");
    u.addList("List1");
    u.addList(&l);
    u.printLists();
}