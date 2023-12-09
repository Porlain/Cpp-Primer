/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-05 20:20:46
 */
#ifndef LIMIT_QUOTE_H
#define LIMIT_QUOTE_H
#include "quote.h"
class Limit_quote : public Quote
{
public:
    Limit_quote() = default;
    Limit_quote(const std::string &book, double price, std::size_t qty, double discounts) : Quote(book, price), max_qty(qty), discount(discounts) {}
    virtual double net_price(std::size_t) const override;

private:
    double discount;
    std::size_t max_qty;
};
#endif