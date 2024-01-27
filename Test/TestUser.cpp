//
// Created by Donat on 18/09/2023.
//
#include <gtest/gtest.h>
#include "../User.h"

TEST(Usertest, Constructor) {
    std::cout << "User Constructor test" << std::endl;
    std::string name = "Donat";
    User u(name);
    std::cout << "User Constructor test done" << std::endl;


}

TEST(Usertest, Changename) {
    std::cout << "User method Changename test" << std::endl;
    std::string name = "Donat";
    User u(name);
    std::string name2 = "Donat2";
    u.changeName(name2);
    std::cout << "User method Changename test done" << std::endl;

}

TEST(Usertest, AddList) {
    std::cout << "User method AddList test" << std::endl;
    std::string name = "Donat";
    User u(name);
    std::string list1name = "List1";
    std::string list2name = "List2";

    ShoppingList l(list2name);
    u.addList(list1name);
    u.addList(&l);
    std::cout << "User method AddList test done" << std::endl;

}

TEST(Usertest, RemoveList){
std::cout << "User method RemoveList test" << std::endl;
    std::string name = "Donat";
    User u(name);
    std::string list1name = "List1";
    std::string list2name = "List2";
    ShoppingList l(list2name);
    u.addList(list1name);
    u.addList(&l);
    u.removeList("List1");
    u.removeList("List2");
    std::cout << "User method RemoveList test done" << std::endl;

}

TEST(Usertest, PrintLists) {
    std::cout << "User method PrintLists test" << std::endl;
    std::string name = "Donat";
    User u(name);
    std::string list1name = "List1";
    std::string list2name = "List2";
    ShoppingList l(list2name);
    u.addList(list1name);
    u.addList(&l);
    std::cout << "User method PrintLists test done" << std::endl;

}

TEST(Usertest, GetLists) {
    std::cout << "User method GetLists test" << std::endl;
    std::string name = "Donat";
    User u(name);
    std::string list1name = "List1";
    std::string list2name = "List2";
    ShoppingList l(list2name);
    u.addList(list1name);
    u.addList(&l);
    u.getLists();
    std::cout << "User method GetLists test done" << std::endl;
}



