/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-07 10:53:17
 */
#include "disc_quote.h"

bool operator!=(const Disc_quote &lhs, const Disc_quote &rhs)
{
    return (Quote(lhs) != Quote(rhs)) && (lhs.quantity != rhs.quantity) && (lhs.discount != rhs.discount);
}

Disc_quote &Disc_quote::operator=(const Disc_quote &rhs)
{
    Quote::operator=(rhs);
    quantity = rhs.quantity;
    discount = rhs.discount;
    std::cout << "Disc_quote : copy =()\n";
    return *this;
}

Disc_quote &Disc_quote::operator=(Disc_quote &&rhs)noexcept
{
    if (*this != rhs)
    {
        Quote::operator=(std::move(rhs));
        quantity = std::move(rhs.quantity);
        discount = std::move(rhs.discount);
    }

    std::cout << "Disc_quote : move =()\n";
    return *this;
}
