/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-05 20:11:42
 */
#include "bulk_quote.h"

double Bulk_quote::net_price(std::size_t n) const
{
    if (n >= min_qty)
        return n * (1 - discount) * price;
    return n * price;
}
