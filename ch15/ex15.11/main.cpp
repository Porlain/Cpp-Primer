/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-06 10:33:56
 */
#include "quote.cpp"
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

void print_debug(const Quote &q)
{
    return q.debug();
}

int main()
{
    Quote q("textbook", 10.60);
    Bulk_quote bq("textbook", 10.60, 10, 0.3);
    Limit_quote lq("Bible", 10.60, 10, 0.3);

    /** @note   Not dynamic binding!
     *  The codes below are not dynamic binding. The compiler has known what the
     *  r refering to at compile time. As a result, the virtual function debug of
     *  the subobject is called.
     */
    Quote& r = q;
    r.debug();
	std::cout << "\n";
    r = bq;
    r.debug();
	std::cout << "\n";
    r = lq;
    r.debug();
	std::cout << "\n";


    std::cout << "====================\n";

    /** @note   dynamic binding!
     *  The below will happen dynamic binding. The reason might be that while  print_debug
     *  compiling the compiler compile it independly from the rest codes. The compiler has
     *  no idea what the paramter q refering to. Thus compiler will leave the decision to
     *  run time. That is, dynamic binding.
     *
     *  Once dynamic binding happens, the corresponding vertual function in derived class will
     *  be called rather than that of the subobject inside the derived object.
     *
     *  Anyway, the reference is essentially an address being passed.
     *
     */
    print_debug(q);
	std::cout << "\n";
    print_debug(lq);
	std::cout << "\n";
    print_debug(bq);
	std::cout << "\n";

    return 0;
}