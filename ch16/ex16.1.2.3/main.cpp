/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-09 14:58:06
 */
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Sales_data
{
};

template <typename T>
int compare(const T &lhs, const T &rhs)
{
    if (lhs < rhs)
        return -1;
    if (rhs < lhs)
        return 1;
    return 0;
}

int main()
{
    cout << compare(1, 0) << endl;
    vector<int> vec1{1, 2, 3}, vec2{4, 5, 6};
    cout << compare(vec1, vec2) << endl;

    // error: no match for 'operator<' (operand types are 'const Sales_data' and 'const Sales_data')
    // Sales_data s1, s2;
    // cout << compare(s1, s2) << endl;
    return 0;
}