/*
 * @Author: Porlain szbj2023@163.com
 * @Date: 2023-11-11 14:46:29
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */

#include <iostream>
#include <fstream>
#include <string>
#include "../ch07/ex7_26.h"

using namespace std;

int main()
{
    string filename = "../data/book.txt";
    ifstream in(filename);
    Sales_data total;

    if (read(in, total))
    {
        Sales_data trans;
        while (read(in, trans))
        {
            if (trans.isbn() == total.isbn())
            {
                total.combine(trans);
            }
            else
            {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }

    return 0;
}