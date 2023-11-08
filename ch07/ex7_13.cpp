#include "ex7_12.h"

int main()
{
    // use this to init
    // Sales_data(std::istream &is)
    // {
    //     read(is, *this);
    // }
    Sales_data total(std::cin);
    if (!total.isbn().empty())
    {
        std::istream &is = std::cin;
        // while the istream isn't empty
        while (is)
        {
            // this is same to Sales_data trans(std::cin);
            Sales_data trans(is);
            if (!is)
                break;
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
        print(std::cout, total) << std::endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}