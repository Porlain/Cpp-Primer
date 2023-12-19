/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-19 14:21:14
 */
#include "..\ch14\ex14_45\ex14_45.cpp"
#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>

struct matches_struct
{
    std::vector<Sales_data>::size_type st;
    std::vector<Sales_data>::const_iterator first;
    std::vector<Sales_data>::const_iterator last;
    matches_struct(std::vector<Sales_data>::size_type s,
                   std::vector<Sales_data>::const_iterator f,
                   std::vector<Sales_data>::const_iterator l) : st(s), first(f), last(l) {}
};

std::vector<matches_struct>
findBook(const std::vector<std::vector<Sales_data>> &files, const std::string &book)
{
    std::vector<matches_struct> ret;
    for (auto it = files.cbegin(); it != files.cend(); ++it)
    {
        auto found = std::equal_range(it->cbegin(), it->cend(), book, compareIsbn);
        if (found.first != found.second)
            ret.push_back(matches_struct(it - files.cbegin(), found.first, found.second));
    }
    return ret;
}

void reportResults(std::istream &in, std::ostream &os, const std::vector<std::vector<Sales_data>> &files)
{
    std::string book;
    while (in >> book)
    {
        auto trans = findBook(files, book);
        if (trans.empty())
        {
            std::cout << book << "not found in any stores" << std::endl;
            continue;
        }
        for (const auto &store : trans)
        {
            os << "store " << store.st << " sales: "
               << std::accumulate(store.first, store.last,
                                  Sales_data(book))
               << std::endl;
        }
    }
}

int main()
{
    Sales_data sales_data1("001-01", 1, 100);
    Sales_data sales_data2("001-01", 2, 100);
    Sales_data sales_data3("001-02", 2, 80);

    std::vector<Sales_data> vs1 = {sales_data1, sales_data3};
    std::vector<Sales_data> vs2 = {sales_data2};
    std::vector<std::vector<Sales_data>> vvs = {vs1, vs2};

    reportResults(std::cin, std::cout, vvs);
    return 0;
}
