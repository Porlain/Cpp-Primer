#include "ex13_44.h"
#include <iostream>
#include <algorithm>
#include <cstring>

String::String(const char *c)
{
    auto newchar = alloc_n_copy(c, c + std::strlen(c));
    elements = newchar.first;
    end = newchar.second;
}

String::String(const String &rhs)
{
    auto newchar = alloc_n_copy(rhs.elements, rhs.end);
    elements = newchar.first;
    end = newchar.second;
}

String &String::operator=(const String &rhs)
{
    auto newchar = alloc_n_copy(rhs.elements, rhs.end);
    free();
    elements = newchar.first;
    end = newchar.second;
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
    return {str, std::uninitialized_copy(b, e, str++)};
}