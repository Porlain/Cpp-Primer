/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-09 15:22:30
 */
#include <iostream>
#include <string>
using namespace std;

template <typename T, unsigned N>
constexpr unsigned getSize(const T (&arr)[N])
{
    return N;
}

int main()
{
    string s[] = { "sss" };
    cout << getSize(s) << endl;

    char c[] = "s";
    cout << getSize(c) << endl;
    // the output is 2, as '\0' is added at the end of the array
    return 0;
}
