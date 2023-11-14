/*
 * @Author: Porlain szbj2023@163.com
 * @Date: 2023-11-13 17:02:10
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */
#include <vector>
#include <list>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    list<const char *> list1 = {"Porlain", "Mooophy", "pezy", "Queeuqueg"};
    vector<string> word;
    word.assign(list1.begin(), list1.end());
    for (auto str : word)
        std::cout << str << std::endl;

    return 0;
}