/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-15 14:06:31
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../ch07/ex7_26.h" // Sales_data class.

using namespace std;

inline bool compareISBN(const Sales_data &s1, const Sales_data &s2)
{
    return s1.isbn().size() < s2.isbn().size();
}

int main()
{
    Sales_data d1("aa"), d2("aaaa"), d3("aaa"), d4("z"), d5("aaaaz");
    vector<Sales_data> vec{d1, d2, d3, d4, d5};

    sort(vec.begin(), vec.end(), compareISBN);

    for (const auto &i : vec)
        cout << i.isbn() << " ";
    cout << endl;

    return 0;
}