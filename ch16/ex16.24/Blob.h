/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-13 14:49:46
 * Rewrite according to the content of this chapter
 */
#ifndef BLOB_H
#define BLOB_H

#include <vector>
#include <memory>

using std::shared_ptr;
using std::string;
using std::vector;

template <typename T>
class Blob
{
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    // constructors
    Blob();
    Blob(std::initializer_list<T>);

    template <typename It>
    Blob(It, It);

    // number of elements in the Blob
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const T &t) { data->push_back(t); }
    void push_back(T &&s) { data->push_back(std::move(s)); }
    void pop_back();

    // element access
    T &front();
    T &back();
    T &operator[](size_type);
    const T &operator[](size_type) const;
    const T &front() const;
    const T &back() const;

private:
    shared_ptr<vector<T>> data;
    void check(size_type i, const T &msg) const;
};

template <typename T>
Blob<T>::Blob() : data(std::make_shared<vector<T>>()) {}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<vector<T>>(il)) {}

// constructor taking two iterators
template <typename T>  // for class
template <typename It> // for this member
Blob<T>::Blob(It b, It e) : data(std::make_shared<std::vector<T>>(b, e))
{
}

template <typename T>
void Blob<T>::check(size_type i, const T &msg) const
{
    if (i >= msg.size())
        throw std::out_of_range(msg);
}

template <typename T>
void Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <typename T>
T &Blob<T>::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

template <typename T>
T &Blob<T>::back()
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
T &Blob<T>::operator[](size_type n)
{
    check(n, "out of range");
    return data->at(n);
}

template <typename T>
const T &Blob<T>::operator[](size_type n) const
{
    check(n, "out of range");
    return data->at(n);
}

template <typename T>
const T &Blob<T>::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

template <typename T>
const T &Blob<T>::back() const
{
    check(0, "back on empty Blob");
    return data->back();
}

#endif