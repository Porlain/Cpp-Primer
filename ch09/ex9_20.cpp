/*
 * @Author: Porlain szbj2023@163.com
 * @Date: 2023-11-13 19:51:51
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */

#include <iostream>
#include <list>
#include <deque>
using namespace std;
int main()
{
    list<int> list1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    deque<int> odd, even;
    for (auto i : list1)
        (i % 2 == 0) ? (even.push_back(i)) : (odd.push_back(i));

    for (auto i : odd)
        cout << i << " ";
    cout << endl;
    for (auto i : even)
        cout << i << " ";
    cout << endl;
    return 0;
}