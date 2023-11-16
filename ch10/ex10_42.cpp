/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-16 15:31:31
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

void elimDups(list<string> &list)
{
    list.sort();
    list.unique();
}

int main()
{
    list<string> list = {"aa", "aa", "aa", "aa", "aasss", "aa"};
    elimDups(list);
    for_each(list.cbegin(), list.cend(), [](const string &i)
             { cout << i << " "; });
    cout << endl;

    return 0;
}