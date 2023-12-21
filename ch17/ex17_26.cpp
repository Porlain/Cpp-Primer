/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-20 14:49:06
 */
#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool valid(const smatch &m)
{
    // if there is an open parenthesis before the area code
    if (m[1].matched)
        // the area code must be followed by a close parenthesis
        // and followed immediately by the rest of the number or a space
        return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
    else
        // then there can't be a close after the area code
        // the delimiters between the other two components must match
        return !m[3].matched && m[4].str() == m[6].str();
}

// tx 908.555.1500 (908)5551500
int main()
{
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
    regex r(phone);
    smatch m;
    string str;
    while (getline(cin, str))
    {
        vector<string> vec;
        for (sregex_iterator it(str.begin(), str.end(), r), end_it; it != end_it; ++it)
            if (valid(*it))
                vec.push_back(it->str());
        if (vec.size() == 0)
            cout << "no matched number" << endl;
        else if (vec.size() == 1)
            cout << vec[0] << endl;
        else
            for (int i = 1; i < vec.size(); ++i)
                std::cout << vec[i] << " ";
    }

    return 0;
}