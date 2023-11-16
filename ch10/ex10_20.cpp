/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-15 15:55:56
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

size_t bigger_count(vector<string> const &v)
{
    return count_if(v.begin(), v.end(), [](string const &s)
                    { return s.size() > 6; });
}

int main()
{
    vector<string> v{"alan", "moophy", "1234567", "1234567", "1234567", "1234567"};

    cout << bigger_count(v) << endl;

    return 0;
}