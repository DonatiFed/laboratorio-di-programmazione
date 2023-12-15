//
// Created by Donat on 31/08/2023.
//
#include <iostream>
#include <map>

#include "List.h"
#include "Subject.h"
#include "ObjectNumberUpdate.h"
List::List(std::string n) :name(n),totalobjects(0),tobuyobjects(0){
}

void List::setName(std::string name) {
    List::name=name;
}
std::string List::getName() {
    return name;
}

void List::addItem(std::string unitOfMeasure,  int quantity,std::string category,std::string name,  bool bought) {

        Item i(unitOfMeasure, quantity, category, name, false);
        list.insert(std::make_pair(name, i));
        totalobjects++;
        tobuyobjects++;
        notify();


        std::cout << "Item added" << std::endl;


}
void List::addItem(Item i) {
    list.insert(std::make_pair(i.getName(),i));
    totalobjects++;
    tobuyobjects++;
    notify();
    std::cout<<"Item added"<<std::endl;
}

void List::removeItem(std::string n) {
    auto it = list.find(n);
    if (it == list.end()) {
        std::cout << "No item removed" << std::endl;
    }
    else {
        list.erase(n);
        std::cout << "Item removed" << std::endl;
        totalobjects--;
        tobuyobjects--;
        notify();
    }
}




void List::changeBought(Item* i, bool b) {
    if(i== nullptr){
        std::cout<<"Item not found"<<std::endl;
        return;
    }
    if(i->isBought()==b){
        std::cout<<"no need to change"<<std::endl;
        return;
    }
    i->setBought(b);
    if(b==true){
        tobuyobjects--;
    }
    else{
        tobuyobjects++;
    }
    std::cout<<"Bought changed"<<std::endl;
    notify();
}

void List::printList() {
    int i=1;
    for(auto x:list){
        std::cout<<i<<")  "<<x.first<<std::endl;
        i++;

    }
}

void List::printTotalObjects() {
    std::cout<<"Total objects: "<<totalobjects<<std::endl;
}
void List::printObjectsToBuy() {
    std::cout<<"Objects to buy: "<<tobuyobjects<<std::endl;
}

void List::registerObserver(Observer *o) {
    obs.push_back(o);
}
void::List::unregisterObserver(Observer *o) {
    obs.remove(o);
}
void List::notify() {
    for(auto x:obs){
        x->update();
    }
}
void List::changeName(std::string n) {
    name=n;
}
std::map<std::string,Item> List::getList() {
    return list;
}


