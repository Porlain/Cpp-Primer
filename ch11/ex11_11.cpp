/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-17 11:05:34
 */
#include "../ch07/ex7_26.h"
#include <set>

bool compare(Sales_data const &s1, Sales_data const &s2)
{
    return s1.isbn() < s2.isbn();
}

int main()
{   
    // refer to section 6.3 and section 2.5.3
    using com = bool(*)(Sales_data const &, Sales_data const &);
    std::multiset<Sales_data, com> bookStore(compare);

    return 0;
}