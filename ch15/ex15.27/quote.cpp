/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-07 10:41:59
 */
#include "quote.h"
#include <iostream>

bool operator!=(const Quote &lhs, const Quote &rhs)
{
    return (lhs.bookNo != rhs.bookNo) && (lhs.price != rhs.price);
}

void Quote::debug() const
{
    std::cout << "data members of this class:\n"
              << "bookNo= " << this->bookNo << " "
              << "price= " << this->price << " ";
}

Quote &Quote::operator=(const Quote &rhs)
{
    bookNo = rhs.bookNo;
    price = rhs.price;
    std::cout << "Quote: copy =() \n";
    return *this;
}

Quote &Quote::operator=(Quote &&rhs) noexcept
{
    if (*this != rhs)
    {
        bookNo = std::move(rhs.bookNo);
        price = std::move(rhs.price);
    }
    std::cout << "Quote: move =() \n";
    return *this;
}
