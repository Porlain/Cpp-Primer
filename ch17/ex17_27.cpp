/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-20 14:59:16
 */
#include <iostream>
#include <string>
#include <regex>

using namespace std;

// 111112222
// 11111-2222
// 11111
// 11111-
int main()
{
    string phone = "(\\d{5})([\\.-])?(\\d{4})";
    regex r(phone);
    string format = "$1-$3";
    string str;
    smatch result;

    while (getline(cin, str))
    {
        regex_search(str, result, r);

        if (!result.empty())
            cout << result.format(format) << endl;
        else
            cout << "Sorry, No match." << endl;
    }
    return 0;
}