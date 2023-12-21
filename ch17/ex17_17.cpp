/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-19 17:25:24
 */
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <regex>
using std::regex;
using std::sregex_iterator;

int main()
{
    std::string pattern("[[:alpha:]]*[^c]ei[[:alpha:]]*");
    std::regex r(pattern, std::regex::icase);
    std::smatch results;
    std::string s("freind receipt theif receive");
    for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it)
        cout << it->str() << endl;
}