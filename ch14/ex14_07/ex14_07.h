/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-30 17:06:16
 */
/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-30 16:01:37
 */
#ifndef CP5_CH14_EX07_H_
#define CP5_CH14_EX07_H_

#include <memory>

class String
{
public:
    friend std::ostream &operator<<(std::ostream &, const String &);

public:
    String() : elements(nullptr), end_(nullptr) {}
    String(const char *);
    String(const String &);
    String &operator=(const String &);
    String(String &&) noexcept;
    String &operator=(String &&) noexcept;
    ~String();

public:
    size_t size() const { return end_ - elements; }
    size_t length() const { return end_ - elements - 1; }
    char *begin() const { return elements; }
    char *end() const { return end_; }

private:
    void free();
    std::pair<char *, char *> alloc_n_copy(const char *, const char *);

private:
    char *elements;
    char *end_;
    std::allocator<char> alloc;
};

#endif