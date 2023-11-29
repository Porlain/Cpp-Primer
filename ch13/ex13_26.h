/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-27 16:40:43
 */

#ifndef CP5_ex13_26_h
#define CP5_ex13_26_h

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>
using std::shared_ptr;
using std::string;
using std::vector;

// declare StrBlobPtr
class ConstStrBlobPtr;

// init strblob
class StrBlob
{
public:
    friend class ConstStrBlobPtr;
    // we should define at the end of the file
    ConstStrBlobPtr begin() const; // should add const
    ConstStrBlobPtr end() const;   // should add const

public:
    using size_type = vector<string>::size_type;

    StrBlob();
    StrBlob(std::initializer_list<string> il);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const string &t) { return data->push_back(t); }
    void pop_back();

    string &front();
    string &back();

    const string &front() const;
    const string &back() const;

public:
    // copy constructor
    StrBlob(const StrBlob &sb) : data(std::make_shared<vector<string>>(*sb.data)) {}
    // copyassignment operators, define at the end of the file
    StrBlob &operator=(const StrBlob &sb);

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &str) const;
};

StrBlob::StrBlob() : data(std::make_shared<vector<string>>()) {}
StrBlob::StrBlob(std::initializer_list<string> il) : data(std::make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &str) const
{
    if (i >= str.size())
        throw std::out_of_range(str);
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

string &StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

const string &StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

const string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

// init StrBlobPtr
class ConstStrBlobPtr
{
public:
    // for ex12_20
    bool operator!=(const ConstStrBlobPtr &p) { return p.curr != curr; }

public:
    ConstStrBlobPtr() : curr(0) {}
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {} // should add const
    string &deref() const                                                        // return value should add const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    ConstStrBlobPtr &incr()
    {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }

private:
    shared_ptr<vector<string>> check(size_t i, const string &msg) const;
    std::weak_ptr<vector<string>> wptr;
    size_t curr;
};

shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

ConstStrBlobPtr StrBlob::begin() const { return ConstStrBlobPtr(*this); }

ConstStrBlobPtr StrBlob::end() const
{
    auto ret = ConstStrBlobPtr(*this, data->size());
    return ret;
}

StrBlob &StrBlob::operator=(const StrBlob &sb)
{
    data = std::make_shared<vector<string>>(*sb.data);
    return *this;
}

#endif