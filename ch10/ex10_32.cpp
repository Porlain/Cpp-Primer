/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-16 13:51:12
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include "../include/Sales_item.h"

int main()
{
    std::istream_iterator<Sales_item> iter_in(std::cin), eof;
    std::vector<Sales_item> vec;

    // input data
    while (iter_in != eof)
        vec.push_back(*iter_in++);

    sort(vec.begin(), vec.end(), compareIsbn);
    for (auto beg = vec.cbegin(), end = beg; beg != vec.cend(); beg = end)
    {
        end = find_if(beg, vec.cend(), [beg](const Sales_item &item)
                      { return item.isbn() != beg->isbn(); });
        std::cout << std::accumulate(beg, end, Sales_item(beg->isbn())) << std::endl;
    }

    return 0;
}