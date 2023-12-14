/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-14 13:48:41
 */
#include <iostream>
#include <vector>
#include <memory>
#include <functional>
#include "DebugDelete.h"
#include "shared_pointer.h"
#include "unique_pointer.h"
#include "Blob.h"

int main()
{
    Blob<std::string> b;
    b.push_back("sss");


    b[0] = "zzzz";
    std::cout << b[0] << "\n";
}