/*
 * @Author: Porlain szbj2023@163.com
 * @Date: 2023-11-08 15:24:13
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */

#ifndef CP5_ex7_24_h
#define CP5_ex7_24_h
#include <string>
using std::string;

class Screen
{
public:
    using pos = string::size_type;

    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * width + c]; }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
};

#endif