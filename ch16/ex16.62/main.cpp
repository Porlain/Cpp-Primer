/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-18 14:05:16
 */
#include <iostream>
#include <memory>
#include <unordered_set>
#include "Sales_data.cpp"

int main()
{
    // test for ex16.62
    std::unordered_multiset<Sales_data> mset;
    Sales_data sd("Bible", 10, 0.98);

    mset.emplace(sd);
    mset.emplace("C++ Primer", 5, 9.99);

    for(const auto &item : mset)
        std::cout << "the hash code of " << item.isbn()
                  <<":\n0x" << std::hex << std::hash<Sales_data>()(item)
                  << "\n";

    return 0;
}