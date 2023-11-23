/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-20 20:18:27
 */
#include "ex12_19.h"
#include <iostream>
#include <fstream>

int main()
{
    std::fstream data("../data/book.txt");
    StrBlob blob;

    for (std::string str; std::getline(data, str);)
        blob.push_back(str);

    for (StrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend; pbeg.incr())
        std::cout << pbeg.deref() << std::endl;
    return 0;
}