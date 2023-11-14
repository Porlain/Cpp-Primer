/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-14 13:49:03
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