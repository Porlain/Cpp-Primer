/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-15 14:11:01
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool predicate(const string &str)
{
    return str.size() >= 5;
}

int main()
{
    vector<string> vec = {"a", "as", "aasss", "aaaaassaa", "aaaaaabba", "aaa"};
    auto point = partition(vec.begin(), vec.end(), predicate);
    for (auto it = vec.cbegin(); it != point; ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}