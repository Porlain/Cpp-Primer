/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-20 14:55:49
 */
#include "ex12_02.h"
#include <iostream>

int main()
{
    const StrBlob csb{ "hello", "world", "porlain" };
    StrBlob sb{ "hello", "world", "Mooophy and pezy" };

    std::cout << csb.front() << " " << csb.back() << std::endl;
    std::cout << sb.front() << " " << sb.back() << std::endl;
}
