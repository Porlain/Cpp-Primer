/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-19 10:38:34
 */
#include <tuple>
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

int main()
{
    std::tuple<string, vector<string>, std::pair<string, int>> three_("constants", {"a", "bb"}, {"ccc", 3});

    return 0;
}