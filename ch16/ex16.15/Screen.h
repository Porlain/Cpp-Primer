/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-11 16:13:05
 * @See ex7_27.h
 */

#ifndef SCREEN_H
#define SCREEN_H
#include <string>
#include <iostream>

template <unsigned H, unsigned W>
class Screen;

template <unsigned H, unsigned W>
std::ostream &operator<<(std::ostream &, const Screen<H, W> &);

template <unsigned H, unsigned W>
std::istream &operator>>(std::istream &, Screen<H, W> &);

// definition class
template <unsigned H, unsigned W>
class Screen
{
public:
    friend std::ostream &operator<< <H, W>(std::ostream &, const Screen<H, W> &);
    friend std::istream &operator>> <H, W>(std::istream &, Screen<H, W> &);

public:
    using pos = std::string::size_type;

    Screen() = default;
    Screen(char c) : height(H), width(W), contents(H * W, c) {}

    inline Screen &move(pos r, pos c);
    inline Screen &set(char c);
    inline Screen &set(pos r, pos c, char ch);

    Screen &display(std::ostream &os)
    {
        do_display(os);
        return *this;
    }

    const Screen &display(std::ostream &os) const
    {
        do_display(os);
        return *this;
    }

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * width + c]; }

private:
    void do_display(std::ostream &os) const { os << contents; }

    pos cursor = 0;
    pos height = H, width = W;
    std::string contents;
};

template <unsigned H, unsigned W>
std::ostream &operator<<(std::ostream &out, const Screen<H, W> &c)
{
    for (unsigned int i = 0; i < c.height; ++i)
        out << c.contents.substr(0, W) << std::endl;
    return out;
}

template <unsigned H, unsigned W>
std::istream &operator>>(std::istream &in, Screen<H, W> &c)
{
    char a;
    in >> a;
    std::string temp(H * W, a);
    c.contents = temp;
    return in;
}

template <unsigned H, unsigned W>
inline Screen<H, W> &Screen<H, W>::move(pos r, pos c)
{
    cursor = r * width + c;
    return *this;
}

template <unsigned H, unsigned W>
inline Screen<H, W> &Screen<H, W>::set(char c)
{
    contents[cursor] = c;
    return *this;
}

template <unsigned H, unsigned W>
inline Screen<H, W> &Screen<H, W>::set(pos r, pos c, char ch)
{
    contents[r * width + c] = ch;
    return *this;
}

#endif