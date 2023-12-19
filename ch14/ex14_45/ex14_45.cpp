/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-19 14:15:21
 */
#include "ex14_45.h"

std::istream &operator>>(std::istream &in, Sales_data &item)
{
    double price = 0.0;
    in >> item.bookNo >> item.units_sold >> price;
    if (in)
        item.revenue = price * item.units_sold;
    else
        item = Sales_data();
    return in;
}

std::ostream &operator<<(std::ostream &out, const Sales_data &item)
{
    out << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return out;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum -= rhs;
    return sum;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data &Sales_data::operator-=(const Sales_data &rhs)
{
    units_sold -= rhs.units_sold;
    revenue -= rhs.revenue;
    return *this;
}

//
// here
//
Sales_data &Sales_data::operator=(const Sales_data &rhs)
{
    this->bookNo = rhs.bookNo;
    this->revenue = rhs.revenue;
    this->units_sold = rhs.units_sold;
    return *this;
}

// for ex17_04
Sales_data &Sales_data::operator=(const std::string &rhs)
{
    *this = Sales_data(rhs);
    return *this;
}

Sales_data &Sales_data::combine(const Sales_data &str)
{
    units_sold += str.units_sold;
    revenue += str.revenue;
    // return an object which call this function
    return *this;
}

inline double Sales_data::avg_price() const
{
    return units_sold ? revenue / units_sold : 0;
}

// for ex17_04
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}