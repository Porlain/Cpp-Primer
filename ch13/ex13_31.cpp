/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-27 19:27:37
 */
#include <vector>
#include <algorithm>
#include "ex13_31.h"

int main()
{
    HasPtr s{"s"}, a{"a"}, c{"c"};
    std::vector<HasPtr> vec{s, a, c};
    std::sort(vec.begin(),vec.end());
    for (auto const& elem : vec) elem.show();
    return 0;
}