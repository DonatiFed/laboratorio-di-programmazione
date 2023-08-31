//
// Created by Donat on 31/08/2023.
//
#include <iostream>
#include <map>

#include "List.h"

List::List(std::string n) :name(n),totalobjects(0),tobuyobjects(0){
    categories.insert(std::make_pair(1,"Fruit"));
    categories.insert(std::make_pair(2,"Vegetable"));
    categories.insert(std::make_pair(3,"Meat"));
    categories.insert(std::make_pair(4,"Fish"));
    categories.insert(std::make_pair(5,"Dairy"));
    categories.insert(std::make_pair(6,"Bakery"));
    categories.insert(std::make_pair(7,"Sweets"));
    categories.insert(std::make_pair(8,"Drinks"));
    categories.insert(std::make_pair(9,"Cleaning"));
    categories.insert(std::make_pair(10,"Bathroom"));
    categories.insert(std::make_pair(11,"Other"));

    unitiesOfMeasure.insert(std::make_pair(1,"Kg"));
    unitiesOfMeasure.insert(std::make_pair(2,"g"));
    unitiesOfMeasure.insert(std::make_pair(3,"l"));
    unitiesOfMeasure.insert(std::make_pair(4,"ml"));
    unitiesOfMeasure.insert(std::make_pair(5,"Unities"));
}
std::string List::getName() {
    return name;
}
void List::setName(std::string name) {
    List::name=name;
}

void List::addItem() {
    std::cout<<"Enter the name of the item: "<<std::endl ;
    std::string n;
   std::cin>>n;
    bool categoryselected = false;
    std::string c;
    do {
        std::cout << "select the category for the item: " << std::endl;
        printCategories();
        int j;
        std::cin >> j;
        if (j <= 0) {
            std::cout << "select a number higher than 0" << std::endl;
            continue;
        }
        c=categories[j-1];
        categoryselected = true;
    } while (!categoryselected);

    std::cout<<"Enter the quantity of the item: "<<std::endl;

    int q;
    bool quantityselected=false;
    do {
        std::cin >> q;
        if (q <= 0) {
            std::cout << "Quantity must be a positive number higher than 0" << std::endl;
            continue;
        }
        quantityselected=true;
    } while (!quantityselected);

bool unityselected= false;
std::string u;
do {
std::cout << "select the unit of measure for the item: " << std::endl;
printUnitiesOfMeasure();
int k;
std::cin >> k;
if (k <= 0) {
std::cout << "select a number higher than 0" << std::endl;
continue;
}
 u=unitiesOfMeasure[k-1];
unityselected = true;
} while (!unityselected);

    Item i(n,c,q,u,false);
    list.insert(std::make_pair(n,i));
    totalobjects++;

    }

void List::removeItem() {
    std::cout<<"Which item do you want to remove?"<<std::endl;
    printList();
    int choice3;
    std::cin>>choice3;
    if (choice3<=0) {
        std::cout << "No item removed" << std::endl;
        return;
    }
    if (choice3>list.size()){
        std::cout<<"No item removed"<<std::endl;
        return;
    }
    int i=1;
    for(auto x:list){
        if(i==choice3){
            list.erase(x.first);
            std::cout<<"Item removed"<<std::endl;
            totalobjects--;
            return;
        }
        i++;
    }
}
void List::changeQuantity() {
    std::cout<<"Which item do you want to change in quantity?"<<std::endl;
    printList();
    int choice4;
    std::cin>>choice4;
    if (choice4=='0') {
        std::cout << "No item changed" << std::endl;
        return;
    }
    if (choice4>list.size()){
        std::cout<<"No item changed"<<std::endl;
        return;
    }
    int i=1;
    for(auto x:list){
        if(i==choice4){
            std::cout<<"Enter the new quantity: "<<std::endl;
            int q;
            std::cin>>q;
            if (q<=0){
                std::cout<<"Quantity must be a positive number higher than 0"<<std::endl;
                return;
            }
            x.second.setQuantity(q);
            std::cout<<"Quantity changed"<<std::endl;
            return;
        }
        i++;
    }

}



void List::changeUnitOfMeasure() {
    std::cout<<"Which item do you want to change in unit of measure?"<<std::endl;
    printList();
    int choice5;
    std::cin>>choice5;
    if (choice5<=0) {
        std::cout << "No item changed" << std::endl;
        return;
    }
    if (choice5>list.size()){
        std::cout<<"No item changed"<<std::endl;
        return;
    }
    int i=1;
    for(auto x:list){
        if(i==choice5) {
            bool unityselected = false;
            do {
                std::cout << "select new unit of measure for the item: " << std::endl;
                printUnitiesOfMeasure();
                int q;
                std::cin >> q;
                if (q <= 0) {
                    std::cout << "select a number higher than 0" << std::endl;
                    continue;
                }
                x.second.setUnitOfMeasure(unitiesOfMeasure[q-1]);
                std::cout << "Quantity changed" << std::endl;
                unityselected = true;
                return;

            } while (!unityselected);
            }
        i++;
        }
    }

void List::changeCategory() {
    std::cout<<"Which item do you want to change in category?"<<std::endl;
    printList();
    int choice6;
    std::cin>>choice6;
    if (choice6<=0) {
        std::cout << "No item changed" << std::endl;
        return;
    }
    if (choice6>list.size()){
        std::cout<<"No item changed"<<std::endl;
        return;
    }
    int i=1;
    for(auto x:list){
        if(i==choice6) {
            bool categoryselected = false;
            do {
                std::cout << "select new category for the item: " << std::endl;
                printCategories();
                int q;
                std::cin >> q;
                if (q <= 0) {
                    std::cout << "select a number higher than 0" << std::endl;
                    continue;
                }
                x.second.setCategory(categories[q-1]);
                std::cout << "Category changed" << std::endl;
                categoryselected = true;
                return;

            } while (!categoryselected);
        }
        i++;
    }
}

void List::changeBought() {
    std::cout<<"Which item have you bought/you need to buy?"<<std::endl;
    printList();
    int choice7;
    std::cin>>choice7;
    if (choice7<=0) {
        std::cout << "No item changed" << std::endl;
        return;
    }
    if (choice7>list.size()){
        std::cout<<"No item changed"<<std::endl;
        return;
    }
    int i=1;
    for(auto x:list){
        if(i==choice7){
            if(x.second.isBought()){
                x.second.setBought(false);
                tobuyobjects++;
                std::cout<<"Item set not to buy"<<std::endl;
                return;
            }
            else{
                x.second.setBought(true);
                tobuyobjects--;
                std::cout<<"Item set to buy"<<std::endl;
                return;
            }
        }
    }

}

void List::printList() {
    int i=1;
    for(auto x:list){
        std::cout<<i<<")  "<<x.first<<std::endl;
        i++;

    }
}
void List::printCategories() {
    for(auto x:categories){
        std::cout<<x.first<<")  "<<x.second<<std::endl;
    }
}
void List::printUnitiesOfMeasure() {
    for(auto x:unitiesOfMeasure){
        std::cout<<x.first<<")  "<<x.second<<std::endl;
    }
}
void List::printTotalObjects() {
    std::cout<<"Total objects: "<<totalobjects<<std::endl;
}
void List::printtObjectsToBuy() {
    std::cout<<"Objects to buy: "<<tobuyobjects<<std::endl;
}