/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-28 17:16:49
 */
#ifndef CP5_EX_13_40_H_
#define CP5_EX_13_40_H_
#include <string>
#include <memory>
#include <initializer_list>

class StrVec
{
public:
    StrVec() : elements(nullptr), cap(nullptr), first_free(nullptr) {}
    StrVec(const StrVec &) {}
    StrVec(std::initializer_list<std::string>);
    StrVec &operator=(const StrVec &);
    ~StrVec();

public:
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }

    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }

    void push_back(const std::string &);

public:
    void reserve(size_t new_cap);
    void resize(size_t count);
    void resize(size_t count, const std::string &);

    std::string &at(size_t pos) { return *(elements + pos); }
    const std::string &at(size_t pos) const { return *(elements + pos); }

private:
    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);
    void free();
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    void reallocate();

private:
    std::string *elements;
    std::string *cap;
    std::string *first_free;
    std::allocator<std::string> alloc;
};

#endif