/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-14 13:48:26
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