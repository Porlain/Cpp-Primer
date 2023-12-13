/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-12 14:32:25
 * @See ex13_39.h
 */
#ifndef VEC_H
#define VEC_H
#include <memory>

template <typename T>
class Vec
{
public:
    Vec() : elements(nullptr), cap(nullptr), first_free(nullptr) {}
    Vec(const Vec &);
    Vec(std::initializer_list<T>);
    Vec &operator=(const Vec &);
    ~Vec();

public:
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }

    T *begin() const { return elements; }
    T *end() const { return first_free; }

    void push_back(const T &);

public:
    void reserve(size_t new_cap);
    void resize(size_t count);
    void resize(size_t count, const T &);

private:
    std::pair<T *, T *> alloc_n_copy(const T *, const T *);
    void free();
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    void reallocate();

private:
    T *elements;
    T *cap;
    T *first_free;
    std::allocator<T> alloc;
};

template <typename T>
Vec<T>::Vec(const Vec<T> &rhs)
{
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    elements = newdata.first;
    first_free = newdata.second;
}

template <typename T>
Vec<T>::Vec(std::initializer_list<T> rhs)
{
    T *const newData = alloc.allocate(rhs.size());

    // copy elements from l to the address allocated
    T *p = newData;
    for (const auto &t : rhs)
        alloc.construct(p++, t);

    // build data structure
    elements = newData;
    first_free = cap = elements + rhs.size();
}

template <typename T>
Vec<T> &Vec<T>::operator=(const Vec &rhs)
{
    std::pair<T*, T*> newdata = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = newdata.first;
    first_free = cap = newdata.second;
    return *this;
}

template <typename T>
Vec<T>::~Vec() { free(); }

template <typename T>
void Vec<T>::push_back(const T &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

template <typename T>
void Vec<T>::reserve(size_t new_cap)
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

template <typename T>
void Vec<T>::resize(size_t count)
{
    resize(count, T());
}

template <typename T>
void Vec<T>::resize(size_t count, const T &s)
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

template <typename T>
std::pair<T *, T *> Vec<T>::alloc_n_copy(const T *b, const T *e)
{
    T *data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

template <typename T>
void Vec<T>::free()
{
    if (elements)
    {
        for (auto p = first_free; p != elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

template <typename T>
void Vec<T>::reallocate()
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

#endif