/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-02 15:02:17
 */
#include "ex14_27_StrBlob.cpp"
#include <iostream>

int main()
{
    StrBlob sb1{ "a", "b", "c" };
    StrBlob sb2 = sb1;

    sb2[2] = "b";

    if (sb1 > sb2) {
        for (StrBlobPtr iter = sb1.begin(); iter < sb1.end(); ++iter)
            std::cout << iter.deref() << " ";
        std::cout << std::endl;
    }

    ConstStrBlobPtr iter(sb2);
    std::cout << (iter += 2).deref() << std::endl;
}
