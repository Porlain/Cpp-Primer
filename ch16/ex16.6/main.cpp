/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-09 15:19:59
 */
#include <iostream>
#include <string>
using namespace std;

// We usually don't use a function name which is the same as the function of standard libary
template <typename T, unsigned N>
T *begin_(T (&arr)[N])
{
    return arr;
}

template <typename T, unsigned N>
T *end_(T (&arr)[N])
{
    return arr + N;
}

int main()
{
    string s[] = {"sssss", "ss", "ss", "ssssszzzz"};
    cout << *(begin_(s)) << endl;
    cout << *(end_(s) - 1) << endl;
    return 0;
}