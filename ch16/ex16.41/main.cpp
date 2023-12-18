/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-14 15:53:23
 */
// This may be error
#include <iostream>

template <typename T>
auto sum(T lhs, T rhs) -> decltype(lhs + rhs)
{
    return lhs + rhs;
}

int main()
{
    auto s = sum(123456789123456789123456789123456789123456789, 123456789123456789123456789123456789123456789);
    // std::cout << s << std::endl;
    return 0;
}
