/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-11 15:41:54
 * Rewrite according to the content of this chapter
 */
#ifndef BLOBPTR_H
#define BLOBPTR_H

#include "Blob.h"
#include <memory>
#include <vector>

// Note
// The overload of template operators needs to be declared before being declared within the class,
// and the class name in the parameters needs to be declared
template <typename>
class BlobPtr;

template <typename T>
bool operator==(const BlobPtr<T> &, const BlobPtr<T> &);

template <typename T>
bool operator<(const BlobPtr<T> &, const BlobPtr<T> &);

template <typename T>
class BlobPtr
{
public:
    T &operator*() const;
    friend bool operator== <T>(const BlobPtr<T> &, const BlobPtr<T> &);
    friend bool operator< <T>(const BlobPtr<T> &, const BlobPtr<T> &);

public:
    BlobPtr() : curr(0) {}
    BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

    // prefix
    BlobPtr &operator++();
    BlobPtr &operator--();

    // postfix
    BlobPtr operator++(int);
    BlobPtr operator--(int);

private:
    shared_ptr<vector<T>> check(size_t i, const T &msg) const;
    std::weak_ptr<vector<T>> wptr;
    size_t curr;
};

template <typename T>
T &BlobPtr<T>::operator*() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return lhs.curr < rhs.curr;
}

template <typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return lhs.curr == rhs.curr;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator++()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator--()
{
    --curr;
    check(curr, "increment past end of StrBlobPtr");
    return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    BlobPtr<T> ret = *this;
    ++*this;
    return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
    BlobPtr<T> ret = *this;
    --*this;
    return ret;
}

#endif