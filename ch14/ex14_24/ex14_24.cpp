/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-02 11:14:09
 */
#include "ex14_24.h"

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

Book &Book::operator=(const Book &rhs)
{
    this->isbn_ = rhs.isbn_;
    this->name_ = rhs.name_;
    this->author_ = rhs.author_;
    this->pubdate_ = rhs.pubdate_;
    return *this;
}

Book &Book::operator=(const Book &&rhs) noexcept
{
    if (this != &rhs)
    {
        this->isbn_ = rhs.isbn_;
        this->name_ = rhs.name_;
        this->author_ = rhs.author_;
        this->pubdate_ = rhs.pubdate_;
    }

    return *this;
}
