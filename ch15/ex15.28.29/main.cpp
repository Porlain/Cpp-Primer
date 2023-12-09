/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-07 14:05:05
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "quote.cpp"
#include "bulk_quote.cpp"
#include "disc_quote.cpp"

int main()
{
    std::vector<Quote> vec;
    for (size_t i = 1; i != 10; ++i)
        vec.push_back(Bulk_quote("sss", i * 10.1, 10, 0.3));

    double total = 0;
    for (auto i : vec)
        total += i.net_price(20);

    std::cout << total << std::endl;

    std::cout << "======================\n\n";

    std::vector<std::shared_ptr<Quote>> vec2;
    for (unsigned i = 1; i != 10; ++i)
        vec2.push_back(std::make_shared<Bulk_quote>(Bulk_quote("sss", i * 10.1, 10, 0.3)));
    
    total = 0;
    for (auto i : vec2)
        total += i->net_price(20);
    std::cout << total << std::endl;

    return 0;
}