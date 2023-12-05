/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-05 11:28:13
 *
 * @see ex14_22.h
 */
#ifndef CP5_ex14_45_h
#define CP5_ex14_45_h

#include <string>
#include <iostream>

class Sales_data
{
    friend std::istream &operator>>(std::istream &, Sales_data &);       // input
    friend std::ostream &operator<<(std::ostream &, const Sales_data &); // output
    friend Sales_data operator+(const Sales_data &, const Sales_data &); // addition
    friend Sales_data operator-(const Sales_data &, const Sales_data &); // substraction

public:
    Sales_data &operator+=(const Sales_data &); // compound-assignment
    Sales_data &operator-=(const Sales_data &); // compound-substraction
    Sales_data &operator=(const Sales_data &);
    explicit operator std::string() const { return bookNo; }
    explicit operator double() const { return avg_price(); }

public:
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {}
    Sales_data() : Sales_data(" ", 0, 0.0) {}
    Sales_data(const std::string &s) : Sales_data(s, 0, 0.0) {}
    Sales_data(std::istream &is) {}

    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &str);

    inline double avg_price() const;

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

#endif