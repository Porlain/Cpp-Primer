/*
 * @Author: Porlain szbj2023@163.com
 * @Date: 2023-11-13 20:32:24
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vec;
    cout << vec.at(0);    // terminating with uncaught exception of type out_of_range
    cout << vec[0];       // Segmentation fault: 11
    cout << vec.front();  // Segmentation fault: 11
    cout << *vec.begin(); // Segmentation fault: 11
    return 0;
}