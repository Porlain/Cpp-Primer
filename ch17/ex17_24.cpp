/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-20 14:28:27
 */
#include <iostream>
#include <string>
#include <regex>

using namespace std;

// 908.555.1500
// (908)5551500
// (908.555.1500
int main()
{
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
    regex r(phone);
    string format = "$2.$5.$7";
    string str;
    while (getline(cin, str))
    {
        cout << regex_replace(str, r, format) << endl;
    }
    return 0;
}