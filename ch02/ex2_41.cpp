#include <iostream>
#include <string>

using namespace std;

struct Sale_data
{
    std::string bookNo;           // ISBN number
    unsigned int utiles_sold = 0; // number of quantity
    double revenue = 0.0;         // total sales
    double price = 0.0;           // price of one quantity
};

int main()
{

    // ===================================================================================================================
    // excerse of 1.5.1
    // Sale_data book;
    // cin >> book.bookNo >> book.utiles_sold >> book.price;
    // book.revenue = book.utiles_sold * book.price;
    // cout << book.bookNo << " " << book.utiles_sold << " " << book.revenue << endl;

    // ===================================================================================================================
    // exercise of 1.5.2
    // Sale_data book1, book2;
    // cin >> book1.bookNo >> book1.utiles_sold >> book1.price;
    // cin >> book2.bookNo >> book2.utiles_sold >> book2.price;
    // book1.revenue = book1.utiles_sold * book1.price;
    // book2.revenue = book2.utiles_sold * book2.price;

    // if (book1.bookNo == book2.bookNo)
    // {
    //     unsigned int totalRevenue = book1.revenue + book2.revenue;
    //     unsigned int totalUtils = book1.utiles_sold + book2.utiles_sold;
    //     cout << book1.bookNo << " " << totalUtils << " " << totalRevenue << endl;
    //     if (totalUtils != 0)
    //     {
    //         cout << totalRevenue / totalUtils << endl;
    //     }
    //     else
    //         cout << "No sales of book:" << book1.bookNo << endl;
    //     return 0;
    // }
    // else
    // {
    //     cerr << "Data must refer to same ISBN!" << endl;
    //     return -1;
    // }

    // ===================================================================================================================
    // exercise 1.6
    // Very similar to the previous one
    Sale_data total;
    if (std::cin >> total.bookNo >> total.utiles_sold >> total.price)
    {
        total.revenue = total.utiles_sold * total.price;

        Sale_data trans;
        double transPrice;
        while (std::cin >> trans.bookNo >> trans.utiles_sold >> transPrice)
        {
            trans.revenue = trans.utiles_sold * transPrice;

            if (total.bookNo == trans.bookNo)
            {
                total.utiles_sold += trans.utiles_sold;
                total.revenue += trans.revenue;
            }
            else
            {
                std::cout << total.bookNo << " " << total.utiles_sold << " " << total.revenue << " ";
                if (total.utiles_sold != 0)
                    std::cout << total.revenue / total.utiles_sold << std::endl;
                else
                    std::cout << "(no sales)" << std::endl;

                total.bookNo = trans.bookNo;
                total.utiles_sold = trans.utiles_sold;
                total.revenue = trans.revenue;
            }
        }

        std::cout << total.bookNo << " " << total.utiles_sold << " " << total.revenue << " ";
        if (total.utiles_sold != 0)
            std::cout << total.revenue / total.utiles_sold << std::endl;
        else
            std::cout << "(no sales)" << std::endl;

        return 0;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1; // indicate failure
    }
}
