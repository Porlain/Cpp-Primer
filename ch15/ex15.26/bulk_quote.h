/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-07 11:02:08
 */
#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include "disc_quote.h"
class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote() { std::cout << "default constructing Bulk_quote\n"; };
    Bulk_quote(const std::string &book, double price, std::size_t qty, double discounts) : Disc_quote(book, price, qty, discounts) { std::cout << "Bulk_quote : constructor taking 4 parameters\n"; }

    // copy constructor
    Bulk_quote(const Bulk_quote &rhs) : Disc_quote(rhs) { std::cout << "Bulk_quote : copy constructor\n"; }
    // move constructor
    Bulk_quote(const Bulk_quote &&rhs) : Disc_quote(std::move(rhs)) { std::cout << "Bulk_quote : move constructor\n"; }

    // copy =()
    Bulk_quote &operator=(const Bulk_quote &);
    // move =()
    Bulk_quote &operator=(Bulk_quote &&) noexcept;

    virtual double net_price(std::size_t) const override;
    void debug() const override;
    ~Bulk_quote() { std::cout << "destructing Bulk_quote\n"; }
};
#endif