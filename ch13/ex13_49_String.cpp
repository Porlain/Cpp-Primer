/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-29 15:12:06
 */
#include "ex13_49_String.h"
#include <iostream>
#include <algorithm>
#include <cstring>

String::String(const char *s)
{
    char *sl = const_cast<char *>(s);
    while (*sl)
        ++sl;
    auto newstr = alloc_n_copy(s, ++sl);
    elements = newstr.first;
    end = newstr.second;
}

String::String(const String &rhs)
{
    auto newchar = alloc_n_copy(rhs.elements, rhs.end);
    elements = newchar.first;
    end = newchar.second;
    std::cout << "copy constructor" << std::endl;
}

String &String::operator=(const String &rhs)
{
    auto newchar = alloc_n_copy(rhs.elements, rhs.end);
    free();
    elements = newchar.first;
    end = newchar.second;
    std::cout << "copy-assignment" << std::endl;
    return *this;
}

String::String(String &&s) noexcept : elements(s.elements), end(s.end)
{   
    std::cout << "move constructor" << std::endl;
    s.elements = s.end = nullptr;
}

String &String::operator=(String &&rhs) noexcept
{   
    std::cout << "call move assignment operator" << std::endl;
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        end = rhs.end;
        rhs.elements = rhs.end = nullptr;
    }
    return *this;
}

String::~String() { free(); }

void String::free()
{
    if (elements)
    {
        std::for_each(elements, end, [this](char &c)
                      { alloc.destroy(&c); });
        alloc.deallocate(elements, end - elements);
    }
}

std::pair<char *, char *> String::alloc_n_copy(const char *b, const char *e)
{
    auto str = alloc.allocate(e - b);
    return {str, std::uninitialized_copy(b, e, str)};
}