/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-28 19:44:18
 */
#ifndef CP5_STRING_H__
#define CP5_STRING_H__

#include <memory>

class String
{
public:
    String() : elements(nullptr), end(nullptr) {}
    String(const char *);
    String(const String &);
    String &operator=(const String &);
    ~String();

public:
    size_t size() const { return end - elements; }
    size_t length() const { return end - elements - 1; }
    char *begin() const { return elements; }
    char *end_() const { return end; }

private:
    void free();
    std::pair<char *, char *> alloc_n_copy(const char *, const char *);

private:
    char *elements;
    char *end;
    std::allocator<char> alloc;
};

#endif