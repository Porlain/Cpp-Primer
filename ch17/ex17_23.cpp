/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-20 14:19:36
 */
#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool valid(const smatch &m)
{
    if (m[3].matched)
        return true;
    else
        return !m[2].matched;
}

// 111112222
// 11111-2222
// 11111
// 11111-
int main()
{
    string mail = "(\\d{5})([-])?(\\d{4})?";
    regex r(mail);
    smatch m;
    string str;
    while (getline(cin, str))
    {
        for (sregex_iterator it(str.begin(), str.end(), r), end_it; it != end_it; ++it)
        {
            if (valid(*it))
                cout << "valid: " << it->str() << endl;
            else
                cout << "not valid: " << it->str() << endl;
        }
    }
    return 0;
}