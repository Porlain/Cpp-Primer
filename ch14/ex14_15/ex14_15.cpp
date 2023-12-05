/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-30 17:23:30
 */
#include "ex14_15.h"

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

bool operator>(const Book &lhs, const Book &rhs)
{
    return lhs.isbn_ > rhs.isbn_;
}

bool operator<(const Book &lhs, const Book &rhs)
{
    return rhs > lhs;
}

Book operator+(const Book &lhs, const Book &rhs)
{
    Book sum = lhs;
    sum += rhs;
    return sum;
}

Book operator-(const Book &lhs, const Book &rhs)
{
    Book sum = lhs;
    sum -= rhs;
    return sum;
}

Book &Book::operator+=(const Book &rhs)
{
    if (rhs == *this)
        this->number_ += rhs.number_;
    return *this;
}

Book &Book::operator-=(const Book &rhs)
{
    if (rhs == *this)
        this->number_ -= rhs.number_;
    return *this;
}
