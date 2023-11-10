/*
 * @Author: Porlain szbj2023@163.com
 * @Date: 2023-11-09 10:16:48
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */

#include "ex7_27.h"
#include <iostream>

int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(std::cout);
    std::cout << "\n";
    myScreen.display(std::cout);
    std::cout << "\n";

    return 0;
}