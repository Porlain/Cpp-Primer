/*
 * @Author: Porlain szbj2023@163.com
 * @Date: 2023-11-09 20:45:32
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#include "./ex7_41_b.h"

Sales_data::Sales_data(std::istream &is){
    std::cout << "Sales_data(istream &is)" << std::endl;
    read(is, *this);
}

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