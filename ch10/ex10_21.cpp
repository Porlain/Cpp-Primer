/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-15 16:00:12
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int i = 7;

    auto check = [&i]()
    { return i > 0 ? --i : i; };
    while (check())
        cout << i << " ";
    cout << i << endl;

    return 0;
}