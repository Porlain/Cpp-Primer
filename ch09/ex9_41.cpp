/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-14 14:57:32
 */
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<char> v{'p', 'o', 'r', 'l', 'a', 'i', 'n'};
    string str(v.begin(), v.end());
    cout << str << endl;
    return 0;
}