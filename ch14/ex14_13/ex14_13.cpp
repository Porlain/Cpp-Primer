/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-30 17:04:40
 */
#include "ex14_13.h"

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