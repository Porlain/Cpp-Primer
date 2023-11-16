/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-16 10:15:39
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
    vector<int> vec{1, 1, 3, 3, 5, 5, 7, 7, 9};
    list<int> list1;

    unique_copy(vec.begin(), vec.end(), back_inserter(list1));

    for (auto i : list1)
        cout << i << " ";
    cout << endl;
    return 0;
}