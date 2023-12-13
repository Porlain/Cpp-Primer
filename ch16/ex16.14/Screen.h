/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-11 16:02:19
 * @See ex7_27.h
 */

#ifndef SCREEN_H
#define SCREEN_H
#include <string>
#include <iostream>

// definition class
template <unsigned H, unsigned W>
class Screen
{
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