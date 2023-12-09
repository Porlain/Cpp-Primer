#include "quote.h"
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

    return 0;
}