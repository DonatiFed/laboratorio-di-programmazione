//
// Created by Donat on 29/08/2023.
//

#ifndef UNTITLED18_ITEM_H
#define UNTITLED18_ITEM_H


#include <iostream>

class Item {
public:
    Item(const std::string &u, int q, const std::string &c, const std::string &n, bool b);

    int getQuantity() const;

    bool isBought() const;

    void setName(const std::string &name);

    std::string getName() const;

    void setCategory(const std::string &category);

    void setQuantity(int quantity);

    void setUnitOfMeasure(const std::string &unitOfMeasure);

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