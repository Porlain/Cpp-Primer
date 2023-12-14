/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-14 14:12:30
 */
// 1.   Main function compilation unique_pointer and shared_pointer, 
//      which can cause the swap function to matched incorrectly, therefore modifying the swap function
// 2.   To support make_shared in Blob.h, add a constructor
// 3.   Add default parameters for members
// 4.   Modify some auto types (not necessary)
#pragma once
#include <functional>
#include "DebugDelete.h"

template <typename T>
class SharedPointer;

template <typename T>
void swap(SharedPointer<T> &lhs, SharedPointer<T> &rhs);

template <typename T>
class SharedPointer
{
public:
    friend void ::swap<T>(SharedPointer<T> &lhs, SharedPointer<T> &rhs);

public:
    //
    //  Default Ctor
    //
    SharedPointer() = default;
    //
    //  Ctor that takes raw pointer
    //
    explicit SharedPointer(T *raw_ptr, std::function<void(T *)> d = DebugDelete()) : ptr(raw_ptr), ref_count(new std::size_t(1)), deleter(d) {}
    // ctor taking std::shared_ptr&& i.e. rvalue reference
    explicit SharedPointer(std::shared_ptr<T> &&, std::function<void(T *)> d = DebugDelete());

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
    T *get() const { return ptr; }
    //
    //  Check if the unique user
    //
    bool unique() const { return *ref_count == 1; }
    //
    //  Swap
    //
    void swap(SharedPointer &rhs) { ::swap(*this, rhs); }
    //
    // Free the object pointed to, if unique
    //
    void reset() noexcept { decrement_and_destory(); }
    //
    // Reset with the new raw pointer
    //
    void reset(T *pointer);
    //
    //  Reset with raw pointer and deleter
    //
    void reset(T *pointer, const std::function<void(T *)> &d);

    ~SharedPointer() { decrement_and_destory(); }

private:
    T *ptr = nullptr;
    std::size_t *ref_count = new std::size_t(0);
    std::function<void(T *)> deleter{DebugDelete()};

    void decrement_and_destory();
};

template <typename T>
inline void swap(SharedPointer<T> &lhs, SharedPointer<T> &rhs)
{
    using std::swap;
    swap(lhs.ptr, rhs.ptr);
    swap(lhs.ref_count, rhs.ref_count);
    swap(lhs.deleter, rhs.deleter);
}

template <typename T>
SharedPointer<T>::SharedPointer(std::shared_ptr<T> &&sp, std::function<void(T *)> d)
{
    if (sp.unique())
        *this = SharedPointer(new T(*sp), d);
    else
        throw std::runtime_error("only unique and rvalue reference can transfer ownership--@Alan\n");
}

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
    ::swap(*this, rhs);
    rhs.decrement_and_destory();
    return *this;
}

template <typename T>
inline void SharedPointer<T>::decrement_and_destory()
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
void SharedPointer<T>::reset(T *pointer)
{
    if (ptr != pointer)
    {
        decrement_and_destory();
        ptr = pointer;
        ref_count = new std::size_t(1);
    }
}

template <typename T>
void SharedPointer<T>::reset(T *pointer, const std::function<void(T *)> &d)
{
    reset(pointer);
    deleter = d;
}