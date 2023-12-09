/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-07 15:44:31
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

double print_total(std::ostream &os, const Quote &item, size_t n)
{
    // depending on the type of the object bound to the item parameter
    // calls either Quote::net_price or Bulk_quote::net_price
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() // calls Quote::isbn
       << " # sold: " << n << " total due: " << ret << std::endl;
     return ret;
}