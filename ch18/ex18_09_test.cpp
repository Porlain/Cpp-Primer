/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-22 16:38:37
 */
#include "ex18_09.cpp"

int main()
{
    Sales_data sales_data1("001-01", 1, 100);
    Sales_data sales_data2("001-01", 2, 100);
    Sales_data sales_data3("001-02", 2, 80);

    try
    {
        auto sum = sales_data1 + sales_data3;
        std::cout << sum;
    }
    catch (const Isbn_mismatch &e)
    {
        std::cerr << e.what() << ": left isbn(" << e.left << ") right isbn(" << e.right << ")" << std::endl;
    }
    return 0;
}