/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-15 10:51:33
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    fill_n(v.begin(), v.size(), 0);
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}