#include <iostream>
#include <limits>
#include "User.h"


std::string &insertString() {
    std::string *s = new std::string("Hello, World!");
    std::cin >> *s;
    return *s;
}

std::string &insertName() {
    std::cout << "Insert the name:" << std::endl;
    return insertString();
}

std::string &insertCategory() {
    std::cout << "Insert the category:" << std::endl;

    return insertString();
}

int insertQuantity() {
    int n;
    while (true) {
        std::cout << "Insert the quantity: " << std::endl;
        if (std::cin >> n) { //controlla se l'input è un intero
            break;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora il resto della linea
            std::cout << "Invalid input. Please enter an integer." << std::endl;
        }
    }
    return n;
}

std::string &insertUnitOfMeasure() {
    std::cout << "Insert the unit of measure:" << std::endl;
    return insertString();
}

bool insertBought() {
    std::cout << "Did you buy the Item?" << std::endl;
    std::cout << "1) Yes" << std::endl;
    std::cout << "2) No" << std::endl;
    int choice;
    std::cin >> choice;
    if (choice == 1) {
        return true;
    }
    return false;
}

List *listSelection(User *u) {

    int n;
    bool listselected = false;
    do {
        std::cout << "Which list do you want to select?: " << std::endl;
        u->printLists();
        if (!(std::cin >> n)) {
            std::cout << "Invalid input. Please enter an integer." << std::endl;
            std::cin.clear(); // Ripristina lo stato di std::cin dopo un fallimento di input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Pulisci il buffer
            continue;
        }
        if (n <= 0) {
            std::cout << "Select a number higher than 0" << std::endl;
            continue;
        }
        if (n > u->getLists().size()) {
            std::cout << "Select a number lower than " << u->getLists().size() + 1 << std::endl;
            continue;
        }
        int i = 1;
        for (auto it = u->getLists().begin(); it != u->getLists().end(); it++) {
            if (i == n) {
                std::cout << "List " << it->second->getName() << ":" << std::endl;
                it->second->totelementslist();
                return it->second;
            }
            i++;
        }
    } while (!listselected);
}

Item *itemSelection(List *list) {
    if (list->getList().size() == 0) {
        std::cout << "You don't have any item in the list" << std::endl;
    }
    int number;
    bool itemselected = false;
    do {
        std::cout << "Select an item" << std::endl;
        list->totelementslist();
        std::cin >> number;
        if (number <= 0 || number > list->getList().size()) {
            std::cout << "Select a number between 0 and " << list->getList().size() + 1 << std::endl;
            continue;
        }
        int i = 1;
        for (auto it = list->getList().begin(); it != list->getList().end(); it++) {
            if (i == number) {
                return &(it->second);
            }
            i++;
        }
    } while (!itemselected);

}

void ItemManager(Item *item) {
    if (item == nullptr) {
        std::cout << "No item found" << std::endl;
        return;
    }
    bool continueiteration = true;
    char choice;
    do {
        std::cout << "What would you like to do to " << item->getName() << "?" << std::endl;
        std::cout << "1) Change name" << std::endl;
        std::cout << "2) Change category" << std::endl;
        std::cout << "3) Change quantity" << std::endl;
        std::cout << "4) Exit" << std::endl;

        std::cin >> choice;
        switch (choice) {
            case '1':
                item->setName(insertName());
                break;
            case '2':
                item->setCategory(insertCategory());
                break;
            case '3':
                item->setQuantity(insertQuantity());
                item->setUnitOfMeasure(insertUnitOfMeasure());
                break;
            case '4':
                continueiteration = false;
                break;
            default:
                std::cout << "Select a number between 1 and 5" << std::endl;
                break;
        }
    } while (continueiteration);
}

void ListManager(List *list) {
    if (list == nullptr) {
        std::cout << "No list found" << std::endl;
        return;
    }
    bool continueiteration = true;
    char choice;
    do {
        std::cout << "What would you like to do in " << list->getName() << "?" << std::endl;
        std::cout << "1) Add an item" << std::endl;
        std::cout << "2) Select an item" << std::endl;
        std::cout << "3) Remove an item" << std::endl;
        std::cout << "4) set item as bought/to buy" << std::endl;
        std::cout << "5) Change list's name" << std::endl;
        std::cout << "6) print the list" << std::endl;
        std::cout << "7) Exit" << std::endl;

        std::cin >> choice;
        switch (choice) {
            case '1':
                list->addItem(insertUnitOfMeasure(), insertQuantity(), insertCategory(), insertName(), false);
                break;
            case '2':
                if (list->getList().size() == 0) {
                    std::cout << "You don't have any item in the list" << std::endl;
                    break;
                }
                ItemManager(itemSelection(list));
                break;
            case '3':
                if (list->getList().size() == 0) {
                    std::cout << "You don't have any item in the list" << std::endl;
                    break;
                }
                list->removeItem(itemSelection(list)->getName());
                break;

            case '4':
                if (list->getList().size() == 0) {
                    std::cout << "You don't have any item in the list" << std::endl;
                    break;
                }
                list->changeBought(itemSelection(list)->getName(), insertBought());
                break;
            case '5':
                list->changeName(insertName());
                break;
            case '6':
                list->totelementslist();
                break;

            case '7':
                continueiteration = false;
                break;
            default:
                std::cout << "Select a number between 1 and 5" << std::endl;
                break;
        }
    } while (continueiteration);

}


void UserManager(User *u) {
    bool continueiteration = true;
    char choice;
    do {
        std::cout << u->getName() << ",What would you like to do?" << std::endl;
        std::cout << "1) Add a list" << std::endl;
        std::cout << "2) Select a list" << std::endl;
        std::cout << "3) Remove a list" << std::endl;
        std::cout << "4) Change name" << std::endl;
        std::cout << "5) Exit" << std::endl;

        std::cin >> choice;
        switch (choice) {
            case '1':

                std::cout << "Insert the name of the list:" << std::endl;
                u->addList(insertString());
                break;
            case '2':
                if (u->getLists().size() == 0) {
                    std::cout << "You don't have any list" << std::endl;
                    break;
                }
                ListManager(listSelection(u));
                break;
            case '3':
                if (u->getLists().size() == 0) {
                    std::cout << "You don't have any list" << std::endl;
                    break;
                }
                std::cout << "Select a list" << std::endl;
                u->printLists();
                u->removeList(listSelection(u)->getName());
                break;
            case '4':
                std::cout << "Insert the new name" << std::endl;
                u->changeName(insertString());
                break;
            case '5':
                std::cout << "Goodbye " << u->getName() << std::endl;
                continueiteration = false;
                break;
            default:
                std::cout << "Select a number between 1 and 4" << std::endl;
                break;
        }
    } while (continueiteration);
}


int main() {
    std::string name;
    std::cout << "Insert your name:" << std::endl;
    std::cin >> name;
    User u(name);
    UserManager(&u);
    return 0;
}