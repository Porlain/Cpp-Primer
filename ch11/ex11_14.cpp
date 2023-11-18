/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-17 14:37:34
 */
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::map;
using std::pair;
using std::string;
using std::vector;

auto make_families()
{   
    // we also can use this to declare
    // using Child = pair<string, string>;
    // using Children = vector<Child>;
    // using Data = map<string, Children>;
    map<string, vector<pair<string, string>>> families;
    for (string ln; cout << "Last name:\n", cin >> ln;)
        for (string cn, data; cout << "|-Children's names and birthday:\n", cin >> cn >> data;)
            families[ln].emplace_back(cn, data);
    return families;
}

void print(map<string, vector<pair<string, string>>> const &families)
{
    for (auto const &family : families)
    {
        cout << family.first << ":\n";
        for (auto const &child : family.second)
            cout << child.first << " " << child.second << " ";
        cout << "\n";
    }
}

int main()
{
    auto families = make_families();
    print(families);
    return 0;
}