/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-16 11:21:24
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    istream_iterator<int> in_iter(cin), eof;
    vector<int> vec;
    while (in_iter != eof)
        vec.push_back(*in_iter++);

    sort(vec.begin(), vec.end());
    unique_copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));

    return 0;
}