/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-13 17:08:15
 */
// Ensure that the header file is compiled only once to prevent duplicate references.
#pragma once
#include <functional>
#include "DebugDelete.h"

namespace cp5
{
    template <typename T>
    class SharedPointer;

    template <typename T>
    auto swap(SharedPointer<T> &lhs, SharedPointer<T> &rhs)
    {
        using std::swap;
        swap(lhs.ptr, rhs.ptr);
        swap(lhs.ref_count, rhs.ref_count);
        swap(lhs.deleter, rhs.deleter);
    }
}

template <typename T>
class SharedPointer
{
public:
    //
    //  Default Ctor
    //
    SharedPointer() : ptr(nullptr), ref_count(new std::size_t(1)), deleter(DebugDelete()) {}
    //
    //  Ctor that takes raw pointer
    //
    explicit SharedPointer(T *raw_ptr) : ptr(raw_ptr), ref_count(new std::size_t(1)), deleter(DebugDelete()) {}
    //
    //  Copy Ctor
    //
    SharedPointer(const SharedPointer &rhs) : ptr(rhs.ptr), ref_count(rhs.ref_count), deleter(rhs.deleter) { ++*ref_count; }
    //
    //  Move Ctor
    //
    SharedPointer(SharedPointer &&rhs) noexcept : ptr(rhs.ptr), ref_count(rhs.ref_count), deleter(std::move(rhs.deleter))
    {
        rhs.ref_count = nullptr;
        rhs.ptr = nullptr;
    }
    //
    //  Copy assignment
    //
    SharedPointer &operator=(const SharedPointer &rhs);
    //
    //  Move assignment
    //
    SharedPointer &operator=(SharedPointer &&rhs) noexcept;
    //
    //  Conversion operator
    //
    operator bool() const { return ptr ? true : false; }
    //
    //  Dereference
    //
    T &operator*() const { return *ptr; }
    //
    //  Arrow
    //
    T *operator->() const { return &*ptr; }
    //
    //  Use count
    //
    auto use_count() const { return *ref_count; }
    //
    //  Get underlying pointer
    //
    auto get() const { return ptr; }
    //
    //  Check if the unique user
    //
    auto unique() const { return *ref_count == 1; }
    //
    //  Swap
    //
    auto swap(SharedPointer &rhs) { cp5::swap(*this, rhs); }
    //
    // Free the object pointed to, if unique
    //
    auto reset() { decrement_and_destory(); }
    //
    // Reset with the new raw pointer
    //
    auto reset(T *pointer);
    //
    //  Reset with raw pointer and deleter
    //
    auto reset(T *pointer, const std::function<void(T *)> &d);

    ~SharedPointer() { decrement_and_destory(); }

private:
    T *ptr;
    std::size_t *ref_count;
    std::function<void(T *)> deleter;

    auto decrement_and_destory();
};

template <typename T>
SharedPointer<T> &SharedPointer<T>::operator=(const SharedPointer &rhs)
{
    // increment first to ensure safty for self-assignment
    ++*ref_count;
    decrement_and_destory();
    ptr = rhs.ptr;
    ref_count = rhs.ref_count;
    deleter = rhs.deleter;
    return *this;
}

template <typename T>
SharedPointer<T> &SharedPointer<T>::operator=(SharedPointer &&rhs) noexcept
{
    cp5::swap(*this, rhs);
    rhs.decrement_and_destroy();
    return *this;
}

template <typename T>
auto SharedPointer<T>::decrement_and_destory()
{
    if (ptr && --*ref_count == 0)
    {
        delete ref_count;
        deleter(ptr);
    }
    else if (!ptr)
        delete ref_count;
    ref_count = nullptr;
    ptr = nullptr;
}

template <typename T>
auto SharedPointer<T>::reset(T *pointer)
{
    if (ptr != pointer)
    {
        decrement_and_destory();
        ptr = pointer;
        ref_count = new std::size_t(1);
    }
}

template <typename T>
auto SharedPointer<T>::reset(T *pointer, const std::function<void(T *)> &d)
{
    reset(pointer);
    deleter = d;
}