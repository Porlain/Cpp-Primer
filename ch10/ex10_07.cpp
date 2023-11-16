/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-15 11:04:43
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

void print(vector<int> const &vec)
{
    for (auto i : vec)
        cout << i << " ";

    cout << endl;
}

int main()
{
    // (a)
    vector<int> vec;
    list<int> lst;
    int i;
    cout << "please input numbers:";
    while (cin >> i)
        lst.push_back(i);

    copy(lst.cbegin(), lst.cend(), back_inserter(vec));
    print(vec);

    // (b) No error, but not any sense. v.size() still equal zero.
    // Fixed: 1. use `v.resize(10);`
    //    or  2. use `fill_n(std::back_inserter(v), 10, 0)`
    vector<int> v;
    v.reserve(10);
    fill_n(v.begin(), 10, 0);
    cout << v.size() << endl;
    print(v);

    return 0;
}