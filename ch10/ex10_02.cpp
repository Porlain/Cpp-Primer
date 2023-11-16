/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-14 20:30:13
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    vector<string> vec = {"aa", "aaa", "aa", "cc"};
    string val = "aa";
    cout << count(vec.begin(), vec.end(), val) << endl;

    return 0;
}