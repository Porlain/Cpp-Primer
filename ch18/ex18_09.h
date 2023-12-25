/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-22 16:35:30
 *
 * @see ex16_62.h
 */
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

class Isbn_mismatch : public std::logic_error
{
public:
    explicit Isbn_mismatch(const std::string &s) : std::logic_error(s) {}
    Isbn_mismatch(const std::string &s, const std::string &lhs, const std::string &rhs) : std::logic_error(s), left(lhs), right(rhs) {}
    const std::string left, right;
};

class Sales_data
{
    friend std::hash<Sales_data>;
    friend std::istream &operator>>(std::istream &, Sales_data &);       // input
    friend std::ostream &operator<<(std::ostream &, const Sales_data &); // output
    friend Sales_data operator+(const Sales_data &, const Sales_data &); // addition
    friend Sales_data operator-(const Sales_data &, const Sales_data &); // substraction
    friend bool operator==(const Sales_data &, const Sales_data &);

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

// specialize std::hash
// note : template specialization should be put in the header!
namespace std
{
    template <>
    struct hash<Sales_data>
    {
        typedef size_t result_type;
        typedef Sales_data argument_type;
        size_t operator()(const Sales_data &s) const
        {
            return hash<string>()(s.bookNo) ^
                   hash<unsigned>()(s.units_sold) ^
                   hash<double>()(s.revenue);
        }
    };
}

#endif