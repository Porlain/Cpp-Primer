/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-07 15:46:21
 */
#include "basket.h"

double Basket::total_receipt(std::ostream &out) const
{
    double sum = 0;
    for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
        sum += print_total(out, **iter, items.count(*iter));
    out << "Total Sale: " << sum << std::endl;
    return sum;
}