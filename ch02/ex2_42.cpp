#include <iostream>
#include "ex2_42.h"

int main()
{
    // ===================================================================================================================
    // excerse of 1.5.1
    // Sales_data book;
    // std::cin>>book.bookNo>>book.units_sold>>book.price;
    // book.CalRevenue();
    // book.Print();

    // ===================================================================================================================
    // excerse of 1.5.2
    // Sales_data book1, book2;
    // std::cin >> book1.bookNo >> book1.units_sold >> book1.price;
    // std::cin >> book2.bookNo >> book2.units_sold >> book2.price;
    // book1.CalRevenue();
    // book2.CalRevenue();
    
    // if (book1.bookNo == book2.bookNo)
    // {
    //     book1.AddData(book2);
    //     book1.Print();
    //     return 0;
    // }
    // else
    // {
    //     std::cerr << "Data must refer to same ISBN!" << std::endl;
    //     return -1;
    // }

    // ===================================================================================================================
    // exercise 1.6
    // Very similar to the previous one
    // if you want to stop the program, then you should use CTRL+Z
    Sales_data total;
    if (std::cin >> total.bookNo >> total.units_sold >> total.price)
    {
        total.CalRevenue();
        Sales_data trans;
        double transPrice;
        while (std::cin >> trans.bookNo >> trans.units_sold >> trans.price)
        {
            trans.CalRevenue();
            if (total.bookNo == trans.bookNo)
            {
                total.AddData(trans);
            }
            else
            {
                total.Print();
                total.SetData(trans);
            }
        }
        total.Print();
        return 0;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;  // indicate failure
    }
}
