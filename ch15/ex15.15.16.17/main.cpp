/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-06 13:59:55
 */
#include "quote.cpp"
#include "bulk_quote.cpp"
#include <iostream>

int main()
{
    //$ g++ -o ex17 ex17.cpp -std=c++11
    // ex17.cpp: In function ‘int main()’:
    // ex17.cpp:17:13: error: cannot declare variable ‘dq’ to be of abstract type ‘Disc_quote’
    //   Disc_quote dq("A1-001", 80, 5, 0.2);
    //              ^
    // In file included from Limit_quote_ex16.h:4:0,
    //                  from ex17.cpp:2:
    // Disc_quote_ex15.h:7:7: note:   because the following virtual functions are pure within ‘Disc_quote’:
    //  class Disc_quote : public Quote
    //        ^
    // Disc_quote_ex15.h:13:9: note: 	virtual double Disc_quote::net_price(std::size_t) const
    //   double net_price(std::size_t) const = 0;

    Disc_quote d;

    return 0;
}