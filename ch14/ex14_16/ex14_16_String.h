/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-01 14:37:29
 */
// In this document, we will make some additions to our string class to make it more complete.
// The contents of the additions can refer to ex14_16_StrVec.h
#ifndef CP5_STRING_H__
#define CP5_STRING_H__

#include <memory>

class String
{
public:
    friend std::ostream &operator<<(std::ostream &, const String &);
    friend std::istream &operator>>(std::istream &, String &);
    friend bool operator==(const String &, const String &);
    friend bool operator!=(const String &, const String &);

public:
    String() : String("") {}
    String(const char *);
    String(const String &);
    String &operator=(const String &);
    String(String &&) noexcept;
    String &operator=(String &&) noexcept;
    ~String();

public:
    size_t size() const { return end_ - elements; }
    size_t length() const { return size() - 1; }
    size_t capacity() const { return cap - elements; }
    char *begin() const { return elements; }
    char *end() const { return end_; }

    void reserve(size_t);
    void resize(size_t);
    void resize(size_t, char);
    void push_back(const char);

private:
    void free();
    std::pair<char *, char *> alloc_n_copy(const char *, const char *);
    void alloc_n_move(size_t);
    void range_initializer(const char *, const char *);
    void chk_n_alloc();
    void reallocate();

private:
    char *elements;
    char *end_;
    char *first_free;
    char *cap;
    std::allocator<char> alloc;
};

#endif