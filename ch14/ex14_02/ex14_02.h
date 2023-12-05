/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-30 16:31:08
 *
 * @see ex7_26.h
 */
//  @Add 1. use delegating constructors
//       2. add a statement to the body of each of the constructors that prints a message whether it is executed.
// NOTE: Whether the function is a member function
#ifndef CP5_CH14_EX14_02_H
#define CP5_CH14_EX14_02_H

#include <string>
#include <iostream>

class Sales_data
{
    friend std::istream &operator>>(std::istream &, Sales_data &);       // input
    friend std::ostream &operator<<(std::ostream &, const Sales_data &); // output
    friend Sales_data operator+(const Sales_data &, const Sales_data &); // addition

public:
    Sales_data &operator+=(const Sales_data &); // compound-assignment

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