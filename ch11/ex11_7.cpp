/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-16 20:54:52
 */
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::map;
using std::string;
using std::vector;

auto make_families()
{
    map<string, vector<string>> families;
    for (string ln; cout << "Last name:\n", cin >> ln;)
        for (string cn; cout << "|-Children's names:\n", cin >> cn;)
            families[ln].push_back(cn);
    return families;
}

void print(map<string, vector<string>> const &families)
{
    for (auto const &family : families)
    {
        cout << family.first << ":\n";
        for (auto const &child : family.second)
            cout << child << " ";
        cout << "\n";
    }
}

int main()
{
    print(make_families());

    return 0;
}