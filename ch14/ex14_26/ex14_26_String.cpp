/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-02 14:06:57
 */

#include "ex14_26_String.h"
#include <algorithm>
#include <iostream>

/*
 *    public operator
 */

std::ostream &operator<<(std::ostream &out, const String &s)
{
    out << s.elements;
    return out;
}

std::istream &operator>>(std::istream &in, String &s)
{
    for (char c; (in >> c) && (c != '\0');)
        s.push_back(c);
    return in;
}

bool operator==(const String &lhs, const String &rhs)
{
    return (lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

bool operator!=(const String &lhs, const String &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const String &lhs, const String &rhs)
{
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

bool operator>(const String &lhs, const String &rhs)
{
    return rhs < lhs;
}

bool operator<=(const String &lhs, const String &rhs)
{
    return !(rhs < lhs);
}

bool operator>=(const String &lhs, const String &rhs)
{
    return !(lhs < rhs);
}

String &String::operator=(const String &rhs)
{
    auto newstr = alloc_n_copy(rhs.elements, rhs.first_free);
    free();
    elements = newstr.first;
    first_free = cap = newstr.second;
    end_ = first_free - 1;
    return *this;
}

String &String::operator=(String &&rhs) noexcept
{
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        end_ = rhs.end_;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.end_ = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

/*
 *    public constructor function
 */

String::String(const char *s)
{
    char *sl = const_cast<char *>(s);
    while (*sl)
        ++sl;
    range_initializer(s, ++sl);
}

String::String(const String &rhs)
{
    range_initializer(rhs.elements, rhs.first_free);
}

String::String(String &&s) noexcept : elements(s.elements), end_(s.end_), first_free(s.first_free), cap(s.cap)
{
    s.elements = s.end_ = s.first_free = s.cap = nullptr;
}

String::~String() { free(); }

/*
 *    public functional
 */

void String::reserve(size_t new_cap)
{
    if (new_cap <= capacity())
        return;
    alloc_n_move(new_cap);
}

void String::resize(size_t count, char c)
{
    if (count > size())
    {
        if (count > capacity())
            reserve(count * 2);
        for (size_t i = size(); i != count; ++i)
        {
            *end_++ = c;
            alloc.construct(first_free++, '\0');
        }
    }
    else if (count < size())
    {
        while (end_ != elements + count)
        {
            --end_;
            alloc.destroy(--first_free);
        }
        *end_ = '\0';
    }
}

void String::resize(size_t count)
{
    resize(count, ' ');
}

void String::push_back(const char c)
{
    chk_n_alloc();
    *end_ = c;
    end_ = first_free;
    alloc.construct(first_free++, '\0');
}

void String::free()
{
    if (elements)
    {
        std::for_each(elements, end_, [this](char &c)
                      { alloc.destroy(&c); });
        alloc.deallocate(elements, end_ - elements);
    }
}

/*
 *    private functional
 */

std::pair<char *, char *> String::alloc_n_copy(const char *b, const char *e)
{
    auto str = alloc.allocate(e - b);
    return {str, std::uninitialized_copy(b, e, str)};
}

void String::alloc_n_move(size_t new_cap)
{
    auto newdata = alloc.allocate(new_cap);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size() + 1; ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    end_ = dest - 1;
    first_free = dest;
    cap = elements + new_cap;
}

void String::range_initializer(const char *first, const char *last)
{
    auto newstr = alloc_n_copy(first, last);
    elements = newstr.first;
    first_free = cap = newstr.second;
    end_ = first_free - 1;
}

void String::chk_n_alloc()
{
    if (first_free == cap)
        reallocate();
}

void String::reallocate()
{
    //	\0    |    -
    //  ^          ^
    // elements    first_free
    // last_elem   cap

    auto newcapacity = size() ? 2 * (size() + 1) : 2;
    alloc_n_move(newcapacity);
}
