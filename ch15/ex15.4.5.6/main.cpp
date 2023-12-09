/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-05 20:13:14
 */
#include "quote.h"
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
    Quote q("textbook", 10.60);
    Bulk_quote bq("textbook", 10.60, 10, 0.3);

    print_total(std::cout, q, 12);
    print_total(std::cout, bq, 12);
    return 0;
}