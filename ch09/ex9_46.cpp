/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-14 15:31:29
 */
#include <string>
#include <iostream>

using namespace std;

string add_pre_and_suffix(string name, const string pre, const string su)
{
    name.insert(0, pre);
    name.insert(name.size(), su);
    return name;
}

int main()
{
    string name("Song");
    cout << add_pre_and_suffix(name, "Mr.", ", Jr.") << endl;
    return 0;
}