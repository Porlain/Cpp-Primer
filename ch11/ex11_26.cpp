/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-17 15:35:21
 */
#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::map;
using std::string;

int main()
{
    map<int, string> m = {{1, "ss"}, {2, "sz"}};
    map<int, string>::key_type key = 1;
    map<int, string>::mapped_type key_m;
    key_m = m[key];
    cout << key_m << " " << key << " " << m[key] << endl;

    return 0;
}