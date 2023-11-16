/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-15 10:20:04
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4};
    cout << accumulate(v.cbegin(), v.cend(), 0) << endl;
    return 0;
}