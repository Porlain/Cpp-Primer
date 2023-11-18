/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-16 16:37:48
 */
#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    map<string, size_t> word_count;
    string word;
    while (cin >> word)
        ++word_count[word];

    for (auto const &w : word_count)
        cout << w.first << " occurs: " << w.second << ((w.second > 1) ? " times" : " time") << endl;

    return 0;
}