/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-14 13:48:45
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