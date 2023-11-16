/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-14 20:30:23
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 6, 6, 2};
    int val = 6;
    cout << count(vec.begin(), vec.end(), val) << endl;

    return 0;
}