//
// Created by Donat on 29/08/2023.
//

#ifndef UNTITLED18_ITEM_H
#define UNTITLED18_ITEM_H


#include <iostream>

class Item{
public:
Item(std::string u, int q, std::string c, std::string n,  bool b);

    int getQuantity();
    bool isBought();
    void setName(std::string name);
    std::string getName();
    void setCategory(std::string category);
    void setQuantity(int quantity);
    void setUnitOfMeasure(std::string unitOfMeasure);
    void setBought(bool b);


private:
    std::string unitOfMeasure;
    int quantity;
    std::string category;
    std::string name;

    bool bought;

};
#endif //UNTITLED18_ITEM_H