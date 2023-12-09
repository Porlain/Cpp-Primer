/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-07 15:40:56
 */
#ifndef BASKET_H
#define BASKET_H
#include <set>
#include "quote.h"
#include <memory>

class Basket
{
public:
    void add_item(const Quote &sale) { items.insert(std::shared_ptr<Quote>(sale.clone())); }
    void add_item(Quote &&sale) { items.insert(std::shared_ptr<Quote>(std::move(sale).clone())); }

    double total_receipt(std::ostream &) const;

private:
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) { return lhs->isbn() < rhs->isbn(); }
    std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};
};

#endif