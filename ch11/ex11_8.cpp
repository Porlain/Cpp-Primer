/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-17 10:21:01
 */
//  http://stackoverflow.com/questions/8686725/what-is-the-difference-between-stdset-and-stdvector
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> vec;
    string str;
    // cin >> str;
    // vec.push_back(str);
    while (cin >> str)
        if (find(vec.begin(), vec.end(), str) == vec.end())
            vec.push_back(str);

    for (auto const &iter : vec)
        cout << iter << " ";
    cout << endl;

    return 0;
}