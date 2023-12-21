/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-20 14:34:02
 */
#include <iostream>
#include <string>
#include <regex>

using namespace std;

//tx 908.555.1500 (908)5551500
int main()
{
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
    regex r(phone);
    string format = "$2.$5.$7";
    string str;
    smatch result;
    while (getline(cin, str))
    {
        regex_search(str, result, r);
        if (!result.empty())
            cout << result.prefix() << result.format(format) << endl;
        else
            cout << "Sorry, No match." << endl;
    }
    return 0;
}