/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-06 14:03:23
 */
#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H
#include "quote.h"

class Disc_quote : public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double price, std::size_t qty, double discounts) : Quote(book, price), quantity(qty), discount(discounts) {}
    virtual double net_price(std::size_t) const override = 0;

protected:
    double discount;
    std::size_t quantity;
};
#endif