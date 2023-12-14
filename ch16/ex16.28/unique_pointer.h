#pragma once
#include "DebugDelete.h"

namespace cp5
{
    template <typename, typename>
    class unique_pointer;

    template <typename T, typename D>
    auto swap(unique_pointer<T, D> &lhs, unique_pointer<T, D> &rhs)
    {
        using std::swap;
        swap(lhs.ptr, rhs.ptr);
        swap(lhs.deleter, rhs.deleter);
    }
}

template <typename T, typename D = DebugDelete>
class unique_pointer
{
public:
    unique_pointer() : ptr(nullptr), deleter(D()) {}
    explicit unique_pointer(T *pointer) : ptr(pointer) {}

    // preventing copy and assignment
    unique_pointer(const unique_pointer &) = delete;
    unique_pointer &operator=(const unique_pointer &) = delete;

    // move constructor
    unique_pointer &operator=(unique_pointer &&) noexcept;

    // std::nullptr_t assignment
    unique_pointer &operator=(std::nullptr_t n) noexcept;

    // operator overloaded :  *  ->  bool
    T &operator*() const { return *ptr; }
    T *operator->() const { return &this->operator*(); }
    operator bool() const { return ptr ? true : false; }

    // return the underlying pointer
    T *get() const noexcept { return ptr; }

    // swap member using swap friend
    void swap(unique_pointer<T, D> &rhs) { cp5::swap(*this, rhs); }

    // free and make it point to nullptr or to p's pointee.
    void reset() noexcept;
    void reset(T *p) noexcept;

    // return ptr and make ptr point to nullptr.
    T *release();

    ~unique_pointer() { deleter(ptr); }

private:
    T *ptr;
    D deleter;
};

// move assignment
template <typename T, typename D>
unique_pointer<T, D> &unique_pointer<T, D>::operator=(unique_pointer &&rhs) noexcept
{
    if (this->ptr != rhs.ptr)
    {
        deleter(ptr);
        ptr = nullptr;
        cp5::swap(*this, rhs);
    }
    return *this;
}

// std::nullptr_t assignment
template <typename T, typename D>
unique_pointer<T, D> &unique_pointer<T, D>::operator=(std::nullptr_t n) noexcept
{
    if (n == nullptr)
    {
        deleter(ptr);
        ptr = nullptr;
    }
    return *this;
}

// free and make it point to nullptr or to p's pointee.
template <typename T, typename D>
void unique_pointer<T, D>::reset() noexcept
{
    deleter(ptr);
    ptr = nullptr;
}

template <typename T, typename D>
void unique_pointer<T, D>::reset(T *p) noexcept
{
    deleter(ptr);
    ptr = p;
}

// relinquish contrul by returnning ptr and making ptr point to nullptr.
template <typename T, typename D>
T *unique_pointer<T, D>::release()
{
    T *ret = ptr;
    ptr = nullptr;
    return ret;
}
