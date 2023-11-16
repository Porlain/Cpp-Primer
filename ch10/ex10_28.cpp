/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-16 11:13:37
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

void print(list<int> const &vec)
{
    for (auto i : vec)
        cout << i << " ";

    cout << endl;
}

int main()
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> list, list_back, list_front;

    // uses inserter
    copy(vec.cbegin(), vec.cend(), inserter(list, list.begin()));
    print(list);

    // uses back_inserter
    copy(vec.cbegin(), vec.cend(), back_inserter(list_back));
    print(list_back);

    // uses front_inserter
    copy(vec.cbegin(), vec.cend(), front_inserter(list_front));
    print(list_front);
    return 0;
}