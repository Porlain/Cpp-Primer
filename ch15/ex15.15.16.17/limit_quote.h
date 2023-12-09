/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-06 14:02:11
 */
#ifndef LIMIT_QUOTE_H
#define LIMIT_QUOTE_H
#include "disc_quote.h"
class Limit_quote : public Disc_quote
{
public:
    Limit_quote() = default;
    Limit_quote(const std::string &book, double price, std::size_t qty, double discounts) :Disc_quote(book, price, qty, discounts){}
    virtual double net_price(std::size_t) const override;
    virtual void debug() const override;
    
};
#endif