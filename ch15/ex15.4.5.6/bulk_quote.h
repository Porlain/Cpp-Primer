/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-05 20:09:46
 */
#include "quote.h"
class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double price, std::size_t qty, double discounts) : Quote(book, price), min_qty(qty), discount(discounts) {}
    virtual double net_price(std::size_t) const override;

private:
    double discount;
    std::size_t min_qty;
};