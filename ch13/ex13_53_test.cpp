/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-29 16:04:44
 */
#include "ex13_53.cpp"

int main()
{
    HasPtr hp1("hello"), hp2("World"), *pH = new HasPtr("World");
    hp1 = hp2;
    hp1 = std::move(*pH);
    return 0;
}
