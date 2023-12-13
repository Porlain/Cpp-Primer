/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-11 16:12:21
 */
#include "Screen.h"
#include <iostream>

int main()
{
    Screen<5, 5> scr('c');
    Screen<5, 5> scr2;

    // output src to the screen
    std::cout<<scr;
    // input connet  to the  src 
    std::cin>>scr2;
    // test input
    std::cout<<scr2;

    return 0;
}