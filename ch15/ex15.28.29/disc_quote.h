/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-07 11:02:01
 */
#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H
#include "quote.h"

class Disc_quote : public Quote
{
public:
    friend bool operator!=(const Disc_quote &, const Disc_quote &);

public:
    Disc_quote() { std::cout << "default constructing Disc_quote\n"; };
    Disc_quote(const std::string &book, double price, std::size_t qty, double discounts) : Quote(book, price), quantity(qty), discount(discounts) { std::cout << "Disc_quote : constructor taking 4 parameters.\n"; }

    // copy constructor
    Disc_quote(const Disc_quote &rhs) : Quote(rhs), quantity(rhs.quantity), discount(rhs.discount) { std::cout << "Disc_quote : copy constructor.\n"; }

    // move constructor
    Disc_quote(const Disc_quote &&rhs) noexcept : Quote(std::move(rhs)), quantity(std::move(rhs.quantity)), discount(std::move(rhs.discount)) { std::cout << "Disc_quote : move constructor.\n"; }

    // copy =()
    Disc_quote &operator=(const Disc_quote &);
    // move =()
    Disc_quote &operator=(Disc_quote &&) noexcept;

    virtual double net_price(std::size_t) const override = 0;

    ~Disc_quote() { std::cout << "destructing Dis_quote\n"; }

protected:
    double discount;
    std::size_t quantity;
};
#endif