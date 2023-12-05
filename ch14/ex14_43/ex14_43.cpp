/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-05 10:49:02
 */
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <functional>
using std::vector;

int main()
{
    vector<int> vec = {2, 3, 4, 5};
    int data;
    std::cin >> data;
    std::modulus<int> mod;
    auto predicator = [&](int i)
    { return 0 == mod(data, i); };
    bool is_divisible = std::all_of(vec.begin(), vec.end(), predicator);
    std::cout << (is_divisible ? "Yes!" : "No!") << std::endl;

    return 0;
}