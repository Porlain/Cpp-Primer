/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-14 13:47:19
 */


// We can certainly use the previous file to define Sales_data class
// But this header file looks a bit ugly
// so, we can use ex7_41_b.h + ex7_41.cpp to define class 

#ifndef CP5_ex7_41_h
#define CP5_ex7_41_h

#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Sales_data
{
    friend std::istream &read(std::istream &is, Sales_data &item);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

public:
    Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n)
    {
        // add some prompt information
        cout << "Sales_data(const std::string&, unsigned, double)" << endl;
    }

    Sales_data() : Sales_data(" ", 0, 0.0) {}

    Sales_data(const string &s) : Sales_data(s, 0, 0.0)
    {
        // add some prompt information
        // tips:0.0 is double, you also can use 0 instead of 0.0, implicitly convert int to double during initialization
        cout << "Sales_data(const std::string&)" << endl;
    }
    Sales_data(std::istream &is) : Sales_data()
    {
        cout << "Sales_data(istream &is)" << endl;
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