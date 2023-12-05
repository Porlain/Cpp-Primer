/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-01 15:21:10
 */
#include "ex14_05.cpp"

int main()
{
    Book book1(123, "CP5", "Porlain", "2012");
    Book book2(123, "CP5", "Porlain", "2012");

    if (book1 == book2)
        std::cout << book1 << std::endl;
}
