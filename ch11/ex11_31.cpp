/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-17 16:44:32
 */
#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::multimap;
using std::string;

int main()
{
    multimap<string, string> authors = {
        {"author", "C++ Primer"},
        {"Porlain", "exercise result"},
        {"will_delete", "aaa"},
        {"will_delete", "aaa"}};

    string it = "will_delete";
    auto count = authors.count(it);

    while (count--)
        authors.erase(authors.find(it));

    for (auto const &author : authors)
        cout << author.first << " " << author.second << endl;

    return 0;
}