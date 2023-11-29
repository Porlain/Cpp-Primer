/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-29 13:55:36
 */
#include "ex13_47.h"
#include <iostream>
#include <algorithm>
#include <cstring>

String::String(const char *s)
{   
    char *sl = const_cast<char*>(s);
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