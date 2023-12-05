/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-30 20:11:04
 */
#include "ex14_16_StrBlob.cpp"
#include <iostream>

int main()
{
    StrBlob sb{ "Hello", "World", "Porlain" };

    for (ConstStrBlobPtr iter = sb.cbegin(); iter != sb.cend(); iter.incr()) {
        std::cout << iter.deref() << " ";
    }
    std::cout << std::endl;
}
