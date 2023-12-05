/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-04 16:02:34
 */

#include "../ex14_30/ex14_30_StrBlob.cpp"
#include "ex14_32.h"
#include <iostream>

StrBlobPtr &StrBlobPtr_point::operator*() const
{
    return *p;
}
StrBlobPtr *StrBlobPtr_point::operator->() const
{
    return p;
}

int main()
{
    StrBlob sb{"hello", "world"};
    StrBlobPtr iter = sb.begin();
    StrBlobPtr_point ps(&iter);
    std::cout << ps->deref() << std::endl;
    return 0;
}