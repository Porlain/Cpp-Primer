/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-07 11:05:08
 */
#ifndef QUOTE_H
#define QUOTE_H
#include <string>
#include <iostream>
class Quote
{
public:
    friend bool operator!=(const Quote &, const Quote &);

public:
    Quote() { std::cout << "default constructing Quote\n"; };
    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) { std::cout << "Quote : constructor taking 2 parameters\n"; }
    // copy constructor
    Quote(const Quote &q) : bookNo(q.bookNo), price(q.price) {std::cout << "Quote: copy constructing\n"; }
    // move constructor
    Quote(Quote &&q) noexcept : bookNo(std::move(q.bookNo)), price(std::move(q.price)) { std::cout << "Quote: move constructing\n"; }

    // copy =
    Quote &operator=(const Quote &);
    // move =
    Quote &operator=(Quote &&) noexcept;

    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual void debug() const;
    virtual ~Quote(){std::cout << "destructing Quote\n";};

private:
    std::string bookNo;

protected:
    double price;
};

#endif