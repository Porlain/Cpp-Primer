/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-04 15:53:19
 */
#include "ex14_30_StrBlob.cpp"
#include <iostream>

int main()
{
    StrBlob sb1{"a", "b", "c"};
    StrBlob sb2 = sb1;

    sb2[2] = "b";

    if (sb1 > sb2)
    {
        for (ConstStrBlobPtr iter = sb1.cbegin(); iter != sb1.cend(); ++iter)
            std::cout << *iter << " ";
        std::cout << std::endl;
    }

    ConstStrBlobPtr iter(sb2);
    std::cout << iter->size() << std::endl;
}
