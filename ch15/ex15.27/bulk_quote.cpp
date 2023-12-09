/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-07 11:00:17
 */
#include "bulk_quote.h"
#include <iostream>

Bulk_quote &Bulk_quote::operator=(const Bulk_quote &rhs)
{
    Disc_quote::operator=(rhs);
    std::cout << "Bulk_quote : copy =()\n";
    return *this;
}

Bulk_quote &Bulk_quote::operator=(Bulk_quote &&rhs)noexcept
{
    Disc_quote::operator=(std::move(rhs));
    std::cout << "Bulk_quote : move =()\n";
    return *this;
}

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
              << "discount= " << this->discount << " ";
}
