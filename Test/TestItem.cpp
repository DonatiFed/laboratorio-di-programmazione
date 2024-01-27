//
// Created by Donat on 18/09/2023.
//

#include <gtest/gtest.h>
#include "../Item.h"

TEST(ItemTest, Constructor) {
    std::cout << "Item Constructor test" << std::endl;
    std::string uom = "Kg";
    std::string categ = "milk";
    std::string name = "cream";
    Item i(uom, 2, categ, name, false);
    std::cout << "Item Constructor test done" << std::endl;
}

