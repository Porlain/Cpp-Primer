/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-13 14:26:10
 */
#include <iostream>
#include "Blob.h"
#include "BlobPtr.h"

int main()
{
    std::vector<int> v = { 1, 2, 3, 4, 5 };
    Blob<int> b(v.begin(), v.end());
    return 0;
}