/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-07 11:03:32
 */
#include <iostream>
#include <string>

#include "quote.cpp"
#include "bulk_quote.cpp"
#include "disc_quote.cpp"


int main()
{
    // Bulk_quote bq1;
    Bulk_quote bq2("ss", 2.05, 12, 0.3);
    bq2 = std::move(bq2);


    return 0;
}