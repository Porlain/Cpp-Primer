/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-02 14:18:24
 */
#include "ex14_26_StrBlob.cpp"
#include <iostream>

int main()
{
    StrBlob sb1{ "a", "b", "c" };
    StrBlob sb2 = sb1;

    sb2[2] = "b";

    if (sb1 > sb2) {
        for (ConstStrBlobPtr iter = sb1.cbegin(); iter < sb1.cend(); iter.incr())
            std::cout << iter.deref() << " ";
        std::cout << std::endl;
    }

    StrBlobPtr iter(sb2);
    std::cout << iter[2] << std::endl;
}
