/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-14 13:48:55
 */



// if you want to pass parameters to main function, please execute ex8_08.exe

#include <iostream>
#include <fstream>
#include <string>
#include "../ch07/ex7_26.h"

using namespace std;

int main(int argc, char **argv)
{
    ifstream in(argv[1]);
    // only here
    ofstream output(argv[2], ofstream::app);
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
                print(output,total)<<endl;
                total = trans;
            }
        }
        print(output,total)<<endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }

    return 0;
}