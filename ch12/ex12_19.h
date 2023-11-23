/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-20 20:22:55
 */
#ifndef CP5_ex12_19_h
#define CP5_ex12_19_h

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>
using std::shared_ptr;
using std::string;
using std::vector;

// declare StrBlobPtr
class StrBlobPtr;

// init strblob
class StrBlob
{
public:
    friend class StrBlobPtr;
    // we should define at the end of the file
    StrBlobPtr begin();
    StrBlobPtr end();

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
class StrBlobPtr
{
public:
    // for ex12_20
    bool operator!=(const StrBlobPtr &p) { return p.curr != curr; }

public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    string &deref() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    StrBlobPtr &incr()
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

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }

StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

#endif