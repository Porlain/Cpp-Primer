/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-17 15:09:03
 */
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::multimap;
using std::string;
using std::vector;

auto make_families()
{
    multimap<string, vector<string>> families;
    vector<string> vs;
    for (string fn, ln; cin >> ln >> fn;)
    {
        vs.push_back(fn);
        families.insert({ln, vs});
    }

    return families;
}

void print(multimap<string, vector<string>> const &families)
{
    for (const auto f : families)
    {
        cout << "first name is : " << f.first << " ";
        for (const auto s : f.second)
            cout << "last name is : " << s << " ";
        cout << endl;
    }
}

int main()
{
    auto families = make_families();
    print(families);
    return 0;
}