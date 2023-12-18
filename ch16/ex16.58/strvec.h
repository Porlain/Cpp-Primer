/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-16 15:39:30
 */
/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-01 14:06:24
 */
#ifndef STRVEC_H
#define STRVEC_H
#include <string>
#include <memory>
#include <initializer_list>

class StrVec
{
public:
    friend bool operator==(const StrVec &, const StrVec &);
    friend bool operator!=(const StrVec &, const StrVec &);
    friend bool operator<(const StrVec &, const StrVec &);
    friend bool operator>(const StrVec &, const StrVec &);
    friend bool operator<=(const StrVec &, const StrVec &);
    friend bool operator>=(const StrVec &, const StrVec &);
    std::string &operator[](size_t n) { return elements[n]; }
    const std::string &operator[](size_t n) const { return elements[n]; }

public:
    StrVec() : elements(nullptr), cap(nullptr), first_free(nullptr) {}
    StrVec(const StrVec &);
    StrVec(std::initializer_list<std::string>);
    StrVec &operator=(const StrVec &);
    StrVec(StrVec &&) noexcept;
    StrVec &operator=(StrVec &&) noexcept;
    ~StrVec();

public:
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }

    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }

    void push_back(const std::string &);
    // a variadic member template using its argumenst to construct
    // an element directly in space managed by the constainer
    template <typename... Args>
    void emplace_back(Args &&...);

    void reserve(size_t);
    void resize(size_t);
    void resize(size_t, const std::string &);

    std::string &at(size_t pos) { return *(elements + pos); }
    const std::string &at(size_t pos) const { return *(elements + pos); }

private:
    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);
    void free();
    void chk_n_alloc();

    void reallocate();

private:
    std::string *elements;
    std::string *cap;
    std::string *first_free;
    std::allocator<std::string> alloc;
};

// call the constructors of the type to construct this element
// and push it back.
template <typename... Args>
inline void
StrVec::emplace_back(Args &&...args)
{
    // reallocate if necessary
    chk_n_alloc();
    alloc.construct(first_free++, std::forward<Args>(args)...);
}

#endif