/*
 * @Author: Porlain szbj2023@163.com
 * @Date: 2023-11-09 10:06:16
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */

#ifndef CP5_ex7_27_h
#define CP5_ex7_27_h
#include <string>

class Screen
{
public:
    using pos = std::string::size_type;

    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

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
    pos height = 0, width = 0;
    std::string contents;
};

inline Screen &Screen::move(pos r, pos c)
{
    cursor = r * width + c;
    return *this;
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos c, char ch)
{
    contents[r * width + c] = ch;
    return *this;
}

#endif