/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-18 14:52:05
 */
#include <iostream>
#include <memory>
#include <sstream>

// always declare first:
template <typename T>
std::string debug_rep(T *p);

template <>
std::string debug_rep(char *p);
template <>
std::string debug_rep(const char *p);

// print any type we don't otherwise.
template <typename T>
std::string debug_rep(const T &t)
{
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

// convert the character pointers to string and call the string version of debug_rep
template <>
std::string debug_rep(char *p)
{
    return debug_rep(std::string(p));
}

template <>
std::string debug_rep(const char *p)
{
    return debug_rep(std::string(p));
}

int main()
{
    char p[] = "porlain";
    std::cout << debug_rep(p) << "\n";
    return 0;
}