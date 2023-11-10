/*
 * @Author: Porlain szbj2023@163.com
 * @Date: 2023-11-09 20:45:34
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */

// if you want to use the first method, then
// include "ex7_41_a.h"

#include "ex7_41_b.h"
#include "./ex7_41.cpp"
using std::cout;
using std::endl;
int main()
{
    cout << "1. default way: " << endl;
    cout << "----------------" << endl;
    Sales_data s1;

    cout << "\n2. use std::string as parameter: " << endl;
    cout << "----------------" << endl;
    Sales_data s2("CPP-Primer-5th");

    cout << "\n3. complete parameters: " << endl;
    cout << "----------------" << endl;
    Sales_data s3("CPP-Primer-5th", 3, 25.8);

    cout << "\n4. use istream as parameter: " << endl;
    cout << "----------------" << endl;
    Sales_data s4(std::cin);

    return 0;
}