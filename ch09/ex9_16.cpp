/*
 * @Author: Porlain szbj2023@163.com
 * @Date: 2023-11-13 17:11:35
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */

#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    list<int> li{1, 2, 3, 4, 5};
    vector<int> vec2{1, 2, 3, 4, 5};
    vector<int> vec3{1, 2, 3, 4};

    cout << (vector<int>(li.begin(), li.end()) == vec2 ? "true" : "false") << endl;
    cout << (vector<int>(li.begin(), li.end()) == vec3 ? "true" : "false") << endl;

    return 0;
}