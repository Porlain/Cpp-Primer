/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-16 14:53:14
 */
#include <iostream>

template <typename T, typename... Args>
void foo(T t, Args... args)
{
    std::cout << sizeof...(Args) << std::endl;
    std::cout << sizeof...(args) << std::endl;
}

int main()
{
    foo(1, 2);
    foo(1, 23, 4, 5, 6);
}
