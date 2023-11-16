/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-15 16:32:28
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool isLesserOrEqual(const string &str, size_t sz)
{
    return str.size() <= sz;
}

int main()
{
    vector<string> v{"alan", "moophy", "1234567", "1234567", "1234567", "1234567"};

    cout << count_if(v.begin(), v.end(), bind(isLesserOrEqual, _1, 6)) << endl;

    return 0;
}