#ifndef CH02_EX2_42_H
#define CH02_EX2_42_H
#include "iostream"
#include "string"

struct Sales_data
{
    std::string bookNo;
    unsigned int units_sold = 0;
    double price = 0.0;
    double revenue = 0.0;

    void CalRevenue();
    void SetData(Sales_data data);
    void AddData(Sales_data data);
    double CalAverage();
    void Print();
};

void Sales_data::CalRevenue()
{
    revenue = units_sold * price;
}

void Sales_data::SetData(Sales_data data)
{
    bookNo = data.bookNo;
    units_sold = data.units_sold;
    price = data.price;
    revenue = data.revenue;
}

void Sales_data::AddData(Sales_data data)
{
    if (bookNo != data.bookNo)
    {
        return;
    }
    units_sold += data.units_sold;
    revenue += data.revenue;
}

double Sales_data::CalAverage()
{
    if (units_sold != 0)
        return revenue / units_sold;
    else
        return 0.0;
}

void Sales_data::Print()
{
    std::cout << "Book's ISBN is:" << bookNo << std::endl
              << "Book's number of quantity is:" << units_sold << std::endl
              << "Book's revenue is:" << revenue << std::endl;
    double averagePrice = CalAverage();
    if (averagePrice != 0.0)
        std::cout << "Book's average price is:" << averagePrice << std::endl;
    else
        std::cout << "(no sales)" << std::endl;
}

#endif