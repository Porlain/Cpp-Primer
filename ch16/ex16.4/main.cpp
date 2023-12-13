/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-09 15:08:29
 */
#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

template <typename Iterator, typename Value>
auto find(Iterator first, Iterator last, const Value &val)
{
    for (; first != last && *first != val; ++first)
        ;
    return first;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto is_in_vector = v.cend() != find(v.cbegin(), v.cend(), 5);
    cout << (is_in_vector ? "found\n" : "not found\n");

    list<string> l = {"aa", "bb", "cc", "dd", "ee", "ff", "gg"};
    auto is_in_list = l.cend() != find(l.cbegin(), l.cend(), "zz");
    cout << (is_in_list ? "found\n" : "not found\n");
    return 0;
}
