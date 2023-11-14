/*
 * @Author: Porlain szbj2023@163.com
 * @Date: 2023-11-13 19:49:42
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */
#include <iostream>
#include <list>
#include <string>
using namespace std;
int main()
{
    list<string> input;
    for (string str; cin >> str; input.push_back(str))
        ;
    // actually, you'd better use cbegin and cend rather than begin and end
    for (auto iter = input.begin(); iter != input.end(); ++iter)
        cout << *iter << endl;
    return 0;
}