/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-06 10:28:52
 */
#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include "quote.h"
class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double price, std::size_t qty, double discounts) : Quote(book, price), min_qty(qty), discount(discounts) {}
    virtual double net_price(std::size_t) const override;
    virtual void debug() const override;

private:
    double discount;
    std::size_t min_qty;
};
#endif