/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-16 11:23:19
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    istream_iterator<int> in(cin), eof;
    vector<int> vec;

    copy(in, eof, inserter(vec, vec.begin()));

    // equal to
    // vector<int> vec(istream_iterator<int>(std::cin), istream_iterator<int>());

    sort(vec.begin(), vec.end());
    copy(vec.cbegin(), vec.cend(), ostream_iterator<int>(cout, " "));

    return 0;
}