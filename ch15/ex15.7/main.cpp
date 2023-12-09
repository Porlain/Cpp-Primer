/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-06 10:30:36
 */
#include "quote.h"
#include "limit_quote.cpp"
#include "bulk_quote.cpp"
#include <iostream>

double print_total(std::ostream &out, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    out << "ISBN:" << item.isbn()
        << "# sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

int main()
{
    // ex15.6
    Quote q("textbook", 10.60);
    Bulk_quote bq("textbook", 10.60, 10, 0.3);
    Limit_quote lq("Bible", 10.60, 10, 0.3);

    print_total(std::cout, q, 5);
    print_total(std::cout, bq, 5);
    print_total(std::cout, lq, 5);

    return 0;
}