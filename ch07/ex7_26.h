/*
 * @Author: Porlain szbj2023@163.com
 * @Date: 2023-11-08 15:29:48
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */

#ifndef CP5_ex7_26_h
#define CP5_ex7_26_h

#include <string>
#include <iostream>
using std::string;

class Sales_data
{
    friend std::istream &read(std::istream &is, Sales_data &item);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

public:
    Sales_data() = default;
    Sales_data(const string &s) : bookNo(s) {}
    Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {}
    Sales_data(std::istream &is)
    {
        read(is, *this);
    }

    string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &str);

    inline double avg_price() const;

private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data &Sales_data::combine(const Sales_data &str)
{
    units_sold += str.units_sold;
    revenue += str.revenue;
    // return an object which call this function
    return *this;
}

std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data temp = lhs;
    return temp.combine(rhs);
}

inline double Sales_data::avg_price() const
{
    return units_sold ? revenue / units_sold : 0;
}

#endif