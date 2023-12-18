/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-18 14:47:21
 */
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

template <typename T>
std::size_t count(const std::vector<T> &vec, T value)
{
    return std::count(vec.cbegin(), vec.cend(), value);
}

std::size_t count(const std::vector<std::string> &vec, const char *value)
{
    std::string str(value);
    return std::count(vec.cbegin(), vec.cend(), str);
}

template <>
std::size_t count(const std::vector<const char *> &vec, const char *value)
{
    return std::count(vec.cbegin(), vec.cend(), value);
}

int main()
{
    std::vector<double> vd = {1, 2, 3, 3.14, 4, 3.14, 5, 6.28};
    std::vector<int> vi = {1, 2, 3, 3, 4, 3, 5, 6};
    std::vector<std::string> vs = {"a", "bb", "ccc", "dddd"};
    std::vector<const char *> vcp = {"a", "bb", "ccc", "dddd"};

    std::cout << count(vd, 3.14) << std::endl;
    std::cout << count(vi, 3) << std::endl;
    std::cout << count(vs, std::string("a")) << std::endl;
    std::cout << count(vcp, "a") << std::endl;

    return 0;
}