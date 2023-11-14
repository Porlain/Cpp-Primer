/*
 * @Author: Porlain szbj2023@163.com
 * @Date: 2023-11-13 16:42:53
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */
#include <vector>
#include <list>
#include <iostream>

using namespace std;
int main()
{
    list<int> list1(10, 1);
    vector<int> vec(10, 2);

    // from list<int> to vector<double>
    vector<double> vec1(list1.begin(), list1.end());
    for (auto i : list1)
        cout << i << " ";
    cout << endl;
    for (auto d : vec1)
        cout << d << " ";
    cout << endl;

    // from vector<int> to vector<double>
    vector<double> vec2(vec.begin(), vec.end());
    for (auto i : vec)
        cout << i << " ";
    cout << endl;
    for (auto d : vec2)
        cout << d << " ";

    return 0;
}
