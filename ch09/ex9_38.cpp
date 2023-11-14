/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-14 14:46:23
 */
#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> v;
    for (std::string buffer; std::cin >> buffer; v.push_back(buffer))
        std::cout << v.capacity() << std::endl;

    return 0;
}