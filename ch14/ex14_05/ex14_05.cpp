/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-30 15:51:43
 */
#include "ex14_05.h"

std::istream &operator>>(std::istream &in, Book &book)
{
    in >> book.isbn_ >> book.name_ >> book.author_ >> book.pubdate_;
    return in;
}

std::ostream &operator<<(std::ostream &out, const Book &book)
{
    out << book.isbn_ << book.name_ << book.author_ << book.pubdate_;
    return out;
}

bool operator==(const Book &lhs, const Book &rhs)
{
    return lhs.isbn_ == rhs.isbn_;
}

bool operator!=(const Book &lhs, const Book &rhs)
{
    return !(lhs.isbn_ == rhs.isbn_);
}