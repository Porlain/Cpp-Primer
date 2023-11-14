/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-14 13:47:10
 */


#ifndef CP5_ex7_32_h
#define CP5_ex7_32_h
#include <string>
#include <vector>

class Screen;

class Window_mgr
{
public:
    Window_mgr() = default;
    using ScreenIndex = std::vector<Screen>::size_type;
    // declaring
    inline void clear(ScreenIndex);

private:
    std::vector<Screen> screens;
};

class Screen
{
public:
    // declaring this is friend function
    friend void Window_mgr::clear(ScreenIndex);

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

inline void Window_mgr::clear(ScreenIndex i ){
    // judge for out_of_range.
    if (i>=screens.size())return;
        
    Screen s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

#endif