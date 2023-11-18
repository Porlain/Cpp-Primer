/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-17 16:59:03
 */
#include <iostream>
#include <map>
#include <set>
#include <string>

using std::cout;
using std::endl;
using std::map;
using std::multimap;
using std::set;
using std::string;

int main()
{
    multimap<string, string> authors = {
        {"author", "C++ Primer"},
        {"Porlain", "exercise result"},
        {"will_delete", "aaa"},
        {"will_delete", "aaa"},
        {"will_delete", "bbb"}};
    // If you directly output a maltimap, there will be n authors,
    // rather than the form where one author corresponds to multiple works
    // map and set sorts keys by default
    // actually, you alse can use multiset here
    map<string, set<string>> orders;

    for (const auto &author : authors)
        orders[author.first].insert(author.second);

    for (const auto &author : orders)
    {
        cout << author.first << ": ";
        for (const auto &work : author.second)
            cout << work << " ";
        cout << endl;
    }
    return 0;
}