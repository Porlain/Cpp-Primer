/*
 * @Author: Porlain szbj2023@163.com
 * @Date: 2023-11-13 19:44:49
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */
#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main()
{
    deque<string> input;
    for (string str; cin >> str; input.push_back(str))
        ;
    for (auto iter = input.begin(); iter != input.end(); ++iter)
        cout << *iter << endl;
    return 0;
}