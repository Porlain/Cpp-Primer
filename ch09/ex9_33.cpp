/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-14 14:19:37
 */


//  @Answer Crash, because the iterator is invalid after inserting.

#include <iostream>
#include <vector>

using std::vector; using std::cout; using std::endl;

int main()
{
    vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto begin = v.begin();
    while (begin != v.end()) {
        ++begin;
        /*begin = */v.insert(begin, 42);
        ++begin;
    }

    for (auto i : v)
        cout << i << " ";

    return 0;
}