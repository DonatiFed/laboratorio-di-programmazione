//
// Created by Donat on 29/08/2023.
//

#ifndef UNTITLED18_ITEM_H
#define UNTITLED18_ITEM_H

#endif //UNTITLED18_ITEM_H
#include <iostream>

class Item{
public:
Item(std::string n, std::string c, int q, std::string u, bool b);
    std::string getName();
    std::string getCategory();
    int getQuantity();
    std::string getUnitOfMeasure();
    bool isBought();
    void setName(std::string name);
    void setCategory(std::string category);
    void setQuantity(int quantity);
    void setUnitOfMeasure(std::string unitOfMeasure);
    void setBought(bool bought);


private:
    std::string name;
    std::string category;
    int quantity;
    std::string unitOfMeasure;
    bool bought;

};