/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-06 14:03:53
 */
#include "bulk_quote.h"
#include <iostream>

double Bulk_quote::net_price(std::size_t n) const
{
    if (n >= quantity)
        return n * (1 - discount) * price;
    return n * price;
}

void Bulk_quote::debug() const
{
	Quote::debug();
    std::cout << "min_qty= " << this->quantity << " "
              << "discount= " << this->discount<< " ";
}