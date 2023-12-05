/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-04 15:52:08
 */
#include "ex14_30_StrBlob.h"

//==================================================================
//
//		All operator
//
//==================================================================

//==================================================================
//
//		StrBlob - operators
//
//==================================================================

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
    return std::lexicographical_compare(lhs.data->begin(), lhs.data->end(), rhs.data->begin(), rhs.data->end());
}

bool operator>(const StrBlob &lhs, const StrBlob &rhs)
{
    return rhs < lhs;
}

bool operator<=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(rhs < lhs);
}

bool operator>=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs < rhs);
}

//================================================================
//
//		StrBlobPtr - operators
//
//================================================================

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &x, const StrBlobPtr &y)
{
    return x.curr < y.curr;
}

bool operator>(const StrBlobPtr &x, const StrBlobPtr &y)
{
    return x.curr > y.curr;
}

bool operator<=(const StrBlobPtr &x, const StrBlobPtr &y)
{
    return x.curr <= y.curr;
}

bool operator>=(const StrBlobPtr &x, const StrBlobPtr &y)
{
    return x.curr >= y.curr;
}

string &StrBlobPtr::operator*() const
{
    auto p = check(curr, "deference past end");
    return (*p)[curr];
}

string *StrBlobPtr::operator->() const
{
    return &this->operator*();
}

StrBlobPtr &StrBlobPtr::operator++()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr &StrBlobPtr::operator--()
{
    --curr;
    check(curr, "increment past end of StrBlobPtr");
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}

StrBlobPtr &StrBlobPtr::operator+=(size_t n)
{
    curr += n;
    check(curr, "increment past end of StrBlobPtr");
    return *this;
}

StrBlobPtr &StrBlobPtr::operator-=(size_t n)
{
    curr -= n;
    check(curr, "increment past end of StrBlobPtr");
    return *this;
}

StrBlobPtr operator+(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    StrBlobPtr ret = lhs;
    ret.curr += rhs.curr;
    return ret;
}

StrBlobPtr operator-(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    StrBlobPtr ret = lhs;
    ret.curr -= rhs.curr;
    return ret;
}

//================================================================
//
//		ConstStrBlobPtr - operators
//
//================================================================

bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    return lhs.curr == rhs.curr;
}

bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    return lhs.curr < rhs.curr;
}

bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    return lhs.curr > rhs.curr;
}

bool operator<=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    return lhs.curr <= rhs.curr;
}

bool operator>=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    return lhs.curr >= rhs.curr;
}

inline ConstStrBlobPtr &ConstStrBlobPtr::operator++()
{
    check(curr, "increment past end of ConstStrBlobPtr");
    ++curr;
    return *this;
}

inline ConstStrBlobPtr &ConstStrBlobPtr::operator--()
{
    --curr;
    check(-1, "decrement past begin of ConstStrBlobPtr");
    return *this;
}

inline ConstStrBlobPtr ConstStrBlobPtr::operator++(int)
{
    ConstStrBlobPtr ret = *this;
    ++*this;
    return ret;
}

inline ConstStrBlobPtr ConstStrBlobPtr::operator--(int)
{
    ConstStrBlobPtr ret = *this;
    --*this;
    return ret;
}

inline ConstStrBlobPtr &ConstStrBlobPtr::operator+=(size_t n)
{
    curr += n;
    check(curr, "increment past end of ConstStrBlobPtr");
    return *this;
}

inline ConstStrBlobPtr &ConstStrBlobPtr::operator-=(size_t n)
{
    curr -= n;
    check(curr, "increment past end of ConstStrBlobPtr");
    return *this;
}

ConstStrBlobPtr operator+(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    ConstStrBlobPtr ret = lhs;
    ret.curr += rhs.curr;
    return ret;
}

ConstStrBlobPtr operator-(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    ConstStrBlobPtr ret = lhs;
    ret.curr -= rhs.curr;
    return ret;
}

//================================================================
//
//		function of StrBlob
//
//================================================================

string &StrBlob::operator[](size_t n)
{
    check(n, "out of range");
    return data->at(n);
}

const string &StrBlob::operator[](size_t n) const
{
    check(n, "out of range");
    return data->at(n);
}

StrBlob &StrBlob::operator=(const StrBlob &lhs)
{
    data = make_shared<vector<string>>(*lhs.data);
    return *this;
}

StrBlob &StrBlob::operator=(StrBlob &&rhs) noexcept
{
    if (this != &rhs)
    {
        data = std::move(rhs.data);
        rhs.data = nullptr;
    }

    return *this;
}

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data->size());
}

ConstStrBlobPtr StrBlob::cbegin() const
{
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::cend() const
{
    return ConstStrBlobPtr(*this, data->size());
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

void StrBlob::check(size_type i, const string &str) const
{
    if (i >= str.size())
        throw std::out_of_range(str);
}

//================================================================
//
//		function of ConstStrBlobPtr
//
//================================================================

const string &ConstStrBlobPtr::operator[](size_t n) const
{
    auto p = check(n, "dereference out of range.");
    return (*p)[n];
}

const string &ConstStrBlobPtr::operator*() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

const string *ConstStrBlobPtr::operator->() const
{
    return &this->operator*();
}

inline string &ConstStrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

inline ConstStrBlobPtr &ConstStrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

//================================================================
//
//		function of StrBlobPtr
//
//================================================================

string &StrBlobPtr::operator[](size_t n)
{
    auto p = check(n, "dereference out of range.");
    return (*p)[n];
}

const string &StrBlobPtr::operator[](size_t n) const
{
    auto p = check(n, "dereference out of range.");
    return (*p)[n];
}

inline string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

inline StrBlobPtr &StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}
