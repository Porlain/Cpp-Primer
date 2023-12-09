/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-06 13:57:38
 */
#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include "disc_quote.h"
class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double price, std::size_t qty, double discounts) : Disc_quote(book, price, qty, discounts) {}
    virtual double net_price(std::size_t) const override;
    void debug() const override;
};
#endif