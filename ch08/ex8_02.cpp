/*
 * @Author: Porlain szbj2023@163.com
 * @Date: 2023-11-11 14:17:29
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */

#include <iostream>
using std::istream;
using std::string;

istream &func(istream &is)
{
    string buf;
    while (is >> buf)
        std::cout << buf << std::endl;
    is.clear();
    return is;
}

int main()
{
    istream &is = func(std::cin);
    std::cout << is.rdstate() << std::endl;
    return 0;
}