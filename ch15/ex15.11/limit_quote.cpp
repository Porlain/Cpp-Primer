/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-06 10:29:14
 */
#include "limit_quote.h"
#include <iostream>

double Limit_quote::net_price(std::size_t n) const
{
    if (n > max_qty)
        return max_qty * price * (1 - discount) + (n - max_qty) * price;
    return n * (1 - discount) * price;
}

void Limit_quote::debug() const
{
	Quote::debug();
    std::cout << "max_qty= " << this->max_qty << " "
              << "discount= " << this->discount<< " ";
}