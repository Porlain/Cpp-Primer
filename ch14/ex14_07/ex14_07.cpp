/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-30 16:04:59
 */
#include "ex14_07.h"
#include <iostream>
#include <algorithm>
#include <cstring>

std::ostream &operator<<(std::ostream &out, const String &s)
{
    for (auto c : s)
        out << c;
    return out;
}

String::String(const char *s)
{
    char *sl = const_cast<char *>(s);
    while (*sl)
        ++sl;
    auto newstr = alloc_n_copy(s, ++sl);
    elements = newstr.first;
    end_ = newstr.second;
}

String::String(const String &rhs)
{
    auto newchar = alloc_n_copy(rhs.elements, rhs.end_);
    elements = newchar.first;
    end_ = newchar.second;
    std::cout << "copy constructor" << std::endl;
}

String &String::operator=(const String &rhs)
{
    auto newchar = alloc_n_copy(rhs.elements, rhs.end_);
    free();
    elements = newchar.first;
    end_ = newchar.second;
    std::cout << "copy-assignment" << std::endl;
    return *this;
}

String::String(String &&s) noexcept : elements(s.elements), end_(s.end_)
{
    std::cout << "move constructor" << std::endl;
    s.elements = s.end_ = nullptr;
}

String &String::operator=(String &&rhs) noexcept
{
    std::cout << "call move assignment operator" << std::endl;
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        end_ = rhs.end_;
        rhs.elements = rhs.end_ = nullptr;
    }
    return *this;
}

String::~String() { free(); }

void String::free()
{
    if (elements)
    {
        std::for_each(elements, end_, [this](char &c)
                      { alloc.destroy(&c); });
        alloc.deallocate(elements, end_ - elements);
    }
}

std::pair<char *, char *> String::alloc_n_copy(const char *b, const char *e)
{
    auto str = alloc.allocate(e - b);
    return {str, std::uninitialized_copy(b, e, str)};
}