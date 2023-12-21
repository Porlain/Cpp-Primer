/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-21 13:58:36
 */
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    cout << left
         << setw(20) << "default format: " << 100 * sqrt(2.0) << '\n'
         << setw(20) << "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
         << setw(20) << "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
         << setw(20) << "hexadecimal: " << hexfloat << 100 * sqrt(2.0) << '\n'
         << setw(20) << "use defaults: " << defaultfloat << 100 * sqrt(2.0) << '\n'
         << "\n\n"
         << right;

    return 0;
}
