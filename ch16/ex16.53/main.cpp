/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-16 15:03:10
 */
#include <iostream>

// trivial case
template <typename Printable>
std::ostream &print(std::ostream &os, Printable const &printable)
{
    return os << printable;
}

// recursion
template <typename T, typename... Args>
std::ostream &print(std::ostream &os, T const &t, Args const &...rest)
{
    return print(os << t << ", ", rest...);
}

int main()
{
    print(std::cout, 1) << std::endl;
    print(std::cout, 1, 2) << std::endl;
    print(std::cout, 1, 2, 3, 4, "sss", 42.4242) << std::endl;

    return 0;
}