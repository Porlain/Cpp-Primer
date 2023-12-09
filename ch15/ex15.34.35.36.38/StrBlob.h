/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-07 20:34:06
 */
// @see ex13_26.h and ex12_19.h
// Format the original file to make it look more beautiful.

#ifndef STRBLOB_H
#define STRBLOB_H

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>
using std::make_shared;
using std::shared_ptr;
using std::string;
using std::vector;

class ConstStrBlobPtr;
class StrBlobPtr;

class StrBlob
{
public:
    using size_type = vector<string>::size_type;
    friend class ConstStrBlobPtr;
    friend class StrBlobPtr;
    friend bool operator==(const StrBlob &, const StrBlob &);
    friend bool operator!=(const StrBlob &, const StrBlob &);
    friend bool operator<(const StrBlob &, const StrBlob &);
    friend bool operator>(const StrBlob &, const StrBlob &);
    friend bool operator<=(const StrBlob &, const StrBlob &);
    friend bool operator>=(const StrBlob &, const StrBlob &);
    string &operator[](size_t);
    const string &operator[](size_t) const;

public:
    StrBlob() : data(make_shared<vector<string>>()) {}
    StrBlob(std::initializer_list<string> il) : data(std::make_shared<vector<string>>(il)) {}

    StrBlob(const StrBlob &sb) : data(std::make_shared<vector<string>>(*sb.data)) {}
    StrBlob &operator=(const StrBlob &sb);

    StrBlob(StrBlob &&rhs) noexcept : data(std::move(rhs.data)) {}
    StrBlob &operator=(StrBlob &&) noexcept;

    StrBlobPtr begin();
    StrBlobPtr end();

    ConstStrBlobPtr cbegin() const; // should add const
    ConstStrBlobPtr cend() const;   // should add const

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const string &t) { return data->push_back(t); }
    void push_back(string &&s) { data->push_back(std::move(s)); }

    void pop_back();

    string &front();
    string &back();
    const string &front() const;
    const string &back() const;

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &str) const;
};

// #-------------------------------------------------------------------------------------------------------

// init ConstStrBlobPtr
class ConstStrBlobPtr
{
public:
    friend bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
    friend bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
    friend bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
    friend bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
    friend bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
    friend bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

    const string &operator[](size_t) const;
    const string &operator*() const;
    const string *operator->() const;

    ConstStrBlobPtr &operator++();
    ConstStrBlobPtr &operator--();
    ConstStrBlobPtr operator++(int);
    ConstStrBlobPtr operator--(int);
    ConstStrBlobPtr &operator+=(size_t);
    ConstStrBlobPtr &operator-=(size_t);
    friend ConstStrBlobPtr operator+(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
    friend ConstStrBlobPtr operator-(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

public:
    ConstStrBlobPtr() : curr(0) {}
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

    string &deref() const;
    ConstStrBlobPtr &incr();

private:
    shared_ptr<vector<string>> check(size_t i, const string &msg) const;
    std::weak_ptr<vector<string>> wptr;
    size_t curr;
};

// #-------------------------------------------------------------------------------------------------------

// init StrBlobPtr
class StrBlobPtr
{

public:
    friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

    string &operator[](size_t);
    const string &operator[](size_t) const;

    string &operator*() const;
    string *operator->() const;
    StrBlobPtr &operator++();
    StrBlobPtr &operator--();
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);
    StrBlobPtr &operator+=(size_t);
    StrBlobPtr &operator-=(size_t);
    friend StrBlobPtr operator+(const StrBlobPtr &, const StrBlobPtr &);
    friend StrBlobPtr operator-(const StrBlobPtr &, const StrBlobPtr &);

public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

    string &deref() const;
    StrBlobPtr &incr();

private:
    shared_ptr<vector<string>> check(size_t i, const string &msg) const;
    std::weak_ptr<vector<string>> wptr;
    size_t curr;
};

#endif