/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-17 13:47:07
 */
#include <vector>
#include <utility>
#include <string>
#include <iostream>

int main()
{
    std::vector<std::pair<std::string, int>> vec;
    std::string str;
    int i;
    while (std::cin >> str >> i)
        vec.push_back(std::pair<std::string, int>(str, i));
    // vec.push_back(std::make_pair(str,i));
    // vec.push_back({str, i});
    // vec.emplace_back(str, i); // best way

    for (auto const &v : vec)
        std::cout
            << v.first << " " << v.second << std::endl;

    return 0;
}