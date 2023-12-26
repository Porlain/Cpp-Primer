/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-26 14:48:41
 */
#include <string>
#include <iostream>

class Screen
{
public:
    using pos = std::string::size_type;

    static const std::string Screen::*data() { return &Screen::contents; }
    static const pos Screen::*pcursor() { return &Screen::cursor; }
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * width + c]; }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

int main()
{
    // const std::string Screen::*pdata;
    // pdata = &Screen::contents;
    // auto pdata = &Screen::contents;  //contents is private

    const std::string Screen::*pdata = Screen::data();
    Screen myScreen(2, 2, 'c');
    auto s = myScreen.*pdata;
    std::cout << s << std::endl;

    const std::string::size_type Screen::*pcursor = Screen::pcursor();
    auto i = myScreen.*pcursor;
    std::cout << i << std::endl;

    return 0;
}
