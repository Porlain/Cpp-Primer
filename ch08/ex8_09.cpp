/*
 * @Author: Porlain szbj2023@163.com
 * @Date: 2023-11-11 15:12:37
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */


#include <iostream>
#include <sstream>
using std::istringstream;
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
    istringstream iss("hello");
    func(iss);
    return 0;
}