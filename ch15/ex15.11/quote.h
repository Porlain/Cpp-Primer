/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-06 10:26:11
 */
#ifndef QUOTE_H
#define QUOTE_H
#include <string>
class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual void debug() const;
    virtual ~Quote() = default;

private:
    std::string bookNo;

protected:
    double price;
};

#endif