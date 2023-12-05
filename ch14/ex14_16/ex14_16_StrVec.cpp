/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-30 20:36:22
 */
#include "ex14_16_StrVec.h"

bool operator==(const StrVec &lhs, const StrVec &rhs)
{
    bool door = (lhs.size() == rhs.size()) && (lhs.capacity() == rhs.capacity()) && (std::equal(lhs.begin(), lhs.end(), rhs.begin()));
    return door;
}

bool operator!=(const StrVec &lhs, const StrVec &rhs)
{
    return !(lhs == rhs);
}

StrVec::StrVec(const StrVec &rhs)
{
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    elements = newdata.first;
    first_free = newdata.second;
}

StrVec::StrVec(std::initializer_list<std::string> il)
{
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = newdata.second;
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = newdata.first;
    first_free = newdata.second;
    return *this;
}

StrVec::StrVec(StrVec &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.first_free;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

StrVec::~StrVec() { free(); }

void StrVec::push_back(const std::string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

void StrVec::reserve(size_t new_cap)
{
    if (new_cap <= capacity())
        return;

    auto newdata = alloc.allocate(new_cap);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + new_cap;
}

void StrVec::resize(size_t count)
{
    resize(count, std::string());
}

void StrVec::resize(size_t count, const std::string &s)
{
    if (count > size())
    {
        if (count > capacity())
            reserve(count * 2);
        for (size_t i = size(); i != count; ++i)
            alloc.construct(first_free++, s);
    }
    else if (count < size())
    {
        while (first_free != elements + count)
            alloc.destroy(--first_free);
    }
}

std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if (elements)
    {
        for (auto p = first_free; p != elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::chk_n_alloc()
{
    if (size() == capacity())
        reallocate();
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}