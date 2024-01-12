//
// Created by Donat on 29/08/2023.
//

#ifndef UNTITLED18_ITEM_H
#define UNTITLED18_ITEM_H


#include <iostream>

class Item {
public:
    Item(std::string &u, int q, std::string &c, std::string &n, bool b);

    int getQuantity() const;

    bool isBought() const;

    void setName(const std::string &name);

    std::string getName() const;

    void setCategory(std::string &category);

    void setQuantity(int quantity);

    void setUnitOfMeasure(std::string &unitOfMeasure);

    void setBought(bool b);

    const std::string &getUnitOfMeasure() const;

    const std::string &getCategory() const;


private:
    std::string unitOfMeasure;
    int quantity;
    std::string category;
    std::string name;

    bool bought;

};

#endif //UNTITLED18_ITEM_H