/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-07 15:50:19
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "quote.cpp"
#include "bulk_quote.cpp"
#include "disc_quote.cpp"
#include "basket.cpp"

int main()
{
    Basket basket;

    for (unsigned i = 0; i != 10; ++i)
        basket.add_item(Bulk_quote("Bible", 20.6, 20, 0.3));

    for (unsigned i = 0; i != 10; ++i)
        basket.add_item(Bulk_quote("C++Primer", 30.9, 5, 0.4));

    for (unsigned i = 0; i != 10; ++i)
        basket.add_item(Quote("CLRS", 40.1));

    basket.total_receipt(std::cout);
    return 0;
}
