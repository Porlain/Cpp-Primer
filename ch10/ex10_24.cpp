/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-15 16:38:42
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool check_size(const string &str, size_t sz)
{
    return str.size() <= sz;
}

int main()
{
    string str("123456");
    vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7};
    auto result = find_if(vec.begin(), vec.end(), bind(check_size, str, _1));
    if (result != vec.end())
        cout << *result << endl;
    else
        cout << "Not found" << endl;

    return 0;
}