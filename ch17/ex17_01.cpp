/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-19 10:32:41
 */
#include <tuple>
#include <iostream>
#include <vector>

int main()
{
    auto three = std::make_tuple(10, 20, 30);
    std::tuple<int, int, int> three_(10, 20, 30);

    return 0;
}